#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
#include <cstdlib>
#include <climits>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

template <typename T> using V = vector<T>;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> Pii;

const double Pi = acos(-1.0);

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i, l, r) for (int i = int(l); i < int(r); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))


string s, t;
int best = INT_MAX;
int bestC = INT_MAX, bestJ = INT_MAX;
string bests, bestt;

void solve(int i) {
	if (i == s.size()) {
		int C = atoi(s.c_str()), J = atoi(t.c_str());
		int d = abs(C - J);

		if (d < best) {
			best = d, bestC = C, bestJ = J, bests = s, bestt = t;
		}
		else if (d == best && C < bestC) {
			bestC = C, bestJ = J, bests = s, bestt = t;
		}
		else if (d == best && C == bestC && J < bestJ) {
			bestJ = J, bestt = t;
		}

		return;
	}

	if (s[i] != '?' && t[i] != '?') return solve(i + 1);

	bool b1 = s[i] == '?', b2 = t[i] == '?';

	for (int a = '0'; a <= '9'; ++a) {
		for (int b = '0'; b <= '9'; ++b) {
			if (b1) s[i] = a;
			if (b2) t[i] = b;
			solve(i + 1);
		}
	}

	if (b1) s[i] = '?';
	if (b2) t[i] = '?';
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	int T; cin >> T;
	forn(tc, T) {
		cin >> s >> t;

		best = INT_MAX;
		bestC = INT_MAX, bestJ = INT_MAX;
		solve(0);

		cout << "Case #" << tc + 1 << ": " << bests << ' ' << bestt << endl;
	}

}