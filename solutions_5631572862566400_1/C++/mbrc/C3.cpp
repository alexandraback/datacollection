#include <bits/stdc++.h>
#define rep(i,x,y) for (int i = (x); i<=(y); i++)
#define repe(i,x,y) for (int i = (x); i < (y);i++)
#define drep(i,x,y) for (int i = (x); i >= (y); i--)
#define mp make_pair
#define pb emplace_back
#define mt make_tuple
#define gcd __gcd
#define sf(n) scanf("%Lf",&n)
#define prf(n) printf("%.12Lf",n)
#define	s(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define pr(n) printf("%d",n)
#define prl(n) printf("%lld",n)
#define endc printf("\n")
#define psp printf(" ")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

const int maxn = 1e5 + 7;
const ll md = 1e9 + 7;

int f[maxn];
int dp[maxn];
int id[maxn];
bool vis[maxn];
int mv[maxn];
int en[maxn];
int men[maxn];

int dfs(int x) {
	vis[x] = true;
	if (id[f[x]] < 0 && !vis[f[x]]) dfs(f[x]);

	dp[x] = dp[f[x]] + 1;
	id[x] = id[f[x]];
	en[x] = en[f[x]];
	if (men[en[x]] < 0 || dp[men[en[x]]] < dp[x]) {
		men[en[x]] = x;
	}
}

const int inf = 1e9;

int init;

int a[maxn];
int b[maxn];

int cyc(int x) {

	//cout<<x<<" -> "<<f[x]<<endl;

	vis[x] = true;
	if (vis[f[x]] && f[x]!=init) return -inf;
	if (vis[f[x]]) return 1;
	return 1 + cyc(f[x]);
}

void solve(int tc) {
	int n; cin>>n;
	rep(i,1,n) {
		cin>>f[i];
		id[i] = -1; vis[i] = false;
		mv[i] = 0;
		en[i] = -1;
		men[i] = -1;
		a[i] = -1; b[i] = -1;
	}

	int idx = 0;

	int ans = 0;

	rep(i,1,n) {
		if (f[f[i]] == i && id[i] < 0) {
			idx++; dp[i] = 1; dp[f[i]] = 1; id[i] = id[f[i]] = idx; en[i] = i; en[f[i]] = f[i];
			men[i] = i; men[f[i]] = f[i];
			vis[i] = vis[f[i]] = true;
			ans = 2;

			a[idx] = i; b[idx] = f[i];			
		}
	}

	rep(i,1,n) {
		if (id[i] < 0) dfs(i);
	}

	rep(i,1,n) {

		//cout<<i<<" : "<<dp[i]<<" : "<<id[i]<<endl;

		vis[i] = false;
	}

	rep(i,1,n) {
		rep(j,1,n) {
			vis[j] = false;
		}
		init = i;
		int v = cyc(i);
		ans = max(ans,v);
		//cout<<i<<" : "<<v<<endl;
	}	

	int cur = 0;

	rep(i,1,idx) {
		cur += dp[men[a[i]]] + dp[men[b[i]]];
	}

	ans = max(ans,cur);

	cout<<"Case #"<<tc<<": "<<ans<<endl;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int t; cin>>t; rep(i,1,t) solve(i);
}
