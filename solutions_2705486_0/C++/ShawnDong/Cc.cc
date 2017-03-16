#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;
const int CHAR = 26;
const int TOTLEN = 5e5 + 9;
const int MAXLEN = 1e6 + 9;
struct Node{
    Node *fail , *next[CHAR];
    int val;
    void init(){
        fail = NULL;
        val = 0;
        memset(next , 0 , sizeof(next));
    }
};
class ACM{
public:
    void init();
    void insert(char * str);
    void build();
    int find(char * str);
private:
    Node * newnode();
    Node acm[TOTLEN];
    Node * root;
    int size;
};
Node * ACM::newnode(){
    acm[size].init();
    return &acm[size++];
}
void ACM::init(){
    size = 0;
    root = newnode();
}
void ACM::insert(char * str){
    Node * p = root;
    for ( ; *str ; ++str){
        int ch = *str - 'a';
        if (p -> next[ch] == NULL)
            p -> next[ch] = newnode();
        p = p -> next[ch];
    }
    p -> val ++;
}
void ACM::build(){
    static queue<Node *> q;
    q.push(root);
    while(!q.empty()){
        Node * tmp = q.front() ; q.pop();
        Node * p;
        for (int i = 0 ; i < CHAR ; ++i){
            Node *& now = tmp -> next[i];
            if (now != NULL){
                q.push(now);
                if (tmp == root){
                    now -> fail = root;
                    continue;
                }
                p = tmp -> fail;
                while(p != NULL){
                    if (p -> next[i] != NULL){
                        now -> fail = p -> next[i];
                        break;
                    }
                    p = p -> fail;
                }
                if (p == NULL) now -> fail = root;
            }
            else{
                if (tmp == root) now = root;
                else now = tmp -> fail -> next[i];
            }
        }
    }
}
int ACM::find(char * str){
    Node *p = root;
    int ans = 0;
    for ( ; *str ; ++str){
        int ch = *str - 'a';
        p = p -> next[ch];
        if (p == NULL)  p = root;
        Node * tmp = p;
        while(tmp != root && tmp ->val != -1){
            ans += tmp -> val;
            tmp -> val = -1;
            tmp = tmp -> fail;
        }
    }
    return ans;
}
ACM ac;
int main(){
}
