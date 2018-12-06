#include <iostream>
#include <string.h>
using namespace std;
struct Node{
    int no_punggung;
    char nama[100],posisi[20];
    Node *next;
};
Node *top;

class Stack{
public:
    void push(int no_punggung, char nama[], char posisi[]);
    void pop();
    void displayStack();
};

void Stack::push(int no, char nama[], char posisi[]) {
    struct Node *newNoode = new Node;
    newNoode->no_punggung=no;
    strcpy(newNoode->nama,nama);
    strcpy(newNoode->posisi,posisi);
    newNoode->next=top;
    top=newNoode;
}

void Stack::pop() {
    if(top==NULL){
        cout<<"Stack Kosong"<<endl;
        return;;
    }
    cout<<top->nama<<"Telah Dihapus"<<endl;
    top=top->next;
}

void Stack::displayStack() {
    if(top==NULL){
        cout<<"Stack Kosong"<<endl;
        return;
    }
    struct Node *temp=top;
    while (temp!=NULL){
        cout<<temp->no_punggung<<"->";
        cout<<temp->nama<<"->";
        cout<<temp->posisi<<endl;
        temp=temp->next;
    }
}

int main() {
    Stack stack;
    int in;
    while (true){
        cout <<"-----------------" <<endl;
        cout <<"Linked List Stack" <<endl;
        cout <<"-----------------" <<endl;
        cout <<"1. Push" <<endl;
        cout <<"2. Pop" <<endl;
        cout <<"3. Display Stack" <<endl;
        cout <<"4. Exit" <<endl;
        cout <<"Masukkan Pilihan : ";cin>>in;
        switch (in){
            case 1: {
                Node node;
                cout << "Data Pemain sepak bola" << endl;
                cout << "----------------------" << endl;
                cout << "Masukkan Nomor Punggung : ";
                cin>>node.no_punggung;
                cout << "Masukkan Nama Pemain    : ";
                cin.ignore(1);
                cin.getline(node.nama,100);
                cout << "Masukkan Posisi Pemain  : ";
                cin.getline(node.posisi,20);
                stack.push(node.no_punggung, node.nama, node.posisi);
                break;
            }
            case 2:
                stack.pop();
                break;
            case 3:
                stack.displayStack();
                break;
            case 4:
                exit(0);
            default:
                cout<<"Out of Range";
        }
    }
}
