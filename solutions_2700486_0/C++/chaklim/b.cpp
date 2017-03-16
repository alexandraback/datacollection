#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;
typedef long long ll;

ll T, n, x, y, t, a;
const ll o = 500;
bool s[1010][1010];

void dfs(int k, int num) {
	if (k == n) {
		if (s[x+o][y])
			a += num;
		return;
	}
	int dx = o, dy = 500;
	while (dy >= 2 && !s[dx][dy - 2])
		dy -= 2;
	if (dy == 0 || (s[dx-1][dy-1] && s[dx+1][dy-1])) {
		s[dx][dy] = 1, dfs(k+1, num), s[dx][dy] = 0;
	}
	else if (s[dx+1][dy-1]) {
		while (dy >= 1 && !s[dx-1][dy-1])
			dx--, dy--;

		s[dx][dy] = 1, dfs(k+1, num), s[dx][dy] = 0;
	}
	else if (s[dx-1][dy-1]) {
		while (dy >= 1 && !s[dx+1][dy-1])
			dx++, dy--;
		
		s[dx][dy] = 1, dfs(k+1, num), s[dx][dy] = 0;
	}
	else {
		int tx = dx, ty = dy;

		while (dy >= 1 && !s[dx-1][dy-1])
			dx--, dy--;
		s[dx][dy] = 1, dfs(k+1, num/2), s[dx][dy] = 0;
		
		dx = tx, dy = ty;
		while (dy >= 1 && !s[dx+1][dy-1])
			dx++, dy--;
		s[dx][dy] = 1, dfs(k+1, num/2), s[dx][dy] = 0;
	}
}

int main() {
	cin >> T;

	int cn = 0;
	while (T--) {
		printf("Case #%d: ", ++cn);

		cin >> n >> x >> y;
		if (x < -500 || x > 500 || y > 500)
			cout << "0.0" << endl;
		else {
			a = 0;
			memset(s, 0, sizeof s);
			dfs(0, 1 << n);
			cout << (a+0.0) / ((1 << n)+0.0) << endl;
		}
	}	

	return 0;
}
