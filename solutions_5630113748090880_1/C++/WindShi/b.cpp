#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int test, n, f[2501];
 
int main() {
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	scanf("%d", &test);
	for (int uu = 1; uu <= test; uu++) {
		memset(f, 0, sizeof(f));
		scanf("%d", &n);
		for (int i = 1; i < n + n; i++) 
			for (int j = 1; j <= n; j++) {
				int x;
				scanf("%d", &x);
				++f[x];
			}
		printf("Case #%d:", uu);
		for (int i = 1; i <= 2500; i++)
			if (f[i] & 1) printf(" %d", i);
		printf("\n");
	}
}
 
