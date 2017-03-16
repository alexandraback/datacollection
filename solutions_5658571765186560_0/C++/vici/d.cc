#include <bits/stdc++.h>
using namespace std;
int const N = 21;
inline void pw(int ca) { printf("Case #%d: GABRIEL\n", ca++); }
inline void pl(int ca) { printf("Case #%d: RICHARD\n", ca++); }
int x, r, c;

int main() {
	freopen("D-small-attempt1.in", "r", stdin);
	freopen("D-small-ans.txt", "w", stdout);
	//freopen("D-large.in", "r", stdin);
	//freopen("D-large-ans.txt", "w", stdout);
	int T, ca = 1;
	for (scanf("%d", &T); T--; ) {
		scanf("%d%d%d", &x, &r, &c);
		if (r > c) {
			swap(r, c);
		}
		
		if (r * c % x != 0) {
			pl(ca++);
			continue;
		}
		
		if (x == 1) {
			pw(ca++);
		} else if (x == 2) {
			pw(ca++);
		} else if (x == 3) {
			if (r >= 2 && c >= 3) {
				pw(ca++);
			} else {
				pl(ca++);
			}
		} else if (x == 4) {
			if (r >= 3 && c >= 4) {
				pw(ca++);
			} else {
				pl(ca++);
			}
		}
	}
	return 0;
}

