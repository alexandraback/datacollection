#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define FOR(i, a, b) for (auto i = (a); i < (b); i++)
#define FORD(i, a, b) for (auto i = (b)-1; i >= (a); i--)
#define FORE(it, x) for (auto it = (x).begin(); it != (x).end(); ++it)
#define ALL(x) (x).begin(), (x).end()

static int c, d, v;
static vector<bool> have;
static vector<vector<bool>> can; // [i][j]: i-t ki tudjuk-e fizetni ugy hogy minden erme <= j
int best(int last, int maxr)
{
	FOR(i, 0, v + 1) FOR(j, 0, v + 1) can[i][j] = false;
	FOR(i, 0, v+1) can[0][i] = true;
	FOR(i, 1, v+1) FOR(j, 0, v+1) FOR(k, 1, min(i+1, j+1)) {
		if (have[k] && can[i - k][k-1]) {
			can[i][j] = true;
			break;
		}
	}
	int ok = 0;
	FOR(i, 1, v + 1) {
		if (can[i][v]) {
			ok++;
		}
	}
	if (ok == v) return 0;
	FOR(ret, 1, maxr + 1) {
		FOR(i, last + 1, v + 1) {
			if (!have[i]) {
				have[i] = true;
				if (best(i, ret - 1) != -1) {
					return ret;
				}
				have[i] = false;
			}
		}
	}
	return -1;
}

int main()
{
	int tn;
	cin >> tn;
	FOR(ti, 1, tn + 1) {
		cin >> c >> d >> v;
		have = vector<bool>(v + 1);
		can = vector<vector<bool>>(v + 1, vector<bool>(v + 1));
		FOR(i, 0, d) {
			int x;
			cin >> x;
			have[x] = true;
		}
		cout << "Case #" << ti << ": " << best(0, v) << endl;
	}
	return 0;
}
