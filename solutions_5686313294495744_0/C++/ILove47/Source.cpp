#include <ctime>
#include <bitset>
#include <iterator>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>
#include <fstream>
using namespace std;


#define PB	push_back
#define MP  make_pair
#define ALL(a) 	(a).begin(), (a).end()
#define FILL(a,v) memset(a,v,sizeof(a))

#define MIN(A, B) ((A) < (B) ? (A) : (B))
#define MAX(A, B) ((A) > (B) ? (A) : (B))
#define ABS(A) ((A) < 0 ? (-(A)) : (A))
#define SQR(x) (x)*(x)

#define y1 asdfasdf

typedef long long ll;

const double PI = acos(-1.0);
const double EPS = 1e-7;
const int MOD = 1000000007;
const int INF = 2000000000;

int n;
map<string, int> m;
int a[16][2];

bool check(int mask, int pos)
{
	bool aa = false;
	bool bb = false;
	for (int i = 0; i < n; ++i)
	{
		if (!(mask & (1 << i)))
		{
			if (a[pos][1] == a[i][1])
				aa=true;
			if (a[pos][0] == a[i][0])
				bb=true;
		}
	}
	return aa && bb;
}

int solveFor(int mask)
{
	int cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		if (mask & (1 << i))
		{
			if (check(mask, i))
				++cnt;
		}
	}
	return cnt;
}

void solve()
{
	m.clear();
	
	cin >> n;
	int cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			string x;
			cin >> x;
			if (m.find(x) == m.end())
			{
				m[x] = cnt++;
			}
			a[i][j] = m[x];
		}
	}

	int res = 0;
	int N = (1 << n);
	for (int mask = 0; mask < N; ++mask)
	{
		res = max(res, solveFor(mask));
	}
	cout << res << endl;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int tests;
	scanf("%d", &tests);

	for (int test = 1; test <= tests; ++test)
	{
		printf("Case #%d: ", test);
		solve();
	}
	return 0;
}
