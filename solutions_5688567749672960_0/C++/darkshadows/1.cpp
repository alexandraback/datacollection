#include<bits/stdc++.h>
#define assn(n,a,b) assert(n<=b && n>=a)
using namespace std;
#define pb push_back
#define mp make_pair
#define clr(x) x.clear()
#define sz(x) ((int)(x).size())
#define F first
#define S second
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,b) for(i=0;i<b;i++)
#define rep1(i,b) for(i=1;i<=b;i++)
#define pdn(n) printf("%d\n",n)
#define sl(n) scanf("%lld",&n)
#define sd(n) scanf("%d",&n)
#define pn printf("\n")
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;
#define MOD 1000000007
LL mpow(LL a, LL n) 
{LL ret=1;LL b=a;while(n) {if(n&1) 
    ret=(ret*b)%MOD;b=(b*b)%MOD;n>>=1;}
return (LL)ret;}
#define MAXN 1000009
int dp[MAXN+10];
int rev(int n){
    int ret=0;
    while(n){
        ret=ret*10+n%10;
        n/=10;
    }
    return ret;
}
void doo(){
    dp[1]=1;
    for(int i=2; i<=MAXN; i++){
        dp[i]=dp[i-1]+1;
        int j=rev(i);
        if(j<i and i%10!=0)dp[i]=min(dp[i],dp[j]+1);
    }
}
int main()
{
    doo();
    int t,p;
    sd(t);
    p=t;
    while(t--){
        int n;
        sd(n);
        printf("Case #%d: %d\n",p-t,dp[n]);
    }
    return 0;
}
