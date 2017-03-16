#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int r, n, m, K;
int c[10];
int data[15];

void work()
{
	memset(c, 0, sizeof(c));
	for (int i = 0; i < K; ++i) {
		scanf("%d", &data[i]);
		int x = data[i];
		for (int p = 2; p <= m; ++p) if (x % p == 0) {
			int curc = 0;
			while (x % p == 0) {
				x /= p;
				++curc;
			}
			c[p] = max(c[p], curc);
		}
	}
	int sumc = 0;
	for (int i = 2; i <= m; ++i) sumc += c[i];
	c[4] = sumc - n;
	c[2] -= c[4] * 2;
	if (c[2] >= 0 && c[4] >= 0) 
		for (int i = 2; i <= m; ++i) for (int j = 0; j < c[i]; ++j) printf("%d", i);
	else
		for (int i = 1; i <= n; ++i) printf("2");
	printf("\n");

}
int main()
{
	freopen("C-small-1-attempt0.in", "r", stdin);
	freopen("C.out", "w", stdout);
	printf("Case #1:\n");
	scanf("%*d");
	scanf("%d%d%d%d", &r, &n, &m, &K);
	for (int t = 0; t < r; ++t) work();
}


