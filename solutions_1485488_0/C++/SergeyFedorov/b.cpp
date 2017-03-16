#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <sstream>
#include <queue>

using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) int(a.size() - 1)
#define all(a) a.begin(), a.end()
#define seta(a,x) memset (a, x, sizeof (a))
#define I (int)

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const long double eps = 1e-7;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;
const string task = "";

template <class T> T sqr (T x) {return x * x;}

int px[] = {-1, 0, 1, 0};
int py[] = {0, 1, 0, -1};

const int nmax = 200;

char buf[100100];
int c[nmax][nmax], f[nmax][nmax];
int h, n, m;

double d[nmax][nmax];
int used[nmax][nmax];
queue<pii> q;
int inq[nmax][nmax];

bool check(int x, int y){
	return x >= 0 && y >= 0 && x < n && y < m;
}

void add(int x, int y, double dp){
	if (dp > 1e9)
		return;
	if (d[x][y] < dp + eps)
		return;
	d[x][y] = dp;
	if (!inq[x][y])
		q.push(mp(x, y));
	inq[x][y] = 1;
}

double can_go(int x, int y, int nx, int ny){
	if (c[nx][ny] < f[x][y] + 50 || c[nx][ny] < f[nx][ny] + 50 || f[nx][ny] + 50 > c[x][y])
		return 1e18;
	double wn = max(.0 + h - (c[nx][ny] - 50), .0) / 10.;
	return wn;
}

double calc(int x, int y, int nx, int ny, double t){
	if (h > t * 10 + f[x][y] + 20 - eps)
		return 1;
	return 10;
}

void go(){
	while (!q.empty()){
		pii now = q.front();
		q.pop();
		int x = now.fs;
		int y = now.sc;
		inq[x][y] = 0;
//		cerr << x << " " << y << endl;
		forn(j, 4){
			int nx = x + px[j];
			int ny = y + py[j];
			if (!check(nx, ny))
				continue;
			double t = can_go(x, y, nx, ny);
//			cerr << t << endl;
			t = max(t, d[x][y]);
			double w = calc(x, y, nx, ny, t);
//			cerr << w << endl;
			add(nx, ny, t + w);
		}   
	}
}


void dfs(int x, int y){
	used[x][y] = 1;
	forn(j, 4){
		int nx = x + px[j];
		int ny = y + py[j];
		if (!check(nx, ny) || used[nx][ny])
			continue;
		double t = can_go(x, y, nx, ny);
		if (t < eps)
			dfs(nx, ny);			
	}
}

void solve(){
	memset(inq, 0, sizeof inq);
	memset(used, 0, sizeof used);
	cin >> h >> n >> m;
	forn(i ,n)
		forn(j, m)
			cin >> c[i][j];
	forn(i, n)
		forn(j, m)
			cin >> f[i][j];
	forn(i, n)
		forn(j, m)
			d[i][j] = 1e8;
	dfs(0, 0);
/*	forn(i, n){
		forn(j, m)
			cerr << used[i][j] << " ";
		cerr << endl;
	}
*/
	forn(i, n)
		forn(j, m)
			if (used[i][j])
				add(i, j, 0);
	go();
	printf("%0.9lf\n", d[n-1][m-1]);			
}

int main ()
{
	int n;
	cin >> n;
	gets(buf);
	forn(i, n){
		cerr << i << endl;
		printf("Case #%d: ", i + 1);
		solve();
	}

	
	return 0;
}
