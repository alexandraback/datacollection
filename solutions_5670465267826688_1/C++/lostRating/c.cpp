#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <ctime>
#include <sstream>
#include <fstream>
#include <bitset>
#include <iomanip>
#include <assert.h>

using namespace std;

typedef long long int64;
typedef long long LL;
typedef long double real;
typedef long double LD;

#define mp make_pair
#define PII pair<int, int>
#define pb push_back
#define sz(X) ((int)((X).size()))

#define x first
#define y second

const double eps = 1e-8;
const double PI = acos(0.) * 2;
const int lim = 1000000000;
const int inf = ~0U >> 1;

template<class T> T abs(T x){return x < 0 ? -x : x;}

const int N = 100005;

const int gxx[4][4] = {
	{0,1,2,3},
	{1,0,3,2},
	{2,3,0,1},
	{3,2,1,0}};

struct node
{
	int x, y;
	node(int x = 0, int y = -1): x(x), y(y) {}
	node operator *(const node &b)
	{
		node c = node(x ^ b.x, gxx[y][b.y]);
		if (y > 0)
		{
			if (y == b.y ||
				(y == 1 && b.y == 3) ||
				(y == 2 && b.y == 1) ||
				(y == 3 && b.y == 2))
				c.x ^= 1;
		}
		return c;
	}
};

node s[N], l[N], cur;
int ed;

void cal(long long m)
{
	if (m == 1) l[++ed] = cur;
	else
	{
		if (m & 1)
		{
			cal(m - 1);
			node tmp = l[ed] * cur;
			l[++ed] = tmp;
		}
		else
		{
			cal(m >> 1);
			node tmp = l[ed] * l[ed];
			l[++ed] = tmp;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	freopen("C-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
	for (int tt = 1; tt <= T; ++tt)
	{
		cout << "Case #" << tt << ": ";
		int n; long long m;
		cin >> n >> m;
		cur = node(0, 0);
		for (int i = 1; i <= n; ++i)
		{
			char t;
			cin >> t;
			if (t == 'i')
				s[i] = node(0, 1);
			else if (t == 'j')
				s[i] = node(0, 2);
			else if (t == 'k')
				s[i] = node(0, 3);
			else
				assert(false);
			cur = cur * s[i];
		}
		ed = 0;
		cal(m);
		if (!(l[ed].x == 1 && l[ed].y == 0))
		{
			cout << "NO" << endl;
			continue;
		}
		cur = node(0, 0);
		long long left = -1, right = -1;
		for (int i = 1, cnt = 1; cnt <= n * 4; ++i, ++cnt)
		{
			if (i > n) i = 1;
			cur = cur * s[i];
			if (cur.x == 0 && cur.y == 1)
			{
				left = cnt;
				break;
			}
		}
		cur = node(0, 0);
		for (int i = n, cnt = 1; cnt <= n * 4; --i, ++cnt)
		{
			if (i < 1) i = n;
			cur = s[i] * cur;
			if (cur.x == 0 && cur.y == 3)
			{
				right = cnt;
				break;
			}
		}
		if (left == -1 || right == -1 || left + right >= 1LL * n * m)
		{
			cout << "NO" << endl;
			continue;
		}
		cout << "YES" << endl;
	}
    return 0;
}

