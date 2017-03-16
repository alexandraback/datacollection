#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <cctype>
#include <map>
#include <iomanip>
                   
using namespace std;
                   
#define eps 1e-8
#define pi acos(-1.0)
#define inf 1<<30
#define linf 1LL<<60
#define pb push_back
#define lc(x) (x << 1)
#define rc(x) (x << 1 | 1)
#define lowbit(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define fi first
#define se second


ll v[1000];
int e,r,n;
ll dp[10000][100];

ll gao(int i,int lefe) {
    if (dp[i][lefe]!=-1) return dp[i][lefe];
    
    if (i==n) return 0;
    ll ans=0;
    for (int k=0; k<=lefe; k++) {
        int leff=min(lefe+r-k,e);
        ans=max(ans,k*v[i]+gao(i+1,leff));
    }
    dp[i][lefe]=ans;
    return dp[i][lefe];
}

int main() {
    freopen("b.in","r",stdin);
    freopen("bb.txt","w",stdout);
    int T,cas=0;
    cin >> T;
    while (T--) {
        cin >> e >> r >> n;
        for (int i=0; i<n; i++) cin >> v[i];
        cas++;
        cout << "Case #" <<  cas << ": ";
        memset(dp,-1,sizeof(dp));  
        cout << gao(0,e) << endl;
    }
    return 0;
}
