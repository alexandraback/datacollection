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
const int OK = (1<<10)-1;
int now;
void calc(LL n){
    while (n){
        int i = (int)(n%10);
        now|=1<<i;
        n/=10;
    }
}
int main(){
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A_small.out","w",stdout);
    int T;
    cin>>T;
    rep(t,1,T){
        LL n;
        scanf("%I64d",&n);
        printf("Case #%d: ",t);
        if (n==0) printf("INSOMNIA\n");
        else{
            now = 0;
            LL nn = 0;
            while (now != OK){
                nn += n;
                calc(nn);
            }
            printf("%I64d\n",nn);
        }
    }
    return 0;
}
