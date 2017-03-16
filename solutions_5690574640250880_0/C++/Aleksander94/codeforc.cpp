#include <iostream> 
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <iomanip>
#include <cmath>
#include <math.h>
#define int64 long long
#define ld long double
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define repd(i,a,b) for (int i = a; i >= b; i--)
#define mp make_pair

using namespace std;

const int N = 300000;
const int inf = 1000000000;


char a[300][300], a1[300][300];
bool used[300][300];



void dfs(int i, int j, int n, int m)
{
	used[i][j] = true;
	int k = 0;
	rep(ii,-1,1)
		rep(ii,-1,1)
		rep(jj,-1,1)
			if (i != 0 && j != 0 && i + ii > 0 && i + ii <= n && j + jj > 0 
				&& j + jj <= m && a[i + ii][j + jj] == '*') k++;
	if (k > 0) return;
	rep(ii,-1,1)
		rep(jj,-1,1)
			if (i != 0 && j != 0 && i + ii > 0 && i + ii <= n && j + jj > 0 
				&& j + jj <= m && a[i + ii][j + jj] != '*' && !used[i + ii][j + jj]) dfs(i + ii, j + jj, n, m);
}

void fill(int n, int m, int first, int second, int k)
{
	int rest = n * m - k;
	rep(i,1,n)
		rep(j,1,m) a[i][j] = '*';
	if (n == 1)
	{
		rep(i,1,rest) a[1][i] = '.';
		a[1][1] = 'c';
		return;
	}
	if (m == 1)
	{
		rep(i,1,rest) a[i][1] = '.';
		a[1][1] = 'c';
		return;
	}
	rep(i,1,first) 
	{
		if (!rest) break;
		a[1][i] = '.';
		rest--;
	}
	rep(i,1,second)
	{
		if (!rest) break;
		a[2][i] = '.';
		rest--;
	}
	rep(i,3,n)
		rep(j,1,2)
		{
			if (j == 1 && rest == 1) break;
			if (!rest) break;
			a[i][j] = '.';
			rest--;
		}
	rep(i,3,n)
		rep(j,1,second)
		{
			if (!rest) break;
			if (a[i][j] == '*')
			{
				rest--;
				a[i][j] = '.';
			}
		}
	if (rest)
	{
		rep(i,1,n)
			rep(j,1,m)
			{
				if (!rest) break;
				if (a[i][j] == '*')
				{
					rest--;
					a[i][j] = '.';
				}
			}
	}
	a[1][1] = 'c';
}

bool check(int n, int m)
{
	rep(i,1,n)
		rep(j,1,m) used[i][j] = false;
	dfs(1, 1, n, m);
	rep(i,1,n)
		rep(j,1,m)
			if (a[i][j] != '*' && !used[i][j]) return false;
	return true;
}

bool solve(int n, int m, int k)
{
	if (n == 1 || m == 1)
	{
		fill(n, m, 1, 1, k);
		return true;
	}
	int rest = n * m - k;
	rep(i,1,50)
	{
		if (i > m) continue;
		if (i > rest) continue;
		fill(n, m, i, min(i, rest - i), k);
		if (check(n, m)) return true;
	}
	return false;
}

void reverse(int &n, int &m)
{
	rep(i,1,m)
		rep(j,1,n) a1[j][i] = a[i][j];
	swap(n, m);
	rep(i,1,n)
		rep(j,1,m) a[i][j] = a1[i][j];
}

void print(int n, int m)
{
	rep(i,1,n)
	{
		rep(j,1,m) printf("%c", a[i][j]);
		if (i != n) printf("\n");
	}
}

int main()
{
/*#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif*/
//#ifndef _DEBUG
	freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);
//#endif
	int q;
	scanf("%d", &q);
	rep(ii,1,q)
	{
		int n, m, k;
		scanf("%d%d%d", &n, &m, &k);
		printf("Case #%d:\n", ii);
		if (solve(n, m, k)) print(n, m);
		else 
		{
			swap(n, m);
			if (solve(n, m, k))
			{
				reverse(n, m);
				print(n, m);
			}
			else printf("Impossible");
		}
		if (ii != q) printf("\n");
	}
	return 0;
}