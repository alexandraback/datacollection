#include<iostream>
#include <cstdio>
#include <set>
using namespace std;

int h, n, m;
int c[100][100];
int f[100][100];
int was[100][100];
int way[100][100];
const int inf = 1e9;
struct comp{
	comp(){}
	bool operator () (pair<int, int> a, pair<int, int> b){
		if (way[a.first][a.second]!=way[b.first][b.second])
			return way[a.first][a.second]<way[b.first][b.second];
		else
			return a<b;
	}
};
set<pair<int, int>, comp> s;

const int vx[]={1, 0,-1, 0};
const int vy[]={0, 1, 0,-1};

bool pos(int x, int y){
	return (0<=x && x<n && 0<=y && y<m);
}

double fw(int x, int y, int x1, int y1, int t){
	if (c[x1][y1]-f[x1][y1]<50 || c[x1][y1]-f[x][y]<50 || c[x][y]-f[x1][y1]<50)
		return inf;
	t = max(t, h-min(h, c[x1][y1]-50));
	if (t==0)
		return 0;
	if (h-t-f[x][y]<20)
		return t+100;
	else
		return t+10;
}

void solve(){
	s.clear();
	cin>>h>>n>>m;
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			cin>>c[i][j];
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			cin>>f[i][j];
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j){
			was[i][j]=0;
			way[i][j]=inf;
			s.insert(make_pair(i, j));
		}
	way[0][0]=0;
	while (!was[n-1][m-1]){
		pair<int, int> cur=*s.begin();
		s.erase(s.begin());
		was[cur.first][cur.second]=1;
		for (int i=0; i<4; ++i){
			if (!pos(cur.first+vx[i], cur.second+vy[i])) continue;
			double nw=fw(cur.first, cur.second, cur.first+vx[i], cur.second+vy[i], way[cur.first][cur.second]);
			if (nw<way[cur.first+vx[i]][cur.second+vy[i]]){
				s.erase(make_pair(cur.first+vx[i], cur.second+vy[i]));
				way[cur.first+vx[i]][cur.second+vy[i]]=nw;
				s.insert(make_pair(cur.first+vx[i], cur.second+vy[i]));
			}
		}
	}
	cout<<way[n-1][m-1]/10<<'.'<<way[n-1][m-1]%10<<endl;
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin>>t;
	for (int i=1; i<=t; ++i){
		cout<<"Case #"<<i<<": ";
		solve();
	}
}