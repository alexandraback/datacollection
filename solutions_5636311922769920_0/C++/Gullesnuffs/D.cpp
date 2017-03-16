#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define all(v) (v).begin(), (v).end()
#define what_is(x) cerr << #x << " is " << x << endl;

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

ll K, C, S;

void solve(){
	scanf("%lld%lld%lld", &K, &C, &S);
	vector<ll> ans;
	for(int i=1; i <= K; i += C){
		ll x=0;
		for(int j=0; j < C; ++j){
			x *= K;
			if(i+j <= K)
				x += i+j-1;
		}
		ans.push_back(x);
	}
	if(((int)ans.size()) > S){
		puts(" IMPOSSIBLE");
		return;
	}
	rep(i,0,ans.size())
		printf(" %lld", ans[i]+1);
	printf("\n");
}

int main(){
	int T;
	scanf("%d", &T);
	for(int i=1; i <= T; ++i){
		printf("Case #%d:", i);
		solve();
	}
}
