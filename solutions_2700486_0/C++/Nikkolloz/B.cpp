#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

int tc, n, x, y;
set<pair<int, int> > s;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &tc);
	for (int tn = 0; tn < tc; tn++) {
		scanf("%d%d%d", &n, &x, &y);
		int p = 0, q = 0;
		for (int m = 0; m < (1<<n); m++) {
			s.clear();
			s.insert(make_pair(0, 0));
			int h = 0;
			for (int i = 1; i < n; i++) {
				int xx = 0, yy = h+2;
				while (1) {
					if (s.find(make_pair(xx-1, yy-1)) == s.end() && s.find(make_pair(xx+1, yy-1)) == s.end()) {
						if (m & (1<<i)) {
							xx--;
							yy--;
						} else {
							xx++;
							yy--;
						}
					} else if (s.find(make_pair(xx-1, yy-1)) == s.end() && s.find(make_pair(xx+1, yy-1)) != s.end()) {
						xx--;
						yy--;
					} else if (s.find(make_pair(xx-1, yy-1)) != s.end() && s.find(make_pair(xx+1, yy-1)) == s.end()) {
						xx++;
						yy--;
					} else
						break;
					if (yy == 0)
						break;
				}
				s.insert(make_pair(xx, yy));
				if (xx == 0)
					h = yy;
			}
			if (s.find(make_pair(x, y)) != s.end())
				q++;
			p++;
		}
		printf("Case #%d: %.9lf\n", tn+1, q / (double) p);
	}
	return 0;
}