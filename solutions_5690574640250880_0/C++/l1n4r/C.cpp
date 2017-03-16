
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cstring>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <memory.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;

bool find(const int r, const int c, const int m, const int a, const int b, const int d, vii& p)
{
	if (!m)
	{
		if (d!=r-1)
		{
			if (d==r)
			{
				if (r == 1)
				{
					return true;
				}
				else if ((b==1&&a==c-1) || (b>1&&a!=c-1))
				{
					return true;
				}
			}
			else
			{
				return true;
			}
		}
		return false;
	}

	for (int i = 1; i < a; i++)
	{
		if (i != c-1 || b == r-1)
		{
			for (int j = 1; j <= r-d; j++)
			{
				if (i*j <= m)
				{
					if (find(r, c, m - i*j, i, j, d+j, p))
					{
						p.push_back(make_pair(i,d+j));
						return true;
					}
				}
			}
		}
	}

	return false;
}

bool find(const int r, const int c, const int m, vii& p)
{
	for (int a = 1; a <= c; a++)
	{
		if (a != c-1 || r == 1)
		{
			for (int b = 1; b <= r; b++)
			{
				if (a*b <= m)
				{
					if (find(r, c, m - a*b, a, b, b, p))
					{
						p.push_back(make_pair(a,b));
						return true;
					}
				}
			}
		}
	}
	return false;
}

char b[64][64];

void solve(const int r, const int c, const int m)
{
	vii p;

	bool possible = false;

	if (r*c - m >= 1)
	{
		memset(b, '.', sizeof(b));

		if (m)
		{
			if (find(r, c, m, p))
			{
				for (int k = 0; k < p.size(); k++)
				{
					for (int j = 0; j < p[k].first; j++)
					{
						for (int i = 0; i < p[k].second; i++)
						{
							b[i][j] = '*';
						}
					}
				}
				possible = true;
			}
			else if (r != c && find(c, r, m, p))
			{
				for (int k = 0; k < p.size(); k++)
				{
					for (int i = 0; i < p[k].first; i++)
					{
						for (int j = 0; j < p[k].second; j++)
						{
							b[i][j] = '*';
						}
					}
				}
				possible = true;
			}
		}
		else
		{
			possible = true;
		}
	}

	if (!possible)
	{
		printf("Impossible\n");
	}
	else
	{
		b[r-1][c-1] = 'c';
		for (int i = 0; i < r; i++)
		{
			b[i][c] = '\0';
			printf("%s\n", b[i]);
		}
	}
}

int main()
{
	string name = "C-small";
	string path = "";

	freopen((path + name + ".in").c_str(), "r", stdin);
	freopen((name + ".out").c_str(), "w", stdout);

	int test_cases;
	scanf("%d", &test_cases);

	for (int test_case = 1; test_case <= test_cases; test_case++)
	{
		int r, c, m;
		scanf("%d %d %d", &r, &c, &m);

		//printf("Case #%d: (%d %d %d)\n", test_case, r, c, m);
		printf("Case #%d:\n", test_case);

		solve(r, c, m);
	}

	fclose(stdout);
	fclose(stdin);

	return 0;
}
