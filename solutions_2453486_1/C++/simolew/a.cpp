#include<iostream>
using namespace std;

void d(int c) {
    cout<<"Case #"<<c<<": ";
    char s[4][4];
    for(int i=0;i<4;i++) for(int j=0;j<4;j++) cin>>s[i][j];
    for(int i=0;i<4;i++) {
        bool x=true;
        bool o=true;
        for(int j=0;j<4;j++) {
            if(s[i][j]=='.') {
                x=false;
                o=false;
            }
            if(s[i][j]=='X') o=false;
            if(s[i][j]=='O') x=false;
        }
        if(x) {cout<<"X won\n";return;}
        if(o) {cout<<"O won\n";return;}
    }
    bool notcomp=false;
    for(int i=0;i<4;i++) {
        bool x=true;
        bool o=true;
        for(int j=0;j<4;j++) {
            if(s[j][i]=='.') {
                notcomp=true;
                x=false;
                o=false;
            }
            if(s[j][i]=='X') o=false;
            if(s[j][i]=='O') x=false;
        }
        if(x) {cout<<"X won\n";return;}
        if(o) {cout<<"O won\n";return;}
    }

    {
        int xx=0,oo=0,tt=0;
        for(int a=0;a<4;a++) {
        if(s[a][a]=='X') xx++;
        if(s[a][a]=='O') oo++;
        if(s[a][a]=='T') tt++;
        }
        if(xx>=3 && xx+tt==4) { cout<<"X won\n";return;}
        if(oo>=3 && oo+tt==4) { cout<<"O won\n";return;}
    }
    {
        int xx=0,oo=0,tt=0;
        for(int a=0;a<4;a++) {
        if(s[a][3-a]=='X') xx++;
        if(s[a][3-a]=='O') oo++;
        if(s[a][3-a]=='T') tt++;
        }
        if(xx>=3 && xx+tt==4) { cout<<"X won\n";return;}
        if(oo>=3 && oo+tt==4) { cout<<"O won\n";return;}
    }
    if(notcomp) cout<<"Game has not completed\n";
    else cout<<"Draw\n";
}

int main() {
    int t=0;
    cin>>t;
    for(int i=1;i<=t;i++) d(i);
}
