#include <iostream>
#include <cstdio>
#include <cmath>
#include <string.h>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;
//char s[1000];
int a[200][200], n, m;
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int test;
	scanf("%d", &test);
	for (int tt = 1; tt <= test; tt++) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				scanf("%d", &a[i][j]);
			}
		}
		bool ans = true;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				bool u1 = true, u2 = true;	
				for (int l = 1; l <= m; l++) {
					if (a[i][l] > a[i][j]) u1 = false;
				}
				for (int l = 1; l <= n; l++) {
					if (a[l][j] > a[i][j]) u2 = false;
				}
				if (!u1 && !u2) ans = false;
			}
		}
		printf("Case #%d: ", tt);
		if (ans) printf("YES"); else printf("NO");
		printf("\n");
	}
	
	return 0;
}
