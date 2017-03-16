#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<string>
#include<stdio.h>
#define rep(i,a,b) for (int i=(a);i<=(b);i++)
using namespace std;
typedef long long LL;
char c[111];
int main(){
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B_small.out","w",stdout);
    int T;
    cin>>T;
    rep(t,1,T){
        scanf("%s",c);
        printf("Case #%d: ",t);
        int n = strlen(c);
        c[n] = '+';
        int ans = 0;
        rep(i,1,n){
            if (c[i]!=c[i-1]) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
