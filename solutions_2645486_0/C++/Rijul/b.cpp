#include<stdio.h>
#include<string.h>
#include<math.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

#define inf (1<<29)
#define maxm 101000
#define ii __int64

int on(int n,int k){
    return (n|(1<<k));
}
int off(int n,int k){
    return (n-(n&(1<<k)));
}
bool chck(int n,int k){
    return (n&(1<<k));
}


ii mini(ii a,ii b){ if(a<b) return a; return b; }
ii maxi(ii a,ii b){ if(a>b) return a; return b; }

ii e,r,n,v[maxm];
ii dp[50][50];
bool fl[50][50];

ii cal(int ind,int rem);

int main(){

    int i,j,k,l,test,t=1;

    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    scanf("%d",&test);

    while(test--){

        scanf("%I64d %I64d %I64d",&e,&r,&n);

        for(i=1;i<=n;i++){
            scanf("%I64d",&v[i]);
        }
        ii ans=0,now=e;

        memset(fl,0,sizeof(fl));
        ans=cal(1,e);

        printf("Case #%d: %I64d\n",t++,ans);
    }

    return 0;
}


ii cal(int ind,int rem){

    if(ind>n) return 0;

    if(fl[ind][rem]) return dp[ind][rem];
    fl[ind][rem]=1;

    ii ret=0;

    for(int i=0;i<=rem;i++){
        ret=maxi(ret,cal(ind+1,mini(rem-i+r,e))+(v[ind]*i));
    }

    return dp[ind][rem]=ret;
}
