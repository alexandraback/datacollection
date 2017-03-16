#include <cstdio>
#include <cassert>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int n, m, h;
int nt;

int a[100][100];
int b[100][100];

bool good[100][100];

int di[] = {1,  0, -1, 0};
int dj[] = {0, -1,  0, 1};

double cost[100][100];

const double oo = 1e20;

void go(int i, int j)
{
	if (good[i][j]) return;
	good[i][j] = true;
	
	for(int d = 0; d < 4; d++)
	{
		int ii = i + di[d];
		int jj = j + dj[d];
		if (ii < 0 || jj < 0 || ii >= n || jj >= m) continue;
		
		if (b[ii][jj] - h < 50) continue;
		if (b[ii][jj] - a[i][j] < 50) continue;
		if (b[ii][jj] - a[ii][jj] < 50) continue;
		if (b[i][j] - a[ii][jj] < 50) continue;
		
		go(ii, jj);
	}
}

int main()
{
	scanf("%d", &nt);
	
	for(int tt = 1; tt <= nt; tt++)
	{	
		printf("Case #%d: ", tt);
		
		scanf("%d %d %d", &h, &n, &m);
		
		for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) scanf("%d", &b[i][j]);
		for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) scanf("%d", &a[i][j]);
		
		memset(good, 0, sizeof good);
		
		go(0, 0);
		
		set< pair<double, pair<int, int> > > Q;
		
		for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cost[i][j] = oo;
		
		for(int i = 0; i < n; i++) for(int j = 0; j < m; j++)
		if (good[i][j])
		{
			Q.insert(make_pair(0.0, make_pair(i, j)));
			cost[i][j] = 0.0;
		}
		
		while(cost[n - 1][m - 1] == oo && Q.size() > 0)
		{
			double t = Q.begin()->first;
			int i = Q.begin()->second.first;
			int j = Q.begin()->second.second;
			Q.erase(Q.begin());
			
			//printf("at (%d, %d), t = %.3lf\n", i, j, t);
			
			for(int d = 0; d < 4; d++)
			{
				int ii = i + di[d];
				int jj = j + dj[d];
				if (ii < 0 || jj < 0 || ii >= n || jj >= m) continue;
				
				if (b[ii][jj] - a[i][j] < 50) continue;
				if (b[ii][jj] - a[ii][jj] < 50) continue;
				if (b[i][j] - a[ii][jj] < 50) continue;
				
				double level = h - 10.0 * t;
				double new_t = t;
				
				if (b[ii][jj] - level < 50) new_t += (50.0 - (b[ii][jj] - level)) / 10.0;
				
				double new_level = h - 10.0 * new_t;
				
				if (new_level - a[i][j] >= 20.0 - 1e-8) new_t += 1; else new_t += 10;
				
				if (cost[ii][jj] <= new_t) continue;
				if (cost[ii][jj] != oo) Q.erase(Q.find(make_pair(cost[ii][jj], make_pair(ii, jj))));
				cost[ii][jj] = new_t;
				Q.insert(make_pair(cost[ii][jj], make_pair(ii, jj)));
			}
		}
		
		printf("%.10lf\n", cost[n - 1][m - 1]);
	}
	
	return 0;
}
