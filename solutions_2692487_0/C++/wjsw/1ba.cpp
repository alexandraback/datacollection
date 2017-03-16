#include <stdio.h>
#include <map>
#include <algorithm>
using namespace std;
int m[100];
void ifminset(map<int, int> &ma, int f, int s) {
	if (ma.find(f) == ma.end())
		ma[f] = s;
	else if (ma[f] > s)
		ma[f] = s;
}
int main() {
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);

	int t;
	scanf("%d", &t);
	for (int tt = 1; tt <= t; ++tt) {
		int a, n;
		scanf("%d%d", &a, &n);
		for (int i = 0; i < n; ++i)
			scanf("%d", m + i);
		sort(m, m + n);
		map<int, int> s[101];
		s[0][a] = 0;
		for (int i = 0; i < n; ++i) {
			for (map<int, int>::iterator it = s[i].begin(); it != s[i].end();
					++it) {
				ifminset(s[i + 1], it->first, it->second + 1);
				if (it->first > 1) {
					int x = it->first, y = 0;
					while (x <= m[i]) {
						x += x - 1;
						++y;
					}
					ifminset(s[i + 1], x + m[i], it->second + y);
				}
			}
			for (map<int, int>::iterator it = s[i + 1].begin();
					it != s[i + 1].end();) {
				map<int, int>::iterator it2 = it++;
				if (it != s[i + 1].end()) {
					if (it2->second >= it->second) {
						s[i + 1].erase(it2);
						if (it != s[i + 1].begin())
							--it;
					}
				}
			}
			/*			printf("%d\n",i+1);
			 for (map<int, int>::iterator it = s[i + 1].begin();
			 it != s[i + 1].end(); ++it) {
			 printf("%d %d\n", it->first, it->second);
			 }*/
		}
		printf("Case #%d: %d\n", tt, s[n].begin()->second);
	}
}
