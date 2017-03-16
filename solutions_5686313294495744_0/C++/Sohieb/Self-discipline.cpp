#include <bits/stdc++.h>
#include <ext/hash_map>
using namespace std;
using namespace __gnu_cxx;

#define Fastcin() cin.tie(0),cerr.tie(0),cout.tie(0),ios_base::sync_with_stdio(0)
#define oo       1e9
#define ll       long long
#define sc(x)    scanf("%d",&x)
#define scl(x)   scanf("%lld",&x)
#define lop(i,n) for(int i=0;i<n;++i)
#define sz(x)    (int)x.size()
#define all(x)   x.begin(),x.end()
#define f        first
#define s        second
#define pi       acos(-1)

int T;
int n;
pair<string,string> arr[20];

int dp[1<<16];

bool good(int mask,int idx){
    int a=0,b=0;
    for(int i=0;i<n;i++){
        if(i==idx)continue;
        if((mask&(1<<i))==0)continue;
        if(arr[i].f==arr[idx].f)a=1;
        if(arr[i].s==arr[idx].s)b=1;
    }
    return (a==1&&b==1);
}

int solve(int mask){
    if(mask==(1<<n)-1)return 0;
    int &ret=dp[mask];
    if(~ret)return ret;
    ret=0;
    for(int i=0;i<n;i++){
        if((mask&(1<<i))!=0)continue;
        ret=max(ret,solve(mask|(1<<i))+good(mask,i));
    }
    return ret;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("C-small-attempt0.in", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    sc(T);
    for(int C=1;C<=T;C++){
        sc(n);
        for(int i=0;i<n;i++)
            cin>>arr[i].first>>arr[i].second;
        memset(dp,-1,sizeof dp);
        printf("Case #%d: %d\n",C,solve(0));
    }
}
