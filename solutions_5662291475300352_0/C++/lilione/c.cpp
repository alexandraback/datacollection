#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<cmath>
#include<cctype>
#include<ctime>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<cassert>
#include<bitset>

using namespace std;

const int lim = 1e6;

int d[lim], h[lim], m[lim];
struct node {
	int x, y;
} a[lim];

int main() {
	freopen("c.out", "w", stdout);
	int TT;
	scanf("%d", &TT);
	for (int s = 1; s <= TT; s++) {
		int n;
		scanf("%d", &n);
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d%d%d", &d[i], &h[i], &m[i]);
			for (int j = 1; j <= h[i]; j++) {
				a[++cnt].x = d[i];
				a[cnt].y = m[i] + j - 1;
			}
		}
		int ans = 0;
		if (cnt != 1) {
			if (a[2].y > a[1].y) swap(a[1], a[2]);
			if (a[1].y == a[2].y) ans = 0;
			else {
				if ((long long) (360 - a[1].x) * a[1].y >= (long long) (360 - a[2].x + 360) * a[2].y) ans = 1;
			} 
		}
		printf("Case #%d: %d\n", s, ans);
	}
	return 0;
}

