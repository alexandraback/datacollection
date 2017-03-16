#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int waterH, H, W;

int gf[110][110];
int gc[110][110];
bool cantPass[110][110];
int state[110][110];
double dist[110][110];

//#define DEBUG

struct elem
{
	double t;
	int x;
	int y;
};

bool operator < (const elem& l, const elem& r)
{
	return l.t > r.t ||
		l.t == r.t && l.x > r.x ||
		l.t == r.t && l.x == r.x && l.y > r.y;
}

int ww[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};

bool inrect(int x, int y)
{
	if (x < 0) return false;
	if (y < 0) return false;
	if (x >= W) return false;
	if (y >= H) return false;
	return true;
}
bool canGo(int px, int py, int x, int y, double t)
{
	if (x < 0) return false;
	if (y < 0) return false;
	if (x >= W) return false;
	if (y >= H) return false;
	if (cantPass[y][x]) return false;
	if (gc[y][x] < 50+max(waterH, gf[py][px])) return false;
	if (max(waterH, gf[y][x]) + 50 > gc[py][px]) return false;
	return gc[y][x] - max(waterH - 10*t, (double)gf[y][x]) >= 50;
}

bool canGoAfter(int px, int py, int x, int y, double t, double& tout)
{
#ifdef DEBUG
	cout << "canGoAfter " << px << ' '<<py<<' ' <<x << ' '<<y <<' '<<endl;
#endif
	if (x < 0) return false;
	if (y < 0) return false;
	if (x >= W) return false;
	if (y >= H) return false;
	if (cantPass[y][x]) return false;
	if (gf[y][x] + 50 > gc[py][px]) return false;
#ifdef DEBUG
	cout << "returns true" <<endl;
#endif
	tout = t;
	if (gc[y][x] - max(waterH - 10*t, (double)gf[y][x]) >= 50)
	{
#ifdef DEBUG
		cout << "A water level at start: " << waterH-10*t-gf[py][px] << endl;
#endif
		if (waterH-10*t-gf[py][px]>=20)
			tout += 1;
		else
			tout += 10;
		return true;
	}
	tout = (gc[y][x] - 50 - waterH)/-10.;
#ifdef DEBUG
	cout << "Btout " << tout << endl;
	cout << "B water level at start: " << waterH-10*tout-gf[py][px] << endl;
#endif
	if (waterH-10.*tout-gf[py][px]>=20)
		tout += 1;
	else
		tout += 10;

	return true;
}

double process()
{
	scanf("%d %d %d", &waterH, &H, &W);
	memset(&state, 0, sizeof(state));
	memset(&dist, 0, sizeof(dist));
	memset(&cantPass, 0, sizeof(cantPass));
	for(int i = 0; i < H; i ++)
		for(int j = 0; j < W; j ++)
		{
			scanf("%d", &gc[i][j]);
		}
	for(int i = 0; i < H; i ++)
		for(int j = 0; j < W; j ++)
		{
			scanf("%d", &gf[i][j]);
			if (gc[i][j] - gf[i][j]<50)
				cantPass[i][j] = true;
		}

	// before tide
	state[0][0] = 2;

	queue<pair<int, int> > q;
	q.push(make_pair(0,0));
	double t = 0;
	while(!q.empty())
	{
		pair<int, int> pp = q.front();
		q.pop();
		int x = pp.first;
		int y = pp.second;
		if (canGo(x,y,x-1, y, t) && state[x-1][y] != 2)
		{
			state[x-1][y] = 2;
			dist[x-1][y] = 0;
			q.push(make_pair(x-1,y));
		}
		if (canGo(x,y,x+1, y, t) && state[x+1][y] != 2)
		{
			state[x+1][y] = 2;
			dist[x+1][y] = 0;
			q.push(make_pair(x+1,y));
		}
		if (canGo(x,y,x, y-1, t) && state[x][y-1] != 2)
		{
			state[x][y-1] = 2;
			dist[x][y-1] = 0;
			q.push(make_pair(x,y-1));
		}
		if (canGo(x,y,x, y+1, t) && state[x][y+1] != 2)
		{
			state[x][y+1] = 2;
			dist[x][y+1] = 0;
			q.push(make_pair(x,y+1));
		}
	}
	if (state[W-1][H-1]==2) 
		return 0.0;
	priority_queue<elem> pq;
	for(int y = 0; y < H; y ++)
		for(int x = 0; x < W; x ++)
			if (state[x][y] == 2)
			{
				for(int w = 0; w < 4; w++)
				{
					int nx = x + ww[w][0];
					int ny = y + ww[w][1];
					if (!inrect(nx,ny))
						continue;
					if (state[nx][ny] == 2)
						continue;
					double tout;
#ifdef DEBUG
					cout << "PQ " << nx << ' '<<ny<<' ' <<
						
					 (canGoAfter(x, y, nx, ny, t, tout))
						<<endl;
#endif
					if (canGoAfter(x, y, nx, ny, t, tout))
					{
						if (dist[nx][ny] > tout || state[nx][ny] == 0)
						{
							dist[nx][ny] = tout;
							elem e;
							e.x = nx;
							e.y = ny;
							e.t = tout;
							pq.push(e);
						}
						state[nx][ny] = 1;
					}

				}
			}
#ifdef DEBUG
	cout << pq.size() << endl;
#endif
	while(state[W-1][H-1]!=2)
	{
		if (pq.size() == 0)
		{
			for(int i = 0; i < H; i++)
			{
				for(int j = 0; j < W; j++)
				{
					if (cantPass[i][j])
					cout << '*';
					else
						cout<<' ';
				}
				cout << endl;
			}
			for(int i = 0; i < H; i++)
			{
				for(int j = 0; j < W; j++)
				{
					cout << state[j][i];
				}
				cout << endl;
			}
			while(1);
		}
		elem e = pq.top();
		pq.pop();
		if (state[e.x][e.y] != 1)
			continue;
#ifdef DEBUG
		cout << e.x << ' ' << e.y << ' ' << e.t << ' ' << endl;
		cout << dist[e.x][e.y] << endl;
#endif
		state[e.x][e.y] = 2;
		for(int w = 0; w < 4; w++)
		{
			int nx = e.x + ww[w][0];
			int ny = e.y + ww[w][1];
			if (!inrect(nx,ny))
				continue;
			if (state[nx][ny] == 2)
				continue;
			double tout;
			if (canGoAfter(e.x, e.y, nx, ny, e.t, tout))
			{
				if (dist[nx][ny] > tout || state[nx][ny] == 0)
				{
					dist[nx][ny] = tout;
					elem e;
					e.x = nx;
					e.y = ny;
					e.t = tout;
					pq.push(e);
				}
				state[nx][ny] = 1;
			}
			
		}
	}
	return dist[W-1][H-1];
}

int main()
{
	int tn;
	scanf("%d", &tn);
	for(int loop = 0; loop < tn; loop++)
	{
		printf("Case #%d: ", loop+1);
		double ret = process();
		printf("%.10lf\n", ret);
	}
	return 0;
}
