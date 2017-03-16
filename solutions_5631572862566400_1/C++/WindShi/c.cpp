#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

struct node {
	node *next;
	int where;
} *first[1001], a[10001];
int test, n, f[1001], c[10001], l;
bool b[1001];

inline void makelist(int x, int y) {
	a[++l].where = y;
	a[l].next = first[x];
	first[x] = &a[l];
}

int calc(int x, int limit) {
	int will = 1;
	for (node *y = first[x]; y; y = y->next)
		if (y->where != limit) will = max(will, calc(y->where, limit) + 1);
	return will;
}
 
int main() {
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	scanf("%d", &test);
	for (int uu = 1; uu <= test; uu++) {
		scanf("%d", &n);
		memset(first, 0, sizeof(first)); l = 0; 
		for (int i = 1; i <= n; i++) scanf("%d", &f[i]), makelist(f[i], i);
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			int size = 1, j = f[i]; c[size] = 1;
			memset(b, false, sizeof(b)); b[i] = true; 
			for (; !b[j]; j = f[j]) b[j] = true, c[++size] = j;
			if (j == i) ans = max(ans, size);
			//if (j == c[size - 1]) ans = max(ans, size);
		}  
		int cir = 0;
		for (int i = 1; i <= n; i++)
			if (f[f[i]] == i) {
				cir += calc(i, f[i]) + calc(f[i], i);
			}
		cir /= 2;
		ans = max(cir, ans); 
		printf("Case #%d: %d\n", uu, ans);
	}
}
	 
