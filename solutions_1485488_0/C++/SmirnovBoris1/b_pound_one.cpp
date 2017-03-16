#pragma comment (linker, "/STACK:64000000")
#include <memory.h>
#include <cstdio> 
#include <sstream> 
#include <iostream> 
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <algorithm>
#include <cstring>
#include <list>
#include <cmath>

using namespace std;

//485271451

typedef long long lint;
typedef pair<int,int> pii;
#define pb push_back
#define sz(a) (int)((a).size())


void prepare(string s){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}

struct state
{
	
	int i,j;
	state(){}
	state(int I, int J):i(I), j(J){}

};

const int MAXN = 100 + 2;
const int MAXH = 10000 + 41 ;
int a[MAXN][MAXN];

int f[MAXN][MAXN];
int c[MAXN][MAXN];

int dx[] = {1, -1, 0, 0}; 
int dy[] = {0, 0, 1, -1}; 
int n,m;
bool out(int x, int y)
{
	if (x < 0 || y < 0 || x >= n || y >= m)
		return true;
	return false;
}

bool solve(){

	int N_TEST;
	cin >> N_TEST;
	for (int n_test = 0; n_test < N_TEST; ++ n_test)
	{
		int H;
		memset(a, 60, sizeof(a));
		cin >> H >> n >> m;

		for (int i = 0; i < n; ++ i)
			for (int j = 0; j < m; ++ j)
				cin >> c[i][j];
		for (int i = 0; i < n; ++ i)
			for (int j = 0; j < m; ++ j)
				cin >> f[i][j];

		a[0][0] = 0;
		queue<state> q;
		q.push(state(0,0));

		while (!q.empty())
		{
			int curi = q.front().i;
			int curj = q.front().j;
			q.pop();
			for (int i = 0; i < 4; ++ i)
			{
				int x = curi + dx[i];
				int y = curj + dy[i];
				if (out(x,y))
					continue;
				if (c[x][y] - f[x][y] < 50)
					continue;
				if (c[x][y] - f[curi][curj] < 50)
					continue;
				if (c[curi][curj] - f[x][y] < 50)
					continue;
				int down1 = max(H - a[curi][curj] * 10, f[curi][curj]);
				int down2 = max(H - a[curi][curj] * 10, f[x][y]);
				int up1 = c[curi][curj];
				int up2 = c[x][y];
				int nesTime = 0;
				nesTime = max(nesTime, 50 - (up1 - down2));
				nesTime = max(nesTime, 50 - (up2 - down1));
				nesTime = max(nesTime, 50 - (up2 - down2));
				int curTime = a[curi][curj] + nesTime;
				int curH = max(f[curi][curj], H - curTime);
				int cost;
				if (curH - f[curi][curj] >= 20)
					cost = 10;
				else
					cost = 100;
				if (a[x][y] > curTime + cost)
				{
					a[x][y] = curTime + cost;
					q.push(state(x,y));
				}
				else
					if (a[curi][curj] == 0 && nesTime == 0 && a[x][y] != 0)
						q.push(state(x,y));

				if (a[curi][curj] == 0 && nesTime == 0)
				{
					a[x][y] = 0;
				}
			}	
		}
		double ans = a[n - 1][m - 1];
		printf("Case #%d: %.1lf\n", n_test + 1, ans / 10.);
	}

	return false;
}

int main(){

	prepare("");
	while (solve());



	return 0;
}