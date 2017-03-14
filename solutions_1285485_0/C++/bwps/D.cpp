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

using namespace std;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;

#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = int(b)-1; i >= (a); i--)
#define FORIT(i,c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)

int T, H, W, D, R, C;
string grid[40];

int gcd(int a, int b) {
	return (b == 0) ? a : gcd(b, a%b);
}

int main() {
	cin >> T;
	FOR(cs, 1, T+1) {
		cin >> H >> W >> D;
		FOR(i, 0, H) cin >> grid[i];
		FOR(i, 0, H) FOR(j, 0, W) {
			if (grid[i][j] == 'X') {
				R = i-1, C = j-1;
			}
		}
		H -= 2, W -= 2;
		set<pii> dirs;
		FOR(i, -D, D+1) FOR(j, -D, D+1) {
			if (i == 0 && j == 0) continue;
			int r = R + H*i;
			if (abs(i)%2) r += H-1-2*R;
			int c = C + W*j;
			if (abs(j)%2) c += W-1-2*C;
			int dx = r - R, dy = c - C;
			if (dx*dx + dy*dy > D*D) continue;
			int g = gcd(abs(dx), abs(dy));
			dx /= g, dy /= g;
			dirs.insert(pii(dx, dy));
		}
		cout << "Case #" << cs << ": " << sz(dirs) << endl;
	}
	return 0;
}
