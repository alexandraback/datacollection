#include <ctime>
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
using namespace std;


#define PB	push_back
#define MP  make_pair
#define ALL(a) 	(a).begin(), (a).end()
#define FILL(a,v) memset(a,v,sizeof(a))

#define MIN(A, B) ((A) < (B) ? (A) : (B))
#define MAX(A, B) ((A) > (B) ? (A) : (B))
#define ABS(A) ((A) < 0 ? (-(A)) : (A))
#define SQR(x) (x)*(x)

const double PI = acos(-1.0);
const double EPS = 1e-7;

const int INF = 2000000000;

string s[74];
vector<vector<int> > g(74);


void solve()
{
	for (int i = 0; i < g.size(); ++i)
		g[i].clear();

	int n,m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		cin >> s[i];
	}
	string res = s[0];
	for (int i = 0; i < n; ++i)
	{
		if (s[i] > res)
			res = s[i];
	}
	res = res+res;
	for (int i = 0; i < m; ++i)
	{
		int x,y;
		cin >> x >> y;
		--x;
		--y;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	vector<int> perm;
	for (int i = 0; i < n; ++i)
		perm.push_back(i);
	do
	{
		string ss = s[perm[0]];
		bool ok = true;

		vector<int> v;
		v.push_back(perm[0]);

		for (int i = 1; i < n; ++i)
		{
			/*flight (i-1)->(i)*/
			if (v.size() < 1)
			{
				ok = false;
				break;
			}
			int p = v.back();
			bool canF = false;
			for (int j = 0; j < g[p].size(); ++j)
			{
				if (g[p][j] == perm[i])
				{
					canF = true;
					break;
				}
			}
			if (canF)
			{
				v.push_back(perm[i]);
				ss += s[perm[i]];
			}
			else
			{
				v.pop_back();
				--i;
				continue;
			}
		}

		if (ok && (ss < res))
			res = ss;
	}while(next_permutation(perm.begin(), perm.end()));
	cout << res;
}


int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; ++test)
	{
		cout << "Case #"<<test<<": ";
		solve();
		cout << endl;
	}





	return 0;
} 