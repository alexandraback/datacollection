#include<stdio.h>
#include<iostream>
using namespace std;
string S,s;
int N;

int main() {
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    scanf("%d",&N);
    for(int t=1;t<=N;++t) {
        cin>>s;
        S = "";
        S = S + s[0];
        for(int i=1;i<s.size();++i) {
            if(s[i] >= S[0]) {
                S = s[i] + S;

            } else {
                S = S + s[i];
            }
        }
        cout<<"Case #"<<t<<": "<<S<<"\n";
    }
}
