#include <cstdio>
#include <algorithm>
using namespace std;
#define coder 100

int n, s, p;
int total[coder];

int satis(int ix)
{
	int q;
	int r = (total[ix] + 2) / 3;
	if (r >= p) return 1;
	if (s) {
		if (total[ix] > 1) q = (total[ix] + 4) / 3;
		else q = total[ix];
		--s;
		if (q >= p) return 1;
	}
	return 0;
}

bool cmp(int a, int b)
{
	return a > b ? 1 : 0;
}

int theMax()
{
	int i, cnt = 0;
	sort(total, total + n, cmp);
	for (i = 0; i < n; ++i)
		if (satis(i)) ++cnt;
	return cnt;
}

int main()
{
	FILE *fin = fopen("B-large.in.txt", "r");
	FILE *fout = fopen("blout.txt", "w");
	
	int i, c, t;
	fscanf(fin, "%d", &t);
	for (c = 1; c <= t; ++c) {
		fscanf(fin, "%d%d%d", &n, &s, &p);
		for (i = 0; i < n; ++i)
			fscanf(fin, "%d", &total[i]);
		fprintf(fout, "Case #%d: %d\n", c, theMax());
	}
	return 0;
}
