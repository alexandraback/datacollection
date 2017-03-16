//Solution by Zhusupov Nurlan
#include <iostream>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <ctime>

using namespace std;

typedef long long LL;
typedef map<string , int> MSI;
typedef vector<int> VI;

#define pb(x) push_back(x)
#define sqr(x) ((x) * (x))
#define F first
#define S second
#define SZ(t) ((int) t.size())
#define len(t) ((int) t.length())
#define base 10
#define fname ""
#define sz 1000 * 1000
#define EPS (1e-8)
#define INF ((int)1e9 + 9)
#define write(xx) printf("%d" , xx);
#define readln(xx) getline(cin , xx)
#define read(xx) scanf("%d" , &xx)
#define for(xx1 , yy1 , zz1) for(int zz1 = xx1 ; zz1 <= yy1 ; zz1++)
#define mp make_pair
const double PI  = acos(-1.0);

int t, n, m, c, buf, cnt;
char a[1000][1000];
bool was[1000][1000];

void go(int x, int y)
{
	if (x > n || y < 1)
		return;
	if (c)
		a[x][y] = '*', c--;
	go(x + 1, y - 1);
}

void dfs(int x, int y)
{
	if (x < 1 || x > n || y < 1 || y > m)
		return;
	cnt++;
	was[x][y] = 1;
	bool f = 1;
	for (-1, 1, dx)
		for (-1, 1, dy)
		{
			if (a[x + dx][y + dy] == '*')
				f = 0;
		}
   	if (f)
   	{
   		for (-1, 1, dx)
   			for (-1, 1, dy)
   				if (!was[x + dx][y + dy])
   					dfs(x + dx, y + dy);
   	}
}
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void Go(int x, int y, int d)
{
	if (!c)
		return;
	c--;
	a[x][y] = '*';
	if (x + dx[d] < 1 || x + dx[d] > n || y + dy[d] < 1 || y + dy[d] > m || a[x + dx[d]][y + dy[d]] == '*')
		d = (d + 1) % 4;
	Go(x + dx[d], y + dy[d], d);
}

void out()
{
	for (1, n, i)
    {
    	for (1, m, j)
   			cout << a[i][j];
  		cout << endl;
    }
}

void rec(int x, int y)
{
	int cc = 0;
	for (-1, 1, dx)
		for (-1, 1, dy)
		{
			if (!was[x + dx][y + dy])
				cc++;
		}
   	if (cnt >= cc)
   		cnt -= cc;
   	else
   		return;
   	vector <pair<int, int> > v;
   	for (-1, 1, dx)
   		for (-1, 1, dy)
   		{
   			if (!was[x + dx][y + dy])
   			{
   				was[x + dx][y + dy] = 1;
   				v.pb(mp(x + dx, y + dy));
   			}
   		}
  	for (0, int(v.size()) - 1, i)
  		rec(v[i].F, v[i].S);
}

bool solve(int x, int y)
{
	for (0, n + 1, i)
    		for (0, m + 1, j)
    			was[i][j] = 1, a[i][j] = '.';
    	
    	for (1, n, i)
    		for (1, m, j)
    			was[i][j] = 0, a[i][j] = '.';
    	
    	a[x][y] = 'c';
    	cnt = n * m - c - 1;
    	was[x][y] = 1;
    	rec(x, y);
    	for (1, n, i)
    		for (1, m, j)
    			if (!was[i][j])
    				a[i][j] = '*';
    	if (cnt == 0)
    	{
    		out();
    		return true;
    	}
    	return false;
}

bool epic()
{
	for (1, n, i)
		for (1, m, j)
			if (solve(i, j))
				return true;
  	return false;
}

int main(){
	freopen(fname"in", "r", stdin);
	freopen(fname"out", "w", stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    for (1, t, T)
    {
      	cout << "Case #" << T << ":\n";
    	cin >> n >> m >> c;
    	if (solve(1, 1))
    		continue;
    	if (solve((n + 1) / 2, (m + 1) / 2))
    		continue;
    	if (solve(n, m))
    		continue;
    	if (epic())
    		continue;
    	buf = c;
    	for (0, n + 1, i)
    		for (0, m + 1, j)
    			was[i][j] = 0, a[i][j] = '.';
    	for (1, n + m, i)
    	{
    		go(max(1, i - m + 1), min(i, m));
    	}
    	a[n][m] = 'c';
    	cnt = 0;
    	dfs(n, m);
    	if (cnt == n * m - buf)
    	{
    		out();
    		continue;
    	}
    	c = buf;
    	for (0, n + 1, i)
    		for (0, m + 1, j)
    			was[i][j] = 0, a[i][j] = '.';
    	Go(1, 1, 0);
    	a[(n + 1) / 2][(m + 1) / 2] = 'c';
    	cnt = 0;
    	dfs((n + 1) / 2, (m + 1) / 2);
    	if (cnt == n * m - buf)
    	{
    		out();
    		continue;
    	}
    	cout << "Impossible\n";
    	

    }
    return 0;
}

