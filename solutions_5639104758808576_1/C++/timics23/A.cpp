#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;
string s;
int T,N,x,S;

int main() {
    freopen("input.in","r",stdin);
    freopen("outputA","w",stdout);
    scanf("%d",&T);
    for(int t=1;t<=T;++t) {
        scanf("%d",&N);
        cin>>s;
        x = 0;
        S = 0;
        for(int i=0;i<s.size();++i) {
            S += (1 + '0' - s[i]);
            x = max(x, S);
        }
        printf("Case #%d: %d\n",t,x);
    }
    return 0;
}
