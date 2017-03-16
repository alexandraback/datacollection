#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>

using namespace std;

// Hall of Mirrors

int gcd(int a, int b)
{
	if (b == 0) {
		return a;
	}
	if (a == 0) {
		return b;
	}
	return gcd(b, a % b);
}

int main()
{
	string line;

	int cases;
	cin >> cases;

	for (int caseno = 1; caseno <= cases; caseno++) {
		int H, W, D;
		cin >> H >> W >> D;
		vector <string> map(H);
		int px, py;
		for (int y = 0; y < H; y++) {
			cin >> map[y];
			for (int x = 0; x < W; x++) {
				if (map[y][x] == 'X') {
					px = x;
					py = y;
				}
			}
		}
		int ret = 0;
		int W2 = 2 * (W - 2);
		int H2 = 2 * (H - 2);
		set <pair <int, int> > s;
		for (int y = -D; y <= D; y++) {
			for (int x = -D; x <= D; x++) {
				if (x == 0 && y == 0 ||
				    x * x + y * y > D * D) {
					continue;
				}
				int g = gcd(abs(x), abs(y));
				if ((x % W2 == 0 ||
				     (x % W2 + W2) % W2 == (W - px) * 2 - 3) &&
				    (y % H2 == 0 ||
				     (y % H2 + H2) % H2 == (H - py) * 2 - 3)) {
					if (s.find(make_pair(x / g, y / g)) == s.end()) {
						ret++;
						s.insert(make_pair(x / g, y / g));
					}
				}
			}
		}
		cout << "Case #" << caseno << ": " << ret << endl;
	}

	return 0;
}
