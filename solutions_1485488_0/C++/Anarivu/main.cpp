#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<math.h>
using namespace std;



struct pr
{
	int x, y;
	pr(int xe = 0, int ye = 0)
	{
		x = xe;
		y = ye;
	}
};



int f[105][105];
int c[105][105];
double a[105][105];
int h, n, m;
int stp[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};

bool u[105][105];

double eps = 0.000000001;

double check(pr fr, pr to)
{
	double tm = a[fr.x][fr.y];
	double hm = h - 10 * tm;
	if(c[to.x][to.y] - f[fr.x][fr.y] < 50 || c[fr.x][fr.y] - f[to.x][to.y] < 50)
		return -1;
	
	if(c[to.x][to.y] - 50 < hm)
	{
		tm += (hm - (c[to.x][to.y] - 50)) / 10.0;
		hm = c[to.x][to.y] - 50;
	}

	if(tm == 0)
		return 0;

	if(f[fr.x][fr.y] + 20 <= hm)
		tm += 1;
	else
		tm += 10;
	return tm;
}

int main()
{
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);

	int tt;
	scanf("%d", &tt);

	for(int t = 0; t < tt; t++)
	{
		scanf("%d", &h);
		scanf("%d%d", &n, &m);

		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				scanf("%d", &c[i][j]);
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				scanf("%d", &f[i][j]);

		for(int i = 0; i < 105; i++)
		{
			memset(u[i], 0, 105 * sizeof(bool));
			for(int j = 0; j < m; j++)
				a[i][j] = -1;
		}

		queue<pr> q;
		q.push(pr(0, 0));
		a[0][0] = 0;

		while(!q.empty())
		{
			pr p = q.front();
			q.pop();
			if(u[p.x][p.y])
				continue;
			u[p.x][p.y] = 1;

			for(int i = 0; i < 4; i++)
			{
				if(p.x + stp[i][0] >= 0 && p.x + stp[i][0] < n && 
					p.y + stp[i][1] >= 0 && p.y + stp[i][1] < m)
				{
					double tm = check(p, pr(p.x + stp[i][0], p.y + stp[i][1]));
					if(tm >= a[p.x][p.y] && 
						(a[p.x + stp[i][0]][p.y + stp[i][1]] < 0 ||
						a[p.x + stp[i][0]][p.y + stp[i][1]] > tm))
					{
						u[p.x + stp[i][0]][p.y + stp[i][1]] = 0;
						q.push(pr(p.x + stp[i][0], p.y + stp[i][1]));
						a[p.x + stp[i][0]][p.y + stp[i][1]] = tm;
					}
				}
			}
			
		}

		printf("Case #%d: %.8lf\n", t+1, a[n-1][m-1]);
	}
	

	return 0;
}


