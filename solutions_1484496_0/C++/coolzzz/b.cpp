#include <stdio.h>
#include <algorithm>
using namespace std;

int cs, ct;
int n, m;
int a[20];
struct B {
	int i;
	int s;
	bool operator < (const B &o) const {
		return s < o.s;
	}
} b[1 << 20];

int obit(int x)
{
	int i;
	bool f = false;
	for (i = 0; i < n; i++) {
		if (x & 1) {
			if (f) printf(" ");
			printf("%d", a[i]);
			f = true;
		}
		x >>= 1;
	}
	printf("\n");
}

bool check(int x, int y)
{
	int i, j;
	for (i = x; i < y; i++)
	for (j = i + 1; j <= y; j++)
	if ((b[i].i & b[j].i) == 0) {
		obit(b[i].i);
		obit(b[j].i);
		return true;
	}
	return false;
}

int main()
{
	int i, j, k, s;
	scanf("%d", &cs);
	for (ct = 1; ct <= cs; ct++) {
		scanf("%d", &n);
		for (i = 0; i < n; i++)
			scanf("%d", &a[i]);
		m = 1 << n;
		for (i = 1; i < m; i++) {
			k = i;
			s = 0;
			for (j = 0; j < n; j++) {
				if (k & 1) s += a[j];
				k >>= 1;
			}
			b[i].i = i;
			b[i].s = s;
		}
		sort(b, b + m);
		printf("Case #%d:\n", ct);
		bool succ = false;
		k = 0;
		for (i = 1; i <= m; i++)
		if (i == m || b[i].s != b[k].s) {
			if (check(k, i - 1)) {
				succ = true;
				break;
			}
			k = i;
		}
		if (!succ) printf("Impossible\n");
	}	
	return 0;
}
