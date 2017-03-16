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

static bool testcase() {
	int X, R, C;
	cin >> X >> R >> C;
	if (R > C) swap(R, C);

	if (X > C) return true;

	if ((R * C) % X != 0) return true;

	if (X > 6) return true;

	switch (X) {
		case 3: return !(R >= 2 && C >= 3);
		case 4: return !(R >= 3 && C >= 4);
		case 5: return !(R >= 4 && C >= 5);
		case 6: return !(R >= 4 && C >= 6);
	}

	return false;
}

int main() {
	ios::sync_with_stdio(false);

	int TC;
	cin >> TC;
	FOR(tc, 1, TC+1)
		printf("Case #%d: %s\n", tc, testcase() ? "RICHARD" : "GABRIEL");
}
