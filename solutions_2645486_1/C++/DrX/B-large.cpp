#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <list>
#include <set>
#include <map>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdio>

using namespace std;

const int N = 10011;

int sk[N], top;
int rt[N];

long long d[11][10];
long long v[N];
int n;
long long E, R;


long long DFS (int x, int y) {
	if (x == n + 1) return 0;
	if (d[x][y] != -1) return d[x][y];
	int i, j, k;
	long long ans = -1;
	for (k = 0; k <= y; ++k)
		ans = max(ans, k * v[x] + DFS(x+1, min(y - k + R, E)));
	return d[x][y] = ans;
}

int naive () {
	memset (d, -1, sizeof (d));
	return DFS (1, E);
}

int main () {
	int i, j, k, T, ca;
	scanf ("%d", &T);
	for (ca = 1; ca <= T; ++ca) {
		scanf ("%lld%lld%d", &E, &R, &n);
		sk[top = 0] = 1000001111;
		memset (rt, 0, sizeof (rt));
		for (i = 1; i <= n; ++i) {
			scanf ("%lld", &v[i]);
			while (top > 0 && v[i] > v[sk[top]]) {
				rt[sk[top]] = i;
				top--;
			}
			sk[++top] = i;
		}
		long long cur = E; long long ans = 0;
		if (R >= E) {
			for (i = 1; i <= n; ++i)
				ans += E * v[i];
		}
		else {
			for (i = 1; i <= n; ++i) {
				if (rt[i] == 0) {
					ans += cur * v[i];
					cur = R;
				}
				else {
					j = rt[i];
					if ((j - i) * R >= E) {
						ans += cur * v[i];
						cur = R;
					}
					else if (cur + (j - i) * R >= E) {
						ans += (cur + (j - i) * R - E) * v[i];
						cur = E;
						i = j - 1;
					}
					else {
						cur += (j - i) * R;
						i = j - 1;
					}
				}
			}
		}
		printf ("Case #%d: %Ld\n", ca, ans);
	}
	return 0;
}
