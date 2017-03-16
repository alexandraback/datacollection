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

static inline
int div_up(int a, int b) {
	return (a + b - 1) / b;
}

static const int maxD = 1024;

static int P[maxD];

static int testcase()
{
	int D;
	cin >> D;
	FOR(i,0,D) cin >> P[i];

	int maxP = 0;
	FOR(i,0,D) maxP = max(maxP, P[i]);

	int best = oo;
	FOR(downto, 1, maxP+1) {
		int cur = 0;
		int biggest_part = 0;

		FOR(i,0,D) {
			if (P[i] <= downto) {
				biggest_part = max(biggest_part, P[i]);
			} else {
				int parts = div_up(P[i], downto);
				biggest_part = max(biggest_part, div_up(P[i], parts));
				cur += parts - 1;
			}
		}

		cur += biggest_part;
		best = min(best, cur);
	}
	return best;
}

int main() {
	ios::sync_with_stdio(false);

	int TC;
	cin >> TC;
	FOR(tc, 1, TC+1)
		printf("Case #%d: %d\n", tc, testcase());
}
