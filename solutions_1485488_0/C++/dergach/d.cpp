#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

#define eps 1e-8

double v[105][105], tmp;
int T, t, N, M, i, j, k, H, a[105][105], b[105][105];

int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);
	
	scanf("%d", &T);
	for(t = 1; t <= T; t++)
	{
		scanf("%d %d %d", &H, &N, &M);
		for(i = 0; i < N; i++)
			for(j = 0; j < M; j++)
				scanf("%d", &a[i][j]);
		for(i = 0; i < N; i++)
			for(j = 0; j < M; j++)
				scanf("%d", &b[i][j]);
		for(i = 0; i < N; i++)
			for(j = 0; j < M; j++)
			{
				v[i][j] = 1e15;
			}
		v[0][0] = 0.0;
		queue <int> q;
		q.push(0);
		q.push(0);
		while(!q.empty())
		{
			i = q.front(); q.pop();
			j = q.front(); q.pop();
			if(i - 1 >= 0 && a[i-1][j] - b[i-1][j] >= 50 && a[i][j] - b[i-1][j] >= 50 && a[i-1][j] - b[i][j] >= 50) 
			{
				if(v[i][j] > -eps && v[i][j] < eps && a[i-1][j] - H >= 50)
				{
					if(v[i-1][j] > eps)
					{
						v[i-1][j] = 0.0;
						q.push(i-1); q.push(j);
					}
				}
				else
				{
					if(a[i-1][j] - (H - v[i][j] * 10) - 50.0 > -eps)
						tmp = 0;
					else
						tmp = 50.0 - (a[i-1][j] - (H - v[i][j] * 10));
					if((H - v[i][j] * 10) - tmp - b[i][j] - 20.0 > -eps)
					{
						if(v[i-1][j] - (v[i][j] + tmp / 10.0) - 1.0 > eps)
						{
							v[i-1][j] = (v[i][j] + tmp / 10.0) + 1.0;
							q.push(i-1); q.push(j);
						}
					}
					else
					{
						if(v[i-1][j] - (v[i][j] + tmp / 10.0) - 10.0 > eps)
						{
							v[i-1][j] = (v[i][j] + tmp / 10.0) + 10.0;
							q.push(i-1); q.push(j);
						}
					}
				}
			}

			if(i + 1 < N && a[i+1][j] - b[i+1][j] >= 50 && a[i][j] - b[i+1][j] >= 50 && a[i+1][j] - b[i][j] >= 50) 
			{
				if(v[i][j] > -eps && v[i][j] < eps && a[i+1][j] - H >= 50)
				{
					if(v[i+1][j] > eps)
					{
						v[i+1][j] = 0.0;
						q.push(i+1); q.push(j);
					}
				}
				else
				{
					if(a[i+1][j] - (H - v[i][j] * 10) - 50.0 > -eps)
						tmp = 0;
					else
						tmp = 50.0 - (a[i+1][j] - (H - v[i][j] * 10));
					if((H - v[i][j] * 10) - tmp - b[i][j] - 20.0 > -eps)
					{
						if(v[i+1][j] - (v[i][j] + tmp / 10.0) - 1.0 > eps)
						{
							v[i+1][j] = (v[i][j] + tmp / 10.0) + 1.0;
							q.push(i+1); q.push(j);
						}
					}
					else
					{
						if(v[i+1][j] - (v[i][j] + tmp / 10.0) - 10.0 > eps)
						{
							v[i+1][j] = (v[i][j] + tmp / 10.0) + 10.0;
							q.push(i+1); q.push(j);
						}
					}
				}
			}

			if(j - 1 >= 0 && a[i][j-1] - b[i][j-1] >= 50 && a[i][j] - b[i][j-1] >= 50 && a[i][j-1] - b[i][j] >= 50) 
			{
				if(v[i][j] > -eps && v[i][j] < eps && a[i][j-1] - H >= 50)
				{
					if(v[i][j-1] > eps)
					{
						v[i][j-1] = 0.0;
						q.push(i); q.push(j-1);
					}
				}
				else
				{
					if(a[i][j-1] - (H - v[i][j] * 10) - 50.0 > -eps)
						tmp = 0;
					else
						tmp = 50.0 - (a[i][j-1] - (H - v[i][j] * 10));
					if((H - v[i][j] * 10) - tmp - b[i][j] - 20.0 > -eps)
					{
						if(v[i][j-1] - (v[i][j] + tmp / 10.0) - 1.0 > eps)
						{
							v[i][j-1] = (v[i][j] + tmp / 10.0) + 1.0;
							q.push(i); q.push(j-1);
						}
					}
					else
					{
						if(v[i][j-1] - (v[i][j] + tmp / 10.0) - 10.0 > eps)
						{
							v[i][j-1] = (v[i][j] + tmp / 10.0) + 10.0;
							q.push(i); q.push(j-1);
						}
					}
				}
			}

			if(j + 1 < M && a[i][j+1] - b[i][j+1] >= 50 && a[i][j] - b[i][j+1] >= 50 && a[i][j+1] - b[i][j] >= 50) 
			{
				if(v[i][j] > -eps && v[i][j] < eps && a[i][j+1] - H >= 50)
				{
					if(v[i][j+1] > eps)
					{
						v[i][j+1] = 0.0;
						q.push(i); q.push(j+1);
					}
				}
				else
				{
					if(a[i][j+1] - (H - v[i][j] * 10) - 50.0 > -eps)
						tmp = 0;
					else
						tmp = 50.0 - (a[i][j+1] - (H - v[i][j] * 10));
					if((H - v[i][j] * 10) - tmp - b[i][j] - 20.0 > -eps)
					{
						if(v[i][j+1] - (v[i][j] + tmp / 10.0) - 1.0 > eps)
						{
							v[i][j+1] = (v[i][j] + tmp / 10.0) + 1.0;
							q.push(i); q.push(j+1);
						}
					}
					else
					{
						if(v[i][j+1] - (v[i][j] + tmp / 10.0) - 10.0 > eps)
						{
							v[i][j+1] = (v[i][j] + tmp / 10.0) + 10.0;
							q.push(i); q.push(j+1);
						}
					}
				}
			}
		}

		printf("Case #%d: %.7lf\n", t, v[N-1][M-1]);

	}
	return 0;
}