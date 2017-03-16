#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

const int Maxn = 8;

int t;
int n, m;
string codes[Maxn];
int neigh[Maxn];
int par[Maxn];
string best;
string cur;

void Gen(int nums, int v, int taken, bool nw)
{
	/*printf("nums = %d, v = %d\n", nums, v);
	for (int i = 0; i < n; i++)
		if (taken & 1 << i) printf("%d ", i);
	printf("\n\n");*/
	if (nw) { taken |= 1 << v; cur += codes[v]; }
	if (best != "" && best < cur) { if (nw) cur.erase(cur.length() - 5, 5); return; }
	if (nums == n) best = cur;
	else for (int i = 0; i < n; i++) if (neigh[v] & 1 << i) {
			if (!(taken & 1 << i)) {
				par[i] = v; Gen(nums + 1, i, taken, true);
			}
		}
	if (par[v] != -1) Gen(nums, par[v], taken, false);
	if (nw) cur.erase(cur.length() - 5, 5);
}

int main()
{
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++) {
			cin >> codes[i];
			neigh[i] = 0;
		}
		while (m--) {
			int a, b; scanf("%d %d", &a, &b); a--; b--;
			neigh[a] |= 1 << b; neigh[b] |= 1 << a;
		}
		best = "";
		for (int i = 0; i < n; i++) {
			par[i] = -1;
			Gen(1, i, 0, true);
		}
		printf("Case #%d: %s\n", tc, best.c_str());
	}
	return 0;
}