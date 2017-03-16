#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <utility>

using namespace std;

const int MAX = 111, water_rate = 10, inf = 1023456789, thresh = 50, kayak = 20;
const long double epsilon = 1.0e-9;

int dd[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int T, R, C, water, F[MAX][MAX], H[MAX][MAX];
long double dist[MAX][MAX];

long double edge(int r1, int c1, int r2, int c2, long double cur_t)
{
	// find earliest time you can start moving
	long double water_height = water - water_rate * cur_t;
	if(F[r1][c1] + thresh > H[r2][c2] || F[r2][c2] + thresh > H[r2][c2])
		return inf;
	if(F[r2][c2] + thresh > H[r1][c1])
		return inf;
	long double targ_water_height = H[r2][c2] - thresh;
	//cout << r1 << " " << c1 << " -> " << r2 << " " << c2 << ": " << targ_water_height << " " << water_height << endl;
	if(targ_water_height > water_height) // don't wait
	{
		if(cur_t == 0) return 0; // go before tide changes
		return cur_t + ((water_height - F[r1][c1] + epsilon > kayak) ? 1 : 10);
	}
	else
	{
		long double earliest = (water - targ_water_height) / (long double) water_rate;
		long double t1 = earliest + ((targ_water_height - F[r1][c1] + epsilon > kayak) ? 1 : 10);
		long double earliest2 = (water - (F[r1][c1] + kayak)) / (long double) water_rate;
		if(earliest2 > earliest)
			return min(t1, earliest2 + 1);
		else
			return t1;
	}
}

long double solve()
{
	//cout << "SOLVE" << endl;
	scanf("%d %d %d", &water, &R, &C);
	for(int i = 1; i <= R; i++)
		for(int j = 1; j <= C; j++)
			scanf("%d", &H[i][j]);
	for(int i = 1; i <= R; i++)
		for(int j = 1; j <= C; j++)
			scanf("%d", &F[i][j]);
	for(int i = 0; i <= R + 1; i++)
		for(int j = 0; j <= C + 1; j++)
			dist[i][j] = -1.0;
	for(int i = 1; i <= R; i++)
		for(int j = 1; j <= C; j++)
			dist[i][j] = inf;

	priority_queue<pair<long double, pair<int, int> > > pq; // <-dist, <r, c> >
	pq.push(make_pair(0, make_pair(1, 1)));
	while(pq.size() > 0)
	{
		pair<int, int> n = pq.top().second;
		long double nd = -pq.top().first;
		pq.pop();
		if(nd >= dist[n.first][n.second])
			continue;
		//cout << n.first << " " << n.second << " " << nd << endl;
		dist[n.first][n.second] = nd;
		for(int d = 0; d < 4; d++)
			pq.push(make_pair(-edge(n.first, n.second, n.first + dd[d][0], n.second + dd[d][1], nd), make_pair(n.first + dd[d][0], n.second + dd[d][1])));
	}
	return dist[R][C];
}

int main()
{
	freopen("b.in", "r", stdin);
	scanf("%d", &T);
	for(int t = 1; t <= T; t++)
		printf("Case #%d: %.8Lf\n", t, solve());
	return 0;
}
