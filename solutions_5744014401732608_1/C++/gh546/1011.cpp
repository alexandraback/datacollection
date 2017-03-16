#include <cstdio>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
int a[53][53];
int bit[55];
void solve(int n,ll k,int m){
    int cnt=0;
    memset(bit,0,sizeof(bit));
    int y=k;
    while(k){
        if(k&1) bit[cnt++]=1;
        else bit[cnt++]=0;
        k>>=1;
    }
    //printf("n=%d cnt=%d\n",n,cnt);
    memset(a,0,sizeof(a));
    for(int i=2;i<=m;i++)
        for(int j=i+1;j<=m;j++) a[i][j]=1;
    int x=2;
    if(y==(1LL<<n)){
        for(int i=2;i<=m;i++) a[1][i]=1;
    }
    else{
        for(int i=n-1;i>=0;i--){
            if(bit[i]) a[1][x]=1;
            x++;
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++) printf("%d",a[i][j]);
        printf("\n");
    }
    return ;
}
int main()
{
#ifdef gh546
freopen("b.in","r",stdin);
freopen("b.out","w",stdout);
#endif // gh546

    int t,n,cas=1;
    ll k;scanf("%d",&t);
    while(t--){
        scanf("%d%lld",&n,&k);
        //if(n==2&&k==2)
        int m=n-2;
        if((1LL<<m)>=k){
            printf("Case #%d: POSSIBLE\n",cas++);
            solve(m,k,n);
        }else{
            printf("Case #%d: IMPOSSIBLE\n",cas++);
        }
    }
    return 0;
}
