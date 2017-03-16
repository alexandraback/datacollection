#include <vector>
#include <map>
#include <set>
#include <deque>
#include <algorithm>
#include <functional>
#include <sstream>
#include <cmath>
#include <string>
#include <iostream>

using namespace std;

int main() 
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	

	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		int N, S, p, pt;
		vector<int> point;
		cin >> N >> S >> p;
		for (int i = 0; i < N; i++) { cin >> pt; point.push_back(pt); }
		int c1 = 0, c2 = 0;
		for (int i = 0; i < N; i++) {
			if (point[i] % 3 == 0) {
				pt = point[i]/3;
				if (pt >= p) { c1++; continue; }
				pt = point[i]/3 + (point[i]/3 > 0);
				if (pt >= p) { c2++; continue; }
			} else if (point[i] % 3 == 1) {
				pt = point[i]/3 + 1;
				if (pt >= p) { c1++; continue; }
			} else {
				pt = point[i]/3 + 1;
				if (pt >= p) { c1++; continue; }
				pt = point[i]/3 + 2;
				if (pt >= p) { c2++; continue; }
			}
		}

		printf("Case #%d: %d\n", t, c1 + min(c2, S));
	}
}