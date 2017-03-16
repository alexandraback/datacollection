#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
using namespace std;

const int maxn = 5100000;

int tt, n;
bool p;
int f[25], h[maxn];
vector<int> g[maxn];

void work(){
	for (int i = 0; i < (1 << n); i++) {
		for (int j = 0; j < n; j++) 
			if (!(i & (1 << j))) {
				h[i + (1 << j)] = f[j] + h[i];
			}
	}
	for (int i = 1; i < (1 << n); i++) 
		g[h[i]].push_back(i);
	for (int i = 1; i < (1 << n); i++) {
		for (int j = 0; j < g[h[i]].size(); j++) {
			for (int k = j + 1; k < g[h[i]].size(); k++) {
				if (!(g[h[i]][j] & g[h[i]][k])) {
					bool q = false;
					for (int l = 0; l < n; l++) {
						if (g[h[i]][j] & (1 << l)) {
							if (q) printf(" ");
							q = true;
							printf("%d", f[l]);
						}
					}
					printf("\n");
					q = false;
					for (int l = 0; l < n; l++) {
						if (g[h[i]][k] & (1 << l)) {
							if (q) printf(" ");
							q = true;
							printf("%d", f[l]);
						}
					}
					printf("\n");
					p = true;
					return;	
				}
			}
		}
	}
}

int main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	cin >> tt;
	for (int t = 1; t <= tt; t++) {
		scanf("%d", &n);
		memset(g, 0, sizeof(g));
		for (int i = 0; i < n; i++)
			scanf("%d", &f[i]);
		printf("Case #%d:\n", t);
		p = false;
		work();
		if (!p)
			printf("Impossible\n");
	}
	return 0;
}

