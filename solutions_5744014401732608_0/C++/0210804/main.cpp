#include <iostream>
#include <cstdio>
using namespace std;

int need[55];

void solve(){
    int b;
    long long m;
    scanf("%d%lld",&b,&m);
    if((1LL<<(b-2))<m){
        puts(" IMPOSSIBLE");
        return ;
    }
    puts(" POSSIBLE");

    for(int i=b-1;i>0;i--){
        long long num;
        if(i==1) num = 1;
        else num = 1LL<<(i-2);
        if(num<=m){
            need[i] = 1;
            m -= num;
        }else need[i] = 0;
    }

    for(int i=1;i<=b-1;i++){
        for(int j=1;j<b;j++){
            printf("%d",(j>i?1:0));
        }
        printf("%d\n",need[i]);
    }
    for(int i=0;i<b;i++){
        printf("0");
    }
    puts("");
}

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("b_small.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        printf("Case #%d:",i);
        solve();
    }
    return 0;
}
