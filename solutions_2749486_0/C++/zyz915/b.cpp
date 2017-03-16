#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

bool can[1000010];
int pre[1000010];
map<int, int> mx, my;



void solve1(int n, int c, int sum, map<int, int> &m) {
	if (sum == 0) {
		return;
	}
	memset(can, 0, sizeof(can));
	memset(pre, 0, sizeof(pre));
	can[0] = true;
	for (int i = 1; i <= n; i++) {
		if (i == c) continue;
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

/*
void solve(int n, int sum, int x, int y, map<int, int> &mx, map<int, int> &my) {
	if (x < y) {
		solve1(n, (sum - x - y) / 2, x, mx);
		for (int i = 1; i <= n; i++) {
			if (!mx.count(i)) {
				my[i] = 1;
			}
		}
		my[(sum - x - y) / 2] = -1;
	} else {
		solve1(n, (sum - x - y) / 2, y, my);
		for (int i = 1; i <= n; i++) {
			if (!my.count(i)) {
				mx[i] = 1;
			}
		}
		mx[(sum - x - y) / 2] = -1;	
	}
}
*/

void solve(int n, int sum, int x, int y, map<int, int> &mx, map<int, int> &my) {
	for (int i = 1; i <= x; i++) {
		mx[i * 2 - 1] = -1;
		mx[i * 2] = 1;
	}
	for (int i = 1; i <= y; i++) {
		my[2 * x + i * 2 - 1] = -1;
		my[2 * x + i * 2] = 1;
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
			if (sum >= x + y && sum % 2 == (x + y) % 2 && (sum - x - y) / 2 <= n) {
				break;
			}
		}
		mx.clear();
		my.clear();
		solve(n, sum, x, y, mx, my);
		printf("Case #%d: ", t);
		int xx = 0, yy = 0;
		for (int i = 1; i <= 2 * x + 2 * y; i++) {
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