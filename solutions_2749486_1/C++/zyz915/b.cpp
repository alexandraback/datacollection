#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

bool can[1000010];
int pre[1000010];
map<int, int> mx, my;

void solve1(int n, map<int, int> c, int sum, map<int, int> &m) {
	if (sum == 0) {
		return;
	}
	memset(can, 0, sizeof(can));
	memset(pre, 0, sizeof(pre));
	can[0] = true;
	for (int i = 1; i <= n; i++) {
		if (c.count(i)) continue;
		for (int j = sum; j >= i; j--) {
			if (!can[j] && can[j - i]) {
				can[j] = true;
				pre[j] = i;
			}
		}
		if (can[sum]) break;
	}
	if (!can[sum]) {
		printf("error\n");
		return;
	}
	while (sum > 0) {
		m[pre[sum]] = 1;
		sum -= pre[sum];
	}
}


void solve(int n, int sum, int x, int y, map<int, int> &mx, map<int, int> &my) {
	map<int, int> c;
	int cc = (sum - x - y) / 2;
	if (cc <= n) {
		c[cc] = 1;
	} else {
		int a = cc / 2, b = cc / 2 + 1;
		while (a + b > cc) {
			a--;
		}
		while (a + b < cc) {
			b++;
		}
		c[a] = 1;
		c[b] = 1;
	}
	if (x < y) {
		solve1(n, c, x, mx);
		for (int i = 1; i <= n; i++) {
			if (!mx.count(i)) {
				my[i] = 1;
			}
		}
		for (map<int, int>::iterator it = c.begin(); it != c.end(); it++) {
			my[it->first] = -1;
		}
	} else {
		solve1(n, c, y, my);
		for (int i = 1; i <= n; i++) {
			if (!my.count(i)) {
				mx[i] = 1;
			}
		}
		for (map<int, int>::iterator it = c.begin(); it != c.end(); it++) {
			mx[it->first] = -1;
		}
	}
}



int main() {

	int test;
	scanf("%d", &test);
	for (int t = 1; t <= test; t++) {
		int x, y;
		bool fx = false, fy = false;
		scanf("%d%d", &x, &y);
		if (x < 0) {
			x = -x;
			fx = true;
		}
		if (y < 0) {
			y = -y;
			fy = true;
		}
		int n;
		int sum = 0;
		for (n = 1; n <= 10000; n++) {
			sum += n;
			if (sum >= x + y && sum % 2 == (x + y) % 2) {
				break;
			}
		}
		mx.clear();
		my.clear();
		solve(n, sum, x, y, mx, my);
		printf("Case #%d: ", t);
		int xx = 0, yy = 0;
		for (int i = 1; i <= n; i++) {
			if (mx.count(i)) {
				if ((mx[i] > 0) ^ fx) {
					printf("E");
					xx += i;
				} else {
					printf("W");
					xx -= i;
				}
			} else {
				if ((my[i] > 0) ^ fy) {
					printf("N");
					yy += i;
				} else {
					printf("S");
					yy -= i;
				}
			}
		}
		printf("\n");
	}
}