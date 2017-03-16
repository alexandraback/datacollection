#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <string>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <set>
#include <map>
#include <ctime>
#include <cmath>

#define forn(i, n) for(int i=0;i<n;++i)
#define for1(i, n) for(int i=1;i<=n;++i)
#define forv(i, v) for(int i=0;i<v.size();++i)
#define sz(v) int(v.size())
#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define ft first
#define sc second
#define pt pair<int, int>

typedef long long li;
typedef long double ld;


using namespace std;

const int N = 1000, INF = 1000*1000*1000;
const ld  eps = 1e-9;

bool us[N][N];
bool us2[N][N];
int n, m, k;

int dx[] = {0, -1, 0, 1, 1, 1, -1, -1};
int dy[] = {1, 0, -1, 0, 1, -1, 1, -1};


void build(int x, int y, int cnt, int N) {
	memset(us, false, sizeof us);
	queue<pt> q;
	q.push(mp(x, y));
	us[x][y] = true;
	cnt--;
	while(cnt > 0) {
		int x = q.front().ft;
		int y = q.front().sc;
		q.pop();
		forn(i, N) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) 
				continue;
			if (us[nx][ny])
				continue;
			cnt--;
			us[nx][ny] = true;
			q.push(mp(nx, ny));
			if (cnt == 0)
				break;
		}
	}
}

int check(int x, int y) {
	memset(us2, false, sizeof us2);
	queue<pt> q;
	q.push(mp(x, y));
	us2[x][y] = true;
	int cnt = 0;
	while(!q.empty()) {
		int x = q.front().ft;
		int y = q.front().sc;

		cnt++;
		q.pop();
		bool can = true;
		forn(i, 8) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) 
				continue;
			if (!us[nx][ny])
				can = false;
		}
		if (!can)
			continue;
		forn(i, 8) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) 
				continue;
			if (!us[nx][ny])
				continue;
			if (us2[nx][ny])
				continue;
			us2[nx][ny] = true;
			q.push(mp(nx, ny));
		}
	}
	return cnt;
}

void printAns(int x, int y) {
	forn(i, n) {
		forn(j, m) {
			if (i == x && j == y) 
				putchar('c');
			else if (us[i][j])
				putchar('.');
			else
				putchar('*');
		}
		puts("");
	}
}

bool solve(int x, int y, int fc, int s) {

	build(x, y, fc, s);

	if (check(x, y) != fc)
		return false;
	printAns(x, y);
   	return true;
}

bool dumbSolve(int k) {
    int fc = n * m - k;
	forn(i, n)
		forn(j, m) {
			if (k > 0)
				us[i][j] = false;
			else
				us[i][j] = true;
			k--;
		}
	if (check(n - 1, m - 1) == fc) {
		printAns(n - 1, m - 1);
		return true;
	}
	k = n * m - fc;
	forn(j, m) 
		forn(i, n) {
			if (k > 0)
				us[i][j] = false;
			else
				us[i][j] = true;
			k--;
		}
	if (check(n - 1, m - 1) == fc) {
		printAns(n - 1, m - 1);
		return true;
	}
	return false;
}

bool solve(int test) {
	scanf("%d%d%d", &n, &m, &k);
   	int fc = n * m - k;

	printf("Case #%d:\n", test + 1);
	forn(x, n)
		forn(y, m)
			if (solve(x, y, fc, 4) || solve(x, y, fc, 8) || dumbSolve(k))
				return false;
	puts("Impossible");
	return false;
}

int main () {	
#ifdef IKAR
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	forn(i, n)
		solve(i);

	return 0;
}