#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <queue>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <bitset>
#include <ctype.h>
#include <cassert>
#include <stack>

using namespace std;


#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define left _left

template < typename T > T abs(T x)
{
	return x > 0 ? x : -x;
}

const int maxn = 55;

int g[maxn][maxn];
string str[maxn];

int main()
{
	srand(time(NULL));
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	
	int t;
	scanf("%d\n", &t);
	
	for (int tt = 1; tt <= t; tt++)
	{
		int n, m;
		scanf("%d %d\n", &n, &m);
		
		for (int i = 0; i < n; i++)
		{
			cin >> str[i];
		}
		
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				g[i][j] = 0;
			}
		}
		
		for (int i = 0; i < m; i++)
		{
			int u, v;
			cin >> u >> v;
			u--;
			v--;
			
			g[u][v] = g[v][u] = 1;
		}
		
		int p[9];
		
		for (int i = 0; i < n; i++)
			p[i] = i;
			
		string ans = "";
		for (int i = 0; i < n; i++)
			ans += "99999";
			
		do {
			string curr = str[p[0]];
			
			vector < int > s;
			s.pb(p[0]);
			
			bool can = true;
			
			for (int i = 1; i < n; i++)
			{
				while (!s.empty() && !g[s.back()][p[i]]) s.pop_back();
				if (s.empty())
				{
					can = false;
					break;
				}
				s.pb(p[i]);
				curr += str[p[i]];
			}
			
			if (can)
			{
				ans = min(ans, curr);
			}
		} while (next_permutation(p, p + n));
		
		cout << "Case #" << tt << ": " << ans << endl;
	}
	
	
	return 0;
}




