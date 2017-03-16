#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <queue>
#include <map>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;
typedef long long ll;

const int MAX_N = 211;
const int MOD = 1000000007;
char s[MAX_N][MAX_N];
int n, d[26][4];

ll fac[MAX_N];

int cmp(const void* a, const void* b)
{
	return strcmp((char *)a, (char *)b);
}

bool has(int i, char x)
{
	int n = strlen(s[i]);
	for (int j = 0; j < n; j++)
	{
		if (x == s[i][j])
		{
			return true;
		}
	}
	return false;
}

bool isAll(int i, char x)
{
	int n = strlen(s[i]);
	for (int j = 0; j < n; j++)
	{
		if (x != s[i][j])
		{
			return false;
		}
	}
	return true;
}

bool isPre(int i, char x)
{
	int n = strlen(s[i]);
	int m;
	for (int j = 0; j < n; j++)
	{
		if (x != s[i][j])
		{
			m = j;
			break;
		}
	}
	for (; m < n; m++)
	{
		if (x == s[i][m])
		{
			return false;
		}
	}
	return true;
}

bool isLast(int i, char x)
{
	int n = strlen(s[i]);
	int m;
	for (int j = n - 1; j >= 0; j--)
	{
		if (x != s[i][j])
		{
			m = j;
			break;
		}
	}
	for (; m >= 0; m--)
	{
		if (x == s[i][m])
		{
			return false;
		}
	}
	return true;
}

bool isMid(int i, char x)
{
	int n = strlen(s[i]);
	int m;
	for (int j = 0; j < n; j++)
	{
		if (x == s[i][j])
		{
			m = j;
			break;
		}
	}
	for (int j = m; j < n; j++)
	{
		if (x != s[i][j])
		{
			m = j;
			break;
		}
	}
	for (int j = m; j < n; j++)
	{
		if (x == s[i][j])
		{
			return false;
		}
	}
	return true;
}

int main() 
{
	fac[0] = 1;
	for (int i = 1; i < MAX_N; i++) 
	{
		fac[i] = fac[i - 1] * i % MOD;
	}
	int n_case = 0;
	scanf("%d", &n_case);
	for (int ca = 1; ca <= n_case; ca++) 
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%s", s[i]);
		}
		ll ans = 1;
		fill(d[0], d[26], 0);
		for (char x = 'a'; x <= 'z'; x++)
		{
			for (int i = 0; i < n; i++)
			{
				if (!has(i, x))
				{
					continue;
				}
				if (isAll(i, x))
				{
					d[x - 'a'][0]++;
				}
				else if (isPre(i, x))
				{
					d[x - 'a'][1]++;
				}
				else if (isLast(i, x))
				{
					d[x - 'a'][2]++;
				}
				else if (isMid(i, x))
				{
					d[x - 'a'][3]++;
				}
				else 
				{
					ans = 0;
				}
			}
		}
		int jhaspre = 0, jhaslast = 0, jhasall = 0;
		for (char x = 'a'; x <= 'z'; x++)
		{
			if (d[x - 'a'][1] > 1 || d[x - 'a'][2] > 1 || d[x - 'a'][3] > 1)
			{
				ans = 0;
			}
			else if (d[x - 'a'][3] == 1)
			{
				if (d[x - 'a'][0] || d[x - 'a'][1] || d[x - 'a'][2])
				{
					ans = 0;
				}
			}
			else
			{
				ans = ans * fac[d[x - 'a'][0]] % MOD;
			}

			if (d[x - 'a'][1] == 0 && d[x - 'a'][2] == 0 && d[x - 'a'][0])
			{
				jhasall++;
			}
			else if (d[x - 'a'][1] && d[x - 'a'][2] == 0)
			{
				jhaspre++;
			}
			else if (d[x - 'a'][1] == 0 && d[x - 'a'][2])
			{
				jhaslast++;
			}
		}

		if (jhaspre + jhasall == 0)
		{
			ans = 0;
		}
		else
		{
			ans = ans * fac[jhaspre + jhasall] % MOD;
		}
		
		printf("Case #%d: %lld\n", ca, ans);
	}
	return 0;
}
