#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;

int n, m, k, nm;
int tp[15][15];
int st[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};

void fill(int x, int y, int c);
bool Check(int msk);

bool GetGrid(int p, int l, int msk)
{
	if(l == 0)
		return Check(msk);
	if(GetGrid(p+1, l-1, msk | (1<<p)))
		return 1;
	if(nm - p <= l)
		return 0;
	return GetGrid(p+1, l, msk);
}


bool Check(int msk)
{
	memset(tp, -1, sizeof(tp));
	for(int i = 0; i < nm; i++)
	{
		if(msk & (1<<i))
			tp[i / m][i % m] = 1;
	}
	for(int i = 0; i < n; i++)
	{
		if(tp[i][0] == -1)
			fill(i, 0, 0);
		if(tp[i][m-1] == -1)
			fill(i, m-1, 0);
	}
	for(int i = 0; i < m; i++)
	{
		if(tp[0][i] == -1)
			fill(0, i, 0);
		if(tp[n-1][i] == -1)
			fill(n-1, i, 0);
	}
	int cnt = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(tp[i][j] == -1)
				fill(i, j, 1);
			cnt += tp[i][j];
		}
	}
	return cnt >= k;
}

int q[25][2];
void fill(int x, int y, int c)
{
	int cur = 0, sz = 1;
	q[0][0] = x;
	q[0][1] = y;
		tp[x][y] = c;
	while(cur < sz)
	{
		x = q[cur][0];
		y = q[cur][1];
		cur++;
		for(int i = 0; i < 4; i++)
		{
			int xx = x + st[i][0], yy = y + st[i][1];
			if(xx >= 0 && xx < n && yy > 0 && yy < m &&
				tp[xx][yy] == -1)
			{
				q[sz][0] = xx;
				q[sz][1] = yy;
				sz++;
				
				tp[xx][yy] = c;
			}
		}
	}
}

int main()
{
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);


	int TT;
	scanf("%d", &TT);
	for(int T = 0; T < TT; T++)
	{
		printf("Case #%d: ", T+1);
		scanf("%d%d%d", &n, &m, &k);
		if(n <= 2 || m <= 2)
		{
			printf("%d\n", k);
			continue;
		}
		nm = n*m;
		int l = 0, r = k;
		while(r - l > 1)
		{
			int mid = (l + r) / 2;
			if(GetGrid(0, mid, 0))
				r = mid;
			else
				l = mid;
		}
		printf("%d\n", r);
	}

	return 0;
}