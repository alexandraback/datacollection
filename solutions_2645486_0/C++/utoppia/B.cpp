#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<queue>
#include<map>
#include<iostream>
using namespace std;

#define FOR(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define DOR(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define bug puts("Fuck");
#define LL long long
#define pb push_back
#define mp make_pair

#define nMax 10100000
#define eps 1e-8
#define inf 0x7fffffff



LL a[nMax],dp[nMax];

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
    int t,cas=1;
    int V,r,n;
    scanf("%d",&t);
    while(t--){
        LL sum = 0;
        LL mxx=0;
        scanf("%d%d%d",&V,&r,&n);
        r = min(V,r);
        memset(dp,0,sizeof(dp));
        FOR(i,1,n){
            scanf("%lld",&a[i]);
          //  mxx =max(mxx,a[i]);
            //sum += (LL)r*a[i];
        }
       // V -= r;
       LL tt=0;
       FOR(i,1,n){
        //   printf("%d : ",i);
           LL tw  =0;
           LL tx = 0;
            DOR(j,V,0)  {
                //dp[j] = max(dp[j],dp[j-1]+a[i]);
                if(j==V){
                    dp[j]=tt;
                }else if(j>=r)dp[j]=dp[j-r];
                else dp[j]=0;
                dp[j]=max(dp[j],tw);
                tw = max(tw+a[i],dp[j]+a[i]);
                if(j>=V-r) tx =max(tx,dp[j]);
             //   printf("dp[%d]=%lld ",j,dp[j]);
            }
            //printf("\n");
            tt = tx;
        }
        LL mx = 0;
        FOR(i,0,V)mx=max(mx,dp[i]);
        printf("Case #%d: %lld\n",cas++,mx);
    }
}
