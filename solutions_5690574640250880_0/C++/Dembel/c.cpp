#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <cstdarg>

#define clr(a) memset(a, 0, sizeof(a))
#define fill(a, b) memset(a b, sizeof(a))

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int,int> pii;

using namespace std;

#define DBG2 1

void dbg(const char * fmt, ...)
{
#ifdef DBG1
#if DBG2
	FILE* file = stderr;
	va_list args;
	va_start(args, fmt);
	vfprintf(file, fmt, args);
	va_end(args);

	fflush(file);
#endif
#endif
}

vector < vector <char> > solve(int n, int m, int k)
{
	if (k == 1)
	{
		vector < vector <char> > res(n, vector <char>(m, '*'));
		res[0][0] = 'c';
		return res;	
	}
	else if (n > m)
	{
		vector < vector <char> > transRes = solve(m, n, k);
		if (transRes.empty())
			return transRes;
		vector < vector <char> > res(n, vector <char>(m));
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				res[i][j] = transRes[j][i];
		return res;
	}
	else if (n == 1)
	{
		vector < vector <char> > res(1, vector <char>(m, '*'));
		res[0][0] = 'c';
		for (int i = 1; i < k; ++i)
			res[0][i] = '.';
		return res;
	}
	else if (n == 2)
	{
		if (k % 2 == 1 || k == 2)
			return vector < vector <char> >(0);
		else
		{
			vector < vector <char> > res(2, vector <char>(m, '*'));
			for (int i = 0; i * 2 < k; ++i)
				res[0][i] = res[1][i] = '.';
			res[0][0] = 'c';
			return res;
		}
	}
	else
	{
		if (k == 2 || k == 3 || k == 5 || k == 7)
			return vector < vector <char> >(0);
		else
		{
			vector < vector <char> > res(n, vector <char>(m, '*'));
			if (k % 2 == 0)
			{
				res[0][0] = 'c';
				res[0][1] = res[1][0] = res[1][1] = '.';
				int cnt = 4;
				for (int i = 2; cnt < k && i < m; ++i, cnt += 2)
					res[0][i] = res[1][i] = '.';
				for (int i = 2; cnt < k && i < n; ++i)
				{
					for (int j = 0; cnt < k && j + 1 < m; j += 2, cnt += 2)
						res[i][j] = res[i][j + 1] = '.';
					if (i % 2 == 1 && m % 2 == 1 && cnt < k)
					{
						cnt += 2;
						res[i - 1][m - 1] = res[i][m - 1] = '.';
					}
				}
			}          
			else
			{
				for (int i = 0; i < 3; ++i)
					for (int j = 0; j < 3; ++j)
						res[i][j] = '.';
				res[0][0] = 'c';
				int cnt = 9;
				int mAdd = m;
				if (m % 2 == 0)
					--m;
				for (int i = 3; cnt < k && i < m; ++i, cnt += 2)
					res[0][i] = res[1][i] = '.';
				for (int i = 3; cnt < k && i + 1 < m; i += 2, cnt += 2)
					res[2][i] = res[2][i + 1] = '.';
				for (int i = 3; cnt < k && i < n; ++i)
				{
					for (int j = 0; cnt < k && j + 1 < m; j += 2, cnt += 2)
						res[i][j] = res[i][j + 1] = '.';
					if (i % 2 == 0 && m % 2 == 1 && cnt < k)
					{
						cnt += 2;
						res[i - 1][m - 1] = res[i][m - 1] = '.';
					}
				}
				if (mAdd != m)
				{
					for (int i = 1; cnt < k && i + 1 < n; i += 2, cnt += 2)
						res[i - 1][mAdd - 1] = res[i][mAdd - 1] = '.';
					if (cnt < k)
					{
						res[n - 1][mAdd - 2] = res[n - 2][mAdd - 1] = '.';
						cnt += 2;
					}
				}
			}
			return res;
		}
	}
}

void solve()
{
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	k = n * m - k;
	vector < vector <char> > res = solve(n, m, k);
	if (res.empty())
		printf("Impossible\n");
	else
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
				printf("%c", res[i][j]);
			printf("\n");
		}	
	}
}

int main()
{
#ifdef DBG1
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
	freopen(".err", "w", stderr);
#endif

	int tt;
	scanf("%d", &tt);
	for (int ii = 1; ii <= tt; ++ii)
	{
		printf("Case #%d:\n", ii);
		solve();
	}

	return 0;
}
