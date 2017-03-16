#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<queue>
#include<stack>
#include<vector>
using namespace std;

const int f[4][4] = 
{
	{0, 1, 2, 3},
	{1, 0, 3, 2},
	{2, 3, 0, 1},
	{3, 2, 1, 0}
};

const int g[4][4] =
{
	{0, 0, 0, 0},
	{0, 1, 0, 1},
	{0, 1, 1, 0},
	{0, 0, 1, 1}
};

const int maxn = 100100;
char s[maxn];
int T;

int main()
{
  freopen("text.in","r",stdin);
  freopen("text.out","w",stdout);
  cin >> T;
  for (int t=1; t<=T; t++)
  	{
  		long long n, X;
			cin >> n >> X;
			scanf ("%s", s);
			for (int i=0; i<n; i++) s[i] -= 'h';
			for (int i=n; i<10*n; i++) s[i] = s[i-n];
			int now = 0, sign = 0, NOW = 0, SIGN = 0;
			for (int i=0; i<n; i++)
				sign ^= g[now][s[i]], now = f[now][s[i]];
			for (int i=0; i<X%4; i++)
				SIGN ^= sign^g[NOW][now], NOW = f[NOW][now];
			if (SIGN == 0 || NOW != 0)
				{
					printf ("Case #%d: NO\n", t);
					continue;
				}
			int a = -1, b = -1;
			now = 0, sign = 0;
			for (int i=0; i<10*n; i++)
				{
					sign ^= g[now][s[i]], now = f[now][s[i]];
					if (sign == 0 && now == 1) { a = i+1; break; }
				}
			now = 0, sign = 0;
			for (int i=10*n-1; i>=0; i--)
				{
					sign ^= g[s[i]][now], now = f[s[i]][now];
					if (sign == 0 && now == 3) { b = 10*n-i; break; }
				}
			if (a > 0 && b > 0 && a+b < n*X)
				printf ("Case #%d: YES\n", t);
			else
				printf ("Case #%d: NO\n", t);
		}
	return 0;
}

