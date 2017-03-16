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
		int N; cin >> N;
		vector<double> blocks[2];
		FOR(i,0,2) {
			blocks[i].reserve(N);
			FOR(n, 0, N) {
				double tmp; cin >> tmp;
				blocks[i].pb(tmp);
			}

			sort(all(blocks[i]));
		}

		int war = 0, dwar = 0;
		int i = N - 1, j = N - 1;

		while (j >= 0) {
			while (i >= 0 && blocks[0][i] > blocks[1][j]) {
				i--;
				war++;
			}
			i--;
			j--;
		}

		int jn = N;
		i = 0;
		j = 0;
		while (i < N) {
			if (blocks[0][i] > blocks[1][j]) {
				i++;
				j++;
				dwar++;
			} else {
				i++;
				jn--;
			}
			assert(j <= jn);
		}
		assert(j == jn);

		cout << "Case #" << tc << ": " << dwar << " " << war << endl;
	}
}
