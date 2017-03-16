#include <algorithm>
#include <iostream>
#include <cassert>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <map>
#include <set>

#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define PB(A) push_back(A)

typedef long long ll;
typedef double ld;

int	fx[] = {-1, 0, +1, 0}, fy[] = {0, +1, 0, -1},
	ex[] = {-1, -1, 0, +1, +1, +1, 0, -1}, ey[] = {0, +1, +1, +1, 0, -1, -1, -1};

using namespace std;

int test_num, case_number;
const int MAXN = 200;
const double INF = 1e18;

#define gout case_number++, printf("Case #%d: ",case_number), cout

int H, n, m, col;
int up[MAXN][MAXN], down[MAXN][MAXN], w[MAXN][MAXN];
double d[MAXN][MAXN];

struct comp
{
 	bool operator () (const pair <int, int> f, const pair <int, int> a) const
 	{
 		if (fabs(d[f.first][f.second]-d[a.first][a.second])<1e-12) return f<a;
		return d[f.first][f.second]<d[a.first][a.second];
 	}
};

set < pair <int, int>, comp > dist;

void dfs(int x, int y)
{
 	w[x][y] = col;
 	d[x][y] = 0;
 	for (int i = 0; i < 4; i++)
 	{
 	 	int xx = x+fx[i], yy = y+fy[i];
 	 	if (xx<0||yy<0||xx>=n||yy>=m||w[xx][yy]==col) continue;
		if (up[xx][yy]-down[x][y]<50 || up[xx][yy]-down[xx][yy]<50) continue;
		if (up[x][y]-down[xx][yy]<50) continue;
		if (up[xx][yy]-H<50) continue;
		dfs(xx, yy);
 	}
}

void main2()
{
	scanf("%d%d%d", &H, &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &up[i][j]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &down[i][j]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			d[i][j] = INF;
	d[0][0] = 0;
	col++;
	dfs(0, 0);
	dist.clear();
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			dist.insert(MP(i, j));
	double wlevel, trans;
	for (int x, y; SIZE(dist);)
	{
		x = dist.begin()->first;
		y = dist.begin()->second;
		dist.erase(dist.begin());
//		cerr << "STaRTING at " << x << " " << y << endl;
		if (fabs(d[x][y]-INF) < 1e-5) break;

		for (int k = 0; k < 4; k++)
		{
		 	int xx = fx[k]+x, yy = fy[k]+y;

		 	if (xx < 0 || yy < 0 || xx>=n || yy>=m) continue;
			if (up[xx][yy]-down[x][y]<50 || up[xx][yy]-down[xx][yy]<50) continue;
			if (up[x][y]-down[xx][yy]<50) continue;

			wlevel = max(0., H-d[x][y]*10);
			trans = 0;

			if (up[xx][yy]-wlevel<50)
			{
				trans = (50-(up[xx][yy]-wlevel))/10.;

				wlevel = max(0., H-(d[x][y]+trans)*10);
			}

			if (wlevel+1e-12-down[x][y]>20)
				trans = trans+1;
			else
				trans = trans+10;

//			cerr << "Here " << x << " " << y << " --> " << xx << " " << yy << " trans = " << trans << endl;

			if (d[xx][yy] > d[x][y]+trans+1e-9 && dist.find(MP(xx, yy))!=dist.end())
			{
			 	dist.erase(dist.find(MP(xx, yy)));
			 	d[xx][yy] = d[x][y]+trans;
			 	dist.insert(MP(xx, yy));
//			 	cerr << SIZE(dist) << endl;
			}
		}
	}
	gout;
	printf("%.15lf\n", d[n-1][m-1]);
}

int main()
{
	scanf("%d", &test_num);

	for (int i = 0; i < test_num; i++)
		main2();

	return 0;
}
