#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 60;

char ans[maxn][maxn];
int R, C, M, n, q;
bool transposed;

void transpose()
{
	for (int i = 0; i < R; i++)
		for (int j = i; j < C; j++)
			swap(ans[i][j], ans[j][i]);
	swap(R, C);
}

void getdecom()
{
	n = (R*C - M) / R;
	q = (R*C - M) % R;
}

void gettranspose()
{
	if (R > C)
	{
		swap(R, C);
		transposed = true;
	}
	else transposed = false;
}

bool caseR1()
{
	for (int i = 0; i < M; i++) ans[0][i] = '*';
	for (int i = M; i < C; i++) ans[0][i] = '.';
	ans[0][C-1] = 'c';
	return true;
}

bool caseR2()
{
	if (M & 1) return false;
	if (R*C - M <= 2) return false;
	int emp = (R*C - M) / 2;
	for (int i = 0; i < emp; i++) ans[0][i] = ans[1][i] = '.';
	for (int i = emp; i < C; i++) ans[0][i] = ans[1][i] = '*';
	ans[0][0] = 'c';
	return true;
}

bool casen1M8()
{
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			ans[i][j] = '*';
	for (int i = 0; i < 3; i++) ans[0][i] = ans[1][i] = '.';
	int emp = R*C - M;
	int r = (emp - 2) / 2;
	for (int i = 2; i < r; i++) ans[i][0] = ans[i][1] = '.';
	if (emp & 1) ans[2][2] = '.';
	ans[0][0] = 'c';
	return true;
}

bool caseM6()
{
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			ans[i][j] = '*';
	for (int i = 0; i < 3; i++) ans[i][0] = ans[i][1] = '.';
	ans[0][0] = 'c';
	return true;
}

bool caseM4()
{
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			ans[i][j] = '*';
	ans[0][1] = ans[1][0] = ans[1][1] = '.';
	ans[0][0] = 'c';
	return true;
}

bool caseM1()
{
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			ans[i][j] = '*';
	ans[0][0] = 'c';
	return true;
}

bool casen1()
{
	int emp = R*C - M;
	if (emp >= 8) return casen1M8();
	else if (emp == 1) return caseM1();
	else if (emp == 4) return caseM4();
	else if (emp == 6) return caseM6();
	else return false;
}

bool caseR3()
{
	return false;
}

bool caseq1n2()
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < n; j++) ans[i][j] = '.';
		for (int j = n; j < C; j++) ans[i][j] = '*';
	}
	ans[0][n] = ans[1][n] = ans[2][n] = '.';
	ans[R-1][0] = ans[R-1][1] = '*';
	ans[0][0] = 'c';
	return true;
}

bool caseq1n3()
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < n; j++) ans[i][j] = '.';
		for (int j = n; j < C; j++) ans[i][j] = '*';
	}
	ans[0][n] = ans[1][n] = '.';
	ans[R-1][n-1] = '*';
	ans[0][0] = 'c';
	return true;
}

bool caseq1()
{
	if (n <= 2)
		if (R == 3) return caseR3();
		else return caseq1n2();
	else return caseq1n3();
}

bool casedefault()
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < n; j++) ans[i][j] = '.';
		for (int j = n; j < C; j++) ans[i][j] = '*';
	}
	for (int i = 0; i < q; i++) ans[i][n] = '.';
	ans[0][0] = 'c';
	return true;
}

bool construct()
{
	if (R*C - M == 1) return caseM1();
	else if (R == 1) return caseR1();
	else if (R == 2) return caseR2();
	else if (n <= 1) return casen1();
	else if (q == 1) return caseq1();
	else return casedefault();
}

bool work()
{
	scanf("%d%d%d", &R, &C, &M);
	gettranspose();
	getdecom();
	bool res = construct();
	if (transposed) transpose();
	return res;
}

void printans()
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++) printf("%c", ans[i][j]);
		printf("\n");
	}
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++)
	{
		printf("Case #%d:\n", i);
		bool res = work();
		if (res) printans();
		else printf("Impossible\n");
	}
	
	return 0;
}

