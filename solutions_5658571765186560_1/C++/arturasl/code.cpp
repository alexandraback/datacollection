#include      <algorithm>
#include      <cassert>
#include      <cmath>
#include      <cstdarg>
#include      <cstdio>
#include      <cstdlib>
#include      <iomanip>
#include      <iostream>
#include      <iterator>
#include      <limits>
#include      <list>
#include      <map>
#include      <set>
#include      <queue>
#include      <vector>
#define endl '\n'
#define each(c, e) for (typeof(c.begin()) e = c.begin(); e != c.end(); ++e)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

bool solve() {
	int X, R, C;
	cin >> X >> R >> C;

	return (R % X == 0 || C % X == 0) \
			&& (R >= X || C >= X) \
			&& (R >= X - 1 && C >= X - 1);

	// switch (X) {
	// 	case 1: return true;
	// 	case 2: return (R % 2 == 0 || C % 2 == 0);
	// 	case 3: return (R % 3 == 0 || C % 3 == 0)
	// 			&& (R >= 3 || C >= 3)
	// 			&& (R > 1 && C > 1);
	// 	case 4: return ((R % 2 == 0 && C % 2 == 0) || R % 4 == 0 || C % 4 == 0)
	// 			&& (R >= 4 || C >= 4)
	// 			&& (R > 2 && C > 2);
	// }
	// assert(false);
}

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t += 1) {
		cout << "Case #" << t << ": " << (solve() ? "GABRIEL" : "RICHARD") << endl;
	}
	return 0;
}
