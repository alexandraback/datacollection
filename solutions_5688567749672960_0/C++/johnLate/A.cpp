#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;

#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = int(b)-1; i >= (a); i--)
#define FORIT(i,c) for(__typeof__((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define mp make_pair
#define pb push_back
#define has(c,i) ((c).find(i) != (c).end())
#define DBG(...) ({ if(1) fprintf(stderr, __VA_ARGS__); })
#define DBGDO(X) ({ if(1) cerr << "DBGDO: " << (#X) << " = " << (X) << endl; })

int TC;
int N;
const int maxN = 1024 * 1024;
pii dp[maxN];

int main() {
	ios::sync_with_stdio(false);

	dp[0] = mp(maxN, 0);
	dp[1] = mp(1, 0);
	FOR(i,2,maxN) {
		int rev = 0;
		string x = to_string(i);
		reverse(all(x));
		if (x[0] != '0') {
			int tmp = stoi(x);
			if (tmp < i)
				rev = tmp;
		}
		dp[i] = min(
			mp(dp[i-1].first + 1, i-1),
			mp(dp[rev].first + 1, rev)
		);
		if (i < 5)
			DBG("%3d: %3d %3d\n", i, dp[i].first, dp[i].second);
	}

	cin >> TC;
	FOR(tc, 1, TC+1) {
		cin >> N;

		printf("Case #%d: %d\n", tc, dp[N].first);
	}
}
