#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back

typedef long long lint;
typedef vector<int> vi;
typedef vector<string> vs;
const int INF = 0x7fffffff;

int n;
vector<vi> g;

vi getP(int v)
{
	vi x;
	for(int i = 1; i <= n; ++i)
		if(g[i][v])
		{
			x.pb(i);
			vi x1 = getP(i);
			for(int k = 0; k < x1.size(); ++k)
				x.pb(x1[k]);
		}
	return x;
}


int Solution()
{
	cin >> n;
	g.clear();
	g.resize(0);
	g.resize(n + 1, vi(n + 1, 0));
	for(int i = 1; i <= n; ++i)
	{
		int m;
		cin >> m;
		for(int j = 0; j < m; ++j)
		{
			int x;
			cin >> x;
			g[i][x] = 1;
		}
	}

	bool ans = false;
	for(int i = 1; i <= n; ++i)
	{
		bool flag = true;
		for(int j = 1; j <= n; ++j)
			if(g[i][j])
			{
				flag = false;
				break;
			}
		
		if(flag)
		{
			vi x = getP(i);
			sort(x.begin(), x.end());
			if(x.size())
				for(int j = 0; j < x.size() - 1; ++j)
					if(x[j] == x[j + 1])
					{
						ans = true;
						break;
					}
		}
		if(ans)
			break;
	}

	if(ans) 
		cout << "Yes";
	else
		cout << "No";
	return 0;
}

#define debug 1

int main()
{
#ifdef debug
	freopen("A-small-attempt2.in", "r", stdin);
	freopen("A-small-attempt2.out", "w", stdout);
#endif
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
	{
		cout << "Case #" << i << ": ";
		Solution();
		cout << endl;
	}
	return 0;
}
