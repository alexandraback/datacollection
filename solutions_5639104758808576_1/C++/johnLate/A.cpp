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
string S;

int main() {
	ios::sync_with_stdio(false);

	cin >> TC;
	FOR(tc, 1, TC+1) {
		cin >> N >> S;

		int res = 0;
		int standing = 0;

		FOR(p,0,sz(S)) {
			int need = max(0, p - standing);
			res += need;
			standing += need;
			standing += S[p] - '0';
		}

		printf("Case #%d: %d\n", tc, res);
	}
}
