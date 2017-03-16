/**					Be name Khoda					**/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <list>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <bitset>
#include <limits>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <memory.h>
using namespace std;

#define ll long long
#define un unsigned
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define VAL(x) #x << " = " << x << "   "
#define SQR(a) ((a) * (a))
#define SZ(x) ((int) x.size())
#define ALL(x) x.begin(), x.end()
#define CLR(x, a) memset(x, a, sizeof x)
#define FOREACH(i, x) for(__typeof((x).begin()) i = (x).begin(); i != (x).end(); i ++)
#define X first
#define Y second
#define SAL cerr << "Salam!\n"
#define PI 3.141592654

#define cout fout
#define cin fin

ifstream fin("B-small-attempt2.in");
ofstream fout("B-small-attempt2.out");

const int MAXN = 10 * 1000 + 10, INF = 1e9 + 7;

map<int, bool> a[MAXN];
map<int, int> ans[MAXN];
vector<pii> v;
int n, tot = 0;

void solve(int idx);

void move(int idx, int x, int y, int c)
{
	while (true)
	{
		if (y > 0 && a[y - 1][x + c])
			break;
		if (y == 0)
			break;
		x += c;
		y --;
	}
	v.pb(mp(x, y));
	a[y][x] = true;
	solve(idx + 1);
	v.pop_back();
	a[y][x] = false;
}

void solve(int idx)
{
	if (idx == n)
	{
		for (int i = 0; i < n; i ++)
			ans[v[i].Y][v[i].X] ++;
		tot ++;
		return ;
	}
	int x = 0, y = idx + 1;
	while (true)
	{
		if (y == 1)
		{
			v.pb(mp(x, 0));
			a[x][0] = true;
			solve(idx + 1);
			a[x][0] = false;
			v.pop_back();
			break;
		}
		if (a[y - 1][x - 1])
		{
			move(idx, x + 1, y - 1, 1);
			break;
		}
		else if (a[y - 1][x + 1])
		{
			move(idx, x - 1, y - 1, -1);
			break;
		}
		else if (a[y - 2][x])
		{
			move(idx, x + 1, y - 1, 1);
			move(idx, x - 1, y - 1, -1);
			break;
		}
		y --;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc ++)
	{
		int x, y;
		cin >> n >> x >> y;
		tot = 0;
		solve(0);
		cout << "Case #" << tc << ": " << fixed << setprecision(10) << (double)((double)ans[y][x] / (double)tot) << endl;
		//cout << ans[y][x] << ' ' << tot << endl;
		for (int i = 0; i < MAXN; i ++)
		{
			ans[i].clear();
			a[i].clear();
		}
		v.clear();
	}
	return 0;
}
