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

int p[1005];

void solve(){
	int D;
	scanf("%d", &D);
	rep(i,0,D)
		scanf("%d", p+i);
	int ans=100000000;
	rep(M,1,1005){
		int t=M;
		rep(i,0,D){
			t += (p[i]-1)/M;
		}
		ans=min(ans,t);
	}
	printf("%d\n", ans);
}

int main(){
	int T;
	scanf("%d", &T);
	for(int t=1; t <= T; ++t){
		printf("Case #%d: ", t);
		solve();
	}
}
