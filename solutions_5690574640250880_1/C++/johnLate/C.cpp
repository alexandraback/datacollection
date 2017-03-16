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

char data[64][64];
int R, C, M, F;

void fill_data(char x) {
	FOR(r,0,R) FOR(c,0,C) data[r][c] = x;
}

bool solve() {
	if (F < 1) return false;

	if (M == 0 || F == 1) {
		fill_data(M == 0 ? '.' : '*');
		data[0][0] = 'c';
		return true;
	}

	if (R == 1) {
		FOR(i,1,F) data[0][i] = '.';
		FOR(i,F,C) data[0][i] = '*';
		data[0][0] = 'c';
		return true;
	}

	if (F == 2 || F == 3 || F == 5 || F == 7)
		return false;

	if (R == 2 || F == 4 || F == 6) {
		if (F % 2 != 0) return false;

		fill_data('*');
		FOR(i,0,F/2) data[0][i] = data[1][i] = '.';
		data[0][0] = 'c';
		return true;
	}
	assert(F >= 8);

	fill_data('.');
	data[0][0] = 'c';

	int rr = R-1;
	while (M > 0 && rr >= 3) {
		int k = min(M, C);
		if (k == C-1) k--;

		FOR(i, C-k, C) data[rr][i] = '*';
		M -= k;
		rr--;
	}
	int cc = C-1;
	while (M >= 3) { 
		FOR(r,0,3) data[r][cc] = '*';
		M -= 3;
		cc--;
	}
	while (M > 0) {
		data[2][cc] = '*';
		M--;
		cc--;
	}
	return true;
}

int main() {
	int TC; cin >> TC;
	FOR(tc, 1, TC+1) {
		printf("Case #%d:\n", tc);

		cin >> R >> C >> M;
		F = R*C - M;

		bool flip = false;
		if (R > C) {
			flip = true;
			swap(R, C);
		}

		if (!solve()) {
			puts("Impossible");
			continue;
		}

		if (flip) {
			FOR(i,0,C) FOR(j,i+1,C) {
				swap(data[i][j], data[j][i]);
			}
			swap(R, C);
		}
		FOR(r,0,R) {
			data[r][C] = 0;
			puts(data[r]);
		}
	}
}
