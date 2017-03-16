#include <bits/stdc++.h>
#define gcd         __gcd
#define bitcount    __builtin_popcountll
#define rep(i,j,n)  for(i=j;i<n;i++)
#define tr(it,c)    for(auto it=(c).begin();it!=(c).end();it++)
#define pb          push_back
#define mp          make_pair
#define hell        1000000007
#define uset        unordered_set
#define umap        unordered_map
using namespace std;
typedef pair<int,int> pi;
typedef long long ll;

template <class T> T& get(T &n) {
    cin>>n;
    return n;
}

#define MAXN 1000000

int rev(int x){
    if(x%10==0)
        return x;
    int r=0;
    while(x){
        r=r*10+x%10;
        x/=10;
    }
    return r;
}

int main() {
    static int T,N,i,j,k;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    get(T);
    vector<int> dp(MAXN+1);
    rep(i,1,MAXN+1){
        dp[i]=i;
    }
    rep(i,2,MAXN+1){
        dp[i]=min(dp[i-1]+1,min(i,dp[rev(i)]+1));
    }
    rep(k,1,T+1) {
        get(N);
        int ans = dp[N];
        static char ans_string[100];
        sprintf(ans_string, "Case #%d: %d\n",k,ans);
        cout<<ans_string;
    }
    return 0;
}

