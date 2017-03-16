#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

#define FF(i, a, b) for (int i=a; i<=b; i++)
#define FI(i, a, b) for (int i=a; i>=b; i--)
#define MS(f, x) memset(f, x, sizeof(f))
#define INF 1 << 30
#define MAXN 200

using namespace std;

const int fi[] = {1, 0, -1, 0};
const int fj[] = {0, 1, 0, -1};

double dis[MAXN][MAXN];
bool used[MAXN][MAXN];
int c[MAXN][MAXN], f[MAXN][MAXN];
int H, n, m;
int qi[1000000], qj[1000000];

double calc(double c1, double f1, double c2, double f2, double ti)
{
	double w = H - 10 * ti;
	if (f1 + 50 > c2 || f2 + 50 > c2 || f2 + 50 > c1)
		return INF;
	if (w + 50 <= c2)
		return 0;
	return (w + 50 - c2) / 10;
}

bool equ(double a, double b)
{
	if (a - b < 1e-8 && b - a < 1e-8) return true;
	return false;
}

double pas(double f, double ti)
{
	double w = H - 10 * ti - f;
	if (w >= 20)
		return 1;
	else
		return 10;
}

int main()
{
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	
	int ttt;
	scanf("%d", &ttt);
	FF(tt, 1, ttt)
	{
		scanf("%d%d%d", &H, &n, &m);
		FF(i, 1, n)
			FF(j, 1, m)
				scanf("%d", &c[i][j]);
		FF(i, 1, n)
			FF(j, 1, m)
			{
				scanf("%d", &f[i][j]);
				dis[i][j] = INF;
			}
			
		dis[1][1] = 0;
		MS(used, 0);
		used[1][1] = 1;
		int h, t;
		qi[1] = 1; qj[1] = 1;
		h = t = 1;
		while (h <= t)
		{
			FF(i, 0, 3)
			{
				int x = qi[h] + fi[i], y = qj[h] + fj[i];
				if (1 <= x && x <= n && 1 <= y && y <= m)
				{
					double tmp1 = calc(c[qi[h]][qj[h]], f[qi[h]][qj[h]], c[x][y], f[x][y], 0);
					if (equ(tmp1, 0))
					{
						double tmp2 = 0;
						if (tmp2 < dis[x][y])
						{
							dis[x][y] = tmp2;
							if (!used[x][y])
							{
								used[x][y] = 1;
								qi[++t] = x;
								qj[t] = y;
							}
						}
					}
				}
			}
			
			used[qi[h]][qj[h]] = 0;
			h++;
		}
		
		h = 1; t = 0;
		MS(used, 0);
		FF(i, 1, n)
			FF(j, 1, m)
				if (dis[i][j] != INF)
				{
					qi[++t] = i;
					qj[t] = j;
					used[i][j] = 1;
				}		
		
		while (h <= t)
		{
			FF(i, 0, 3)
			{
				int x = qi[h] + fi[i], y = qj[h] + fj[i];
				if (1 <= x && x <= n && 1 <= y && y <= m)
				{
					double tmp1 = calc(c[qi[h]][qj[h]], f[qi[h]][qj[h]], c[x][y], f[x][y], dis[qi[h]][qj[h]]);
					if (!equ(tmp1, INF))
					{
						double tmp2 = dis[qi[h]][qj[h]] + tmp1 + pas(f[qi[h]][qj[h]], dis[qi[h]][qj[h]] + tmp1);
						if (tmp2 < dis[x][y])
						{
							dis[x][y] = tmp2;
							if (!used[x][y])
							{
								used[x][y] = 1;
								qi[++t] = x;
								qj[t] = y;
							}
						}
					}
				}
			}
			
			used[qi[h]][qj[h]] = 0;
			h++;
		}

		printf("Case #%d: %lf\n", tt, dis[n][m]);
	}
	
	return 0;
}
