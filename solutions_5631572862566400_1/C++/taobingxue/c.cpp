#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int Times;
int n, p[1005];

int poi[1005], next[1005], son[1005];

int last[1005];

int ans;

int w(int now, int len, int nono) {
	int maxnow = len;
	int u = son[now];
	while (u != 0) {
		if (poi[u] != nono) {
			int ll = w(poi[u], len + 1, nono);
			if (ll > maxnow) maxnow = ll;
		}
		u = next[u];
	}
	return maxnow;	
}

int main() {

	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	
	scanf("%d", &Times);
	for (int times = 1; times <= Times; ++times) {
		printf("Case #%d: ", times);

		memset(son, 0, sizeof(son));
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &p[i]);
			p[i]--;
			
			poi[i+1] = i;
			next[i+1] = son[p[i]];
			son[p[i]] = i+1;
		}
		
		ans = 3;
		// circle
		memset(last, -1, sizeof(last));
		for (int i = 0; i < n; ++i) {
			if (last[i] >= 0) continue;
			int sss = 0, pp = i;
			while (last[pp] < 0) {
				sss++;
				last[pp] = i;
				pp = p[pp];
			}
			if (last[pp] != i) continue;

			int p3 = i;
			while (p3 != pp) {
				sss--;
				p3 = p[p3];
			}			
			if (sss > ans) ans = sss;
		}
		
		// parts
		int ans0 = 0;
		memset(last, -1, sizeof(last));		
		for (int i = 0; i < n; ++i) {
			if (p[p[i]] == i && last[i] < 0 && last[p[i]] < 0) {
				int l1 = w(i, 1, p[i]);
				int l2 = w(p[i], 1, i);
				last[i] = 0;
				last[p[i]] = 0;
				
				ans0 += l1 + l2;
			}
		}
		if (ans0 > ans) ans = ans0;
		
		printf("%d\n", ans);
	}
	
	return 0;
}
