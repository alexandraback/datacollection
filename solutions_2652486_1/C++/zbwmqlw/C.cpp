#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#define pow(x) (1 << (x))
using namespace std;

int r, n, m, K;
int c[10];
int data[15];
int deco[15][10];
double C[40][40];

double evaluate(int *c)
{
	int d[10];
	double res = 1;
	for (int i = 0; i < K; ++i) {
		d[5] = deco[i][5];
		d[7] = deco[i][7];
		if (d[5] > c[5] || d[7] > c[7]) return 0;
		double curp = 0;
		for (d[6] = 0; d[6] <= c[6] && d[6] <= deco[i][2] && d[6] <= deco[i][3]; ++d[6])
			for (d[8] = 0; d[8] <= c[8] && d[8] * 3 + d[6] <= deco[i][2]; ++d[8])
				for (d[4] = 0; d[4] <= c[4] && d[8] * 3 + d[4] * 2 + d[6] <= deco[i][2]; ++d[4]) {
					d[2] = deco[i][2] - d[8] * 3 - d[4] * 2 - d[6];
					d[3] = deco[i][3] - d[6];
					if (d[2] < 0 || d[3] < 0 || d[2] > c[2] || d[3] > c[3]) continue;
					double curp2 = 1;
					for (int k = 2; k <= 8; ++k)
						curp2 *= (double)C[c[k]][d[k]] / pow(c[k]);
					curp += curp2;
				}
		res *= curp;
		if (res == 0) return 0;
	}
	return res;

}

void work()
{
	C[0][0] = 1;
	for (int i = 1; i < 40; ++i) {
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; ++j)
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
	}
	memset(c, 0, sizeof(c));
	memset(deco, 0, sizeof(deco));
	for (int i = 0; i < K; ++i) {
		scanf("%d", &data[i]);
		int x = data[i];
		for (int p = 2; p <= m; ++p) if (x % p == 0) {
			int curc = 0;
			while (x % p == 0) {
				x /= p;
				++deco[i][p];
				++curc;
			}
			c[p] = max(c[p], curc);
		}
	}
	double optv = 0;
	int optc[10];
	for (c[6] = 0; c[6] <= c[2] && c[6] <= c[3]; ++c[6]) for (c[8] = 0; c[8] * 3 + c[6] <= c[2]; ++c[8]) for (c[4] = 0; c[4] * 2 + c[8] * 3 + c[6] <= c[2]; ++c[4]) {
		c[2] -= c[6] + c[8] * 3 + c[4] * 2;
		c[3] -= c[6];
		int sumc = 0;
		for (int i = 2; i <= m; ++i) sumc += c[i];
		if (sumc == n) {
			double v = evaluate(c);
			if (v > optv) {
				optv = v;
				memcpy(optc, c, sizeof(optc));
			}
		}
		c[2] += c[6] + c[8] * 3 + c[4] * 2;
		c[3] += c[6];
	}
	//cout << optv << endl;
	if (optv == 0)
		for (int i = 1; i <= n; ++i) printf("2");
	else
		for (int i = 2; i <= 8; ++i) for (int j = 0; j < optc[i]; ++j) printf("%d", i);
	printf("\n");

}

int main()
{
	freopen("C-small-2-attempt1.in", "r", stdin);
	freopen("C_3.out", "w", stdout);
	printf("Case #1:\n");
	scanf("%*d");
	scanf("%d%d%d%d", &r, &n, &m, &K);
	for (int t = 0; t < r; ++t) work();
}


