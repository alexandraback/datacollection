#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

int pr[1005][1005][50];

struct pt
{
	int x, y, st;
	pt(int x = 0, int y = 0, int st = 0): x(x), y(y), st(st){}
};

int dir[4][2] = {0, 1, 0, -1, -1, 0, 1, 0};
char let[4] = {'N', 'S', 'W', 'E'};

pt q[10005];
int h, t;
char ans[500];

int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int ts, x, y;
	cin >> ts;
	for(int tt = 1; tt <= ts; ++tt)
	{
		scanf("%d%d", &x, &y);
		memset(pr, -1, sizeof(pr));

		h = t = 0;
		pr[500+0][500+0][0] = pr[500+0][500+0][1] = 10;
		q[t++] = pt(0, 0, 1);
		pt p;
		while(h < t)
		{
			p = q[h++];
			if(p.x == x && p.y == y)
				break;
			for(int i = 0; i < 4; ++i)
			{
				int xx = p.x + p.st*dir[i][0], yy = p.y + p.st*dir[i][1];
				if(pr[500+xx][500+yy][p.st+1] == -1)
				{
					pr[500+xx][500+yy][p.st+1] = i;
					q[t++] = pt(xx, yy, p.st+1);
				}
			}
		}
		int asz = 0;
		while(1)
		{
			if(p.x == 0 && p.y == 0)
				break;
			int s = pr[500+p.x][500+p.y][p.st];
			ans[asz++] = let[s];
			p.x -= (p.st-1)*dir[s][0];
			p.y -= (p.st-1)*dir[s][1];
			p.st--;
		}
		reverse(ans, ans+asz);
		printf("Case #%d: %s\n", tt, ans);
	}

	return 0;
}