#include<iostream>
using namespace std;

string C,J;
int len;
int ansd;
string ansc, ansj;

int diff(string A, string B) {
    int a=0, b=0; 
    for(auto x:A)
        a = a*10 +x-'A';
    for(auto x:B)
        b = b*10 +x-'A';
    return a>b?a-b:b-a;
}

void gao(string &cur, int deg) {
    if(deg==len*2) {
        string A=cur.substr(0, len);
        string B=cur.substr(len);
        int d = diff(A, B);
        if(d<ansd||(d==ansd&&A<ansc) ||(d==ansd&&A==ansc&&B<ansj)) {
            ansd = d;
            ansc = A;
            ansj = B;
        }
        return;
    }
    if(deg<len) {
        if(C[deg]=='?') {
            for(int i=0;i<10;i++) {
                cur[deg] = '0' + i;
                gao(cur, deg+1);
            }
        } else {
            cur[deg] = C[deg];
            gao(cur, deg+1);
        }
    } else {
        if(J[deg-len]=='?') {
            for(int i=0;i<10;i++) {
                cur[deg] = '0' + i;
                gao(cur, deg+1);
            }
        } else {
            cur[deg] = J[deg-len];
            gao(cur, deg+1);
        }
    }
}

int main() {
    int T;
    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>C>>J;
        len = C.length();
        ansd = 1<<30;
        string cur = C+J;
        gao(cur, 0);
        cout<<"Case #"<<t<<": "<<ansc<<" "<<ansj<<endl;
    }
    return 0;
}
