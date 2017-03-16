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

map<int,int> M;

void solve(int tc) {
	int n; cin>>n; M.clear();
	rep(i,1,n+n-1) {
		rep(j,1,n) {
			int x;
			cin>>x; if (M.count(x) == 0) M[x] = 0;
			M[x]++;
		}
	}

	vector<int> V; V.clear();

	for (auto z : M) {
		if (z.second%2 == 1) {
			V.pb(z.first);
		}
	}

	sort(V.begin(),V.end());

	cout<<"Case #"<<tc<<": ";
	repe(i,0,V.size()) {
		cout<<V[i]; if (i < V.size()-1) cout<<" ";
	}
	cout<<endl;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int t; cin>>t; rep(i,1,t) solve(i);
}
