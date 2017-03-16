#include <bits/stdc++.h>
using namespace std;

#define s(n)            scanf("%d",&n)
#define sl(n)           scanf("%lld",&n)
#define sf(n)           scanf("%lf",&n)
#define ss(n)           scanf("%s",n)
#define pls(x)          cout << x << " "
#define pln(x)          cout << x << "\n"
#define pis(x)          printf("%d ", x)
#define pin(x)          printf("%d\n", x)
#define pnl             printf("\n")
#define dbn             cerr << "\n"
#define dbg(x)          cerr << #x << " : " << x << " "
#define dbs(x)          cerr << x << " "
#define FOR(i,a,b)      for(int i=a;i<=b;i++)
#define rep(i,n)        FOR(i,0,n-1)
#define foreach(c,v)    for(__typeof((c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define mp              make_pair
#define FF              first
#define SS              second
#define pb              push_back
#define fill(a,v)       memset(a,v,sizeof(a))
#define all(x)          x.begin(),x.end()
#define sz(v)           ((int)(v.size()))
#define INF             (int)1e9
#define LINF            (long long)1e18
#define EPS             1e-9
#define INDEX(arr,ind)  (lower_bound(all(arr),ind)-arr.begin())

typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
typedef vector<int> vi;
typedef vector<lli> vlli;
typedef vector<pii> vii;

const int MAXN = 2000015;
const int MOD  = 1000000007;
/*Main code begins now */
int dp[MAXN];
int N;
int reverse(int n){
	vi A;
	while(n) {
		A.pb(n%10);
		n/=10;
	}
	n = sz(A);
	int ret = 0;
	rep(i,n){
		ret = A[i] + ret*10;
	}
	return ret;
}
int go(int n){
	dp[n] = 1;
	for(int i = n-1;i>=1;i--){
		int m = reverse(i);
		dp[i] = dp[i+1] + 1;
		if(i <=N) dp[i] = min(dp[i],dp[m]+1);
	}
	return dp[1];
}
int main(){
	int t,n;
	s(t);
	rep(z,t){
		printf("Case #%d: ",z+1);
		rep(i,MAXN) dp[i] = INF;
		s(N);
		printf("%d\n",go(N));
	}
	return 0;
}