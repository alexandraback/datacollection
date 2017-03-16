#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <cmath>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
#define MP make_pair
#define PB push_back

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
char s[] = "EWNS";

int d[205][205], px[205][205], py[205][205];
char c[205][205];

int qx[50000], qy[50000];

void put(int x, int y) {
	if (x == 102 && y == 102) return;
	put(px[x][y], py[x][y]);
	putchar(c[x][y]);
}

int main() {
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	int T, n;
	scanf("%d", &T);
	for (int t0 = 1; t0 <= T; ++t0) {
		int x0, y0;
		scanf("%d %d", &x0, &y0);
		x0 += 102; y0 += 102;
		qx[0] = 102; qy[0] = 102; d[102][102] = 1;
		int head = -1, tail = 0;
		while (head < tail && !d[x0][y0]) {
			++head;
			int x1 = qx[head], y1 = qy[head], x, y, p = d[x1][y1];
			for (int k = 0; k < 4; ++k) {
				x = x1 + dx[k] * p;
				y = y1 + dy[k] * p;
				if (x >= 0 && x <= 204 && y >= 0 && y <= 204 && !d[x][y]) {
					d[x][y] = p + 1;
					c[x][y] = s[k];
					px[x][y] = x1;
					py[x][y] = y1;
					++tail;
					qx[tail] = x;
					qy[tail] = y;
				}
			}
		}
		cout << "Case #" << t0 << ": ";
		put(x0, y0);
		cout << endl;
		memset(d, 0, sizeof(d));
	}
	return 0;
}
 
