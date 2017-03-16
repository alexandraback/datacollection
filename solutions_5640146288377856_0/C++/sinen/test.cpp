#include<iostream>
#include<cstdio>
using namespace std;

void asd(){
     int r,c,w;
     cin >> r >> c >> w;
     if(c%w==0){cout << c/w -1+w << endl;}
     else{cout << c/w +w << endl;}
}

int main(){
    freopen ("A-small-attempt0.in","r",stdin);
    freopen ("A-small-attempt0.out","w",stdout);
    int t;
    cin >> t;
    for(int i=1; i<t+1; i++){
            cout << "Case #" << i << ": "; asd();
    }
    return 0;
}
