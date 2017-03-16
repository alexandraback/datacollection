#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<memory.h>
#include<queue>
using namespace std;

int r,c,h;
int cl[200][200];
int fl[200][200];
double d[200][200];

double INF = 1e9;
double eps = 1e-9;

struct state{
	int x,y;
	double t;
	state(int x, int y, double t):x(x), y(y), t(t) {}
	state() {}
	bool operator<(const state& s) const {
		return t > s.t;
	}
};

int cmp(double a, double b) {
	if(fabs(a-b) < eps) return 0;
	return a<b?-1:1;
}

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

double dij() {
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			d[i][j] = INF;

	priority_queue<state> q;
	q.push(state(0,0,0));
	d[0][0] = 0;

	while(!q.empty()) {
		state cur = q.top();
		q.pop();

		if(cur.x == r-1 && cur.y == c-1) return cur.t;
		if(cmp(d[cur.x][cur.y], cur.t) < 0) continue;
		
		for(int k=0;k<4;k++) {
			int nx = cur.x + dx[k], ny = cur.y + dy[k];
			if(nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
			if(cl[nx][ny] - fl[nx][ny] < 50) continue;
			if(cl[nx][ny] - fl[cur.x][cur.y] < 50) continue;
			if(cl[cur.x][cur.y] - fl[nx][ny] < 50) continue;
			double my_water = max(0.0, h-cur.t*10 - fl[cur.x][cur.y]);
			double other_water = max(fl[nx][ny]*1.0, h-cur.t*10);
			double dt = max(0.0, other_water - max(0.0, cl[nx][ny] - 50.0)) / 10.0;
			int dc = (cur.t+dt == 0 ? 0 : ((my_water-dt*10.0) >= 20 ? 1 : 10));
			double nc = dc+dt+cur.t;
			if(cmp(d[nx][ny], nc) <= 0) continue;
			d[nx][ny] = nc;
			q.push(state(nx, ny, nc));
		}
	}

	return -1;
}

int main()	{

	//freopen("b_sample.in","rt",stdin);

	freopen("b_small.in","rt",stdin);
	freopen("b_small.out","wt",stdout);

	int t;
	cin>>t;
	for(int tt=1;tt<=t;tt++) {
		cin>>h>>r>>c;
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
				cin>>cl[i][j];

		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
				cin>>fl[i][j];

		cout.precision(9);
		cout.setf(ios::fixed);
		cout<<"Case #"<<tt<<": "<<dij()<<endl;
	}

	return 0;
}