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

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	int T; cin >> T;
	forn(tc, T) {
		int J, P, S, K;
		cin >> J >> P >> S >> K;

		map<Pii, int> jp;
		map<Pii, int> ps;
		map<Pii, int> js;
		vector<tuple<int, int, int>> v;


		int ans = 0;
		forn(j, J) forn(p, P) forn(s, S) {
			int& p1 = jp[{j, p}];
			int& p2 = ps[{p, s}];
			int& p3 = js[{j, s}];

			if (p1 == K || p2 == K || p3 == K) {
				continue;
			}
			++p1, ++p2, ++p3;
			v.push_back(make_tuple(j,p,s));
			++ans;
		}
		cout << "Case #" << tc + 1 << ": " << ans << endl;
		for (auto t : v) {
			cout << get<0>(t)+1 << ' ' << get<1>(t)+1 << ' ' << get<2>(t)+1 << endl;
		}
	}
}