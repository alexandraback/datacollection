#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1004;
int cs, n, cnt;
double a[maxn], b[maxn];
FILE *in, *out;

void solve() {
	sort(a, a+n);
	sort(b, b+n);
	int i, j, x, y;
	cnt = 0;
	for (i=n-1, j=n-1, x=0, y=0; x <= i; ) {
		if (a[i] < b[j]) { x++; j--; }
		else { cnt++; i--; j--; }
	}
	fprintf(out, "%d ", cnt);

	j = 0;
	cnt = n;
	for (i=0; i < n; i++) {
		while (j < n && b[j] < a[i]) j++;
		if (j < n) { j++; cnt--; }
	}
	fprintf(out, "%d\n", cnt);
}

int main()
{
	int T;
	in = fopen("in.txt", "r");
	out = fopen("out.txt", "w");
	fscanf(in, "%d", &T);
	for (cs=1; cs <= T; cs++) {
		fscanf(in, "%d", &n);
		for (int i=0; i < n; i++) fscanf(in, "%lf", &a[i]);
		for (int i=0; i < n; i++) fscanf(in, "%lf", &b[i]);
		fprintf(out, "Case #%d: ", cs);
		solve();
	}
	return 0;
}
