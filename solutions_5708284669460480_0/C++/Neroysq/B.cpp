#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
const int nmax = 100 + 18;

int K, L, S, n, m;
int P[nmax], F[nmax][nmax];
double G[nmax][nmax];
double p[nmax][nmax];
bool ed[nmax][nmax];
char a[nmax], v[nmax];

void getNext(char *p, int *next)
{
	int j, k;
	next[1] = 0;
	for (int i = 2; i <= n; ++i) {
		j = next[i - 1];
		while (j && p[j + 1] != p[i])
			j = next[j];
		if (p[j + 1] == p[i])
			next[i] = ++j;
		else
			next[i] = 0;
	}
//	for (int i = 1; i < strlen(p + 1); ++i)
//		printf("N %d: %d\n", i, next[i]);
}

void update(int &a, int b)
{
	if (a == -1)
		a = b;
	else if (a < b)
		a = b;
}

int calcF()
{
	memset(F, -1, sizeof(F));
	F[0][0] = 0;
	for (int i = 0; i < S; ++i)
		for (int j = 0; j <= n; ++j)  
			if (F[i][j] != -1) {
				for (int k = 0; k < K; ++k) {
					int nj = j, nF = F[i][j];
					while (nj && v[k] != a[nj + 1])
						nj = P[nj];
					if (a[nj + 1] == v[k]) ++nj;
					if (nj == n)
						nj = P[nj], ++nF;
					update(F[i + 1][nj], nF);
				}
			}
	int rnt = 0;
	for (int j = 0; j <= n; ++j)
		update(rnt, F[S][j]);
	return rnt;
}

double calcG()
{
	memset(ed, 0, sizeof(ed));
	for (int i = 0; i <= S; ++i)
		for (int j = 0; j <= n; ++j)
			G[i][j] = p[i][j] = 0;
	ed[0][0] = 1;
	p[0][0] = 1;
	for (int i = 0; i < S; ++i)
		for (int j = 0; j <= n; ++j)  
			if (ed[i][j]) {
				for (int k = 0; k < K; ++k) {
					int nj = j;
					double nF = G[i][j];
					while (nj && v[k] != a[nj + 1])
						nj = P[nj];
					if (a[nj + 1] == v[k]) ++nj;
					if (nj == n) {
						nj = P[nj];
						nF += 1 * p[i][j];
					}
					G[i + 1][nj] += nF *1.0 / K;
					ed[i + 1][nj] = 1;
					p[i + 1][nj] += p[i][j] / K;
				}
			}
	double rnt = 0;
	for (int j = 0; j <= n; ++j)
		rnt += G[S][j];
	return rnt;
}

double solve()
{
	getNext(a, P);
	//printf("======\n");
	int FF = calcF();
	double GG = calcG();
//	printf("%s %d %.3f\n", a + 1, FF, GG);
	return FF - GG;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int cases = 1; cases <= T; ++cases) {
		scanf("%d%d%d%s%s", &K, &L, &S, v, a + 1);
		n = strlen(a + 1);
		m = strlen(v);
		printf("Case #%d: %.10f\n", cases, solve());
	}
	return 0;
}
