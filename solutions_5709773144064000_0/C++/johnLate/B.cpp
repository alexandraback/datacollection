#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>
#include <numeric>
#include <iomanip>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#include <bitset>
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
#define DBG(...) { if(1) fprintf(stderr, __VA_ARGS__); }
#define DBGDO(X) { if(1) cerr << "DBGDO: " << (#X) << " = " << (X) << endl; }

int main() {
	int TC; cin >> TC;
	FOR(tc, 1, TC+1) {
		double C, F, X;
		cin >> C >> F >> X;

		double rate = 2.0;
		double t = 0.0;
		double have = 0.0;
		double best = 1e42;
		while (t < best) {
			double todo = X - have;
			best = min(best, t + todo / rate);

			todo = C - have;
			if (todo <= 0) break;
			t += todo / rate;
			have = 0.0;
			rate += F;
		}

		printf("Case #%d: %.9lf\n", tc, best);
	}
}
