#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <vector>
#include <list>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <bitset>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <climits>
#include <ctime>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define VAL(x) #x << " = " << (x) << "   "
#define SQR(a) ((a) * (a))
#define SZ(x) ((int) (x).size())
#define ALL(x) (x).begin(), (x).end()
#define CLR(x, a) memset(x, a, sizeof x)
#define FOREACH(i, x) for(__typeof((x).begin()) i = (x).begin(); i != (x).end(); i ++)
#define FOR(i, n) for (int i = 0; i < (n); i ++)
#define X first
#define Y second
#define EPS (1e-8)

//#define cin fin
//#define cout fout

//ifstream fin("problem.in");
//ofstream fout("problem.out");

const int MAXN = 10;

pair<string, int> s[MAXN];
bool mat[MAXN][MAXN];

int main ()
{
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	for (int o = 1; o <= tc; o ++)
	{
		CLR(mat, 0);

		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; i ++) cin >> s[i].X, s[i].Y = i;
		sort(s, s + n);

		for (int i = 0; i < m; i ++)
		{
			int x, y;
			cin >> x >> y; x --, y --;
			mat[x][y] = mat[y][x] = true;
		}

		cout << "Case #" << o << ": ";

		vector<int> v;
		for (int i = 0; i < n; i ++) v.pb(i);
		vector<int> stk;
		do
		{
			stk.clear();
			stk.pb(s[v[0]].Y);

			bool check = true;
			for (int i = 1; i < n; i ++)
			{
				while (SZ(stk))
				{
					if (mat[s[v[i]].Y][stk.back()]) break;
					stk.pop_back();
				}
				if (!SZ(stk)) 
				{
					check = false;
					break;
				}
				stk.pb(s[v[i]].Y);
			}

			if (check)
			{
				for (int i = 0; i < n; i ++)
					cout << s[v[i]].X;
				cout << endl;

				break;
			}
		}
		while (next_permutation(ALL(v)));
	}
	return 0;
}

