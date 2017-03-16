#define _CRT_SECURE_NO_DEPRECATE
//#define _CRT_RAND_S

//#include <windows.h>
//#include <tchar.h>
//#include <atlbase.h>
//#include <winerror.h>

#include <stdint.h>
#include <climits>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <map>
#include <set>
#include <list>
#include <queue>
#include <deque>
#include <string>
#include <bitset>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

int gcd(int a, int b) {
	while (a != 0) { int r = b % a; b = a; a = r; }
	return (b);
}

char a[32][32];

map<pii, int> m;
void add(int x, int y, int r) {
	int d2 = x*x + y*y; if (d2 == 0 || d2 > r*r) return;
	int g = gcd(abs(x), abs(y));
	pii t(x / g, y / g);
	if (!m[t] || m[t] > d2) m[t] = d2;
}
int rect(int w, int h, int x, int y, int r) {
	m.clear();
	int u = 2 * (w - x) - 1;
	int v = 2 * (h - y) - 1;
	int kw = (r - 1) / (2 * w) + 1;
	int kh = (r - 1) / (2 * h) + 1;
	for (int i = -kw; i <= +kw; i++) {
		for (int j = -kh; j <= +kh; j++) {
			add(0 + 2 * w * i, 0 + 2 * h * j, r);
			add(0 + 2 * w * i, v + 2 * h * j, r);
			add(u + 2 * w * i, 0 + 2 * h * j, r);
			add(u + 2 * w * i, v + 2 * h * j, r);
		}
	}
	return m.size();
}

int main() {
	int T; scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		int h, w, d;
		scanf("%d %d %d", &h, &w, &d);
		for (int i = 0; i < h; i++)
			scanf("%s", a[i]);
		int x = 0, y = 0;
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				if (a[i][j] == 'X') y = i, x = j;
		int r = rect(w-2, h-2, x-1, y-1, d);
		printf("Case #%d: %d\n", t, r);
	}
	
	return 0;
}
