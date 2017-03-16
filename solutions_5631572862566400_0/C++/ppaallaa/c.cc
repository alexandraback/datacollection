/*************************************************************************

       Author:            palayutm
       Created Time :     Sat 16 Apr 2016 10:13:40 AM CST

       File Name:         c.cc
       Description:       new style, new life

 ************************************************************************/
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define PB push_back
#define SIZE(x) (int)x.size()
#define clr(x,y) memset(x,y,sizeof(x))
#define MP(x,y) make_pair(x,y)
#define ALL(t) (t).begin(),(t).end()
#define FOR(i,n,m) for (int i = n; i <= m; i ++)
#define ROF(i,n,m) for (int i = n; i >= m; i --)
#define RI(x) scanf ("%d", &(x))
#define RII(x,y) RI(x),RI(y)
#define RIII(x,y,z) RI(x),RI(y),RI(z)

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const ll mod = 1e9+7;
const ll LINF = 1e18;
const int INF = 1e9;
const double EPS = 1e-8;

/**************************************END************************************/

int maxcir = 0;

int vis[1005];
int g[1005];
vector<int> gr[1005];
int in[1005];
int dis[1005];

void init (){
	clr (vis, 0);
	clr (g, 0);
	FOR (i, 1, 1000){
		gr[i].clear ();
	}
	clr (in, 0);
	maxcir = 0;
}

void dfs (int u, int dep){
	vis[u] = dep;
	if (vis[g[u]] == 0){
		dfs (g[u], dep+1);
	}else{
		maxcir = max (maxcir, dep - vis[g[u]] + 1);
	}
}

int solve2 (int a1, int a2){
	clr (dis, 0);
	dis[a1] = 1;
	dis[a2] = 2;
	queue<int> q;
	q.push (a2);
	int ans = 2;
	while (SIZE (q)){
		int u = q.front ();
		q.pop ();
		FOR (i, 0, SIZE (gr[u])-1){
			int v = gr[u][i];
			if (dis[v] == 0){
				dis[v] = dis[u] + 1;
				ans = max (ans, dis[v]);
				q.push (v);
			}
		}
	}
	return ans;
}

int main (){
	int T;
	cin >> T;
	FOR (cas, 1, T){
		init ();
		int n;
		cin >> n;
		FOR (i, 1, n){
			int t;
			cin >> t;
			g[i] = t;
			in[t] ++;
			gr[t].PB (i);
		}
		FOR (i, 1, n){
			if (!vis[i] && in[i] == 0){
				dfs (i, 1);
			}
		}
		FOR (i, 1, n){
			if (!vis[i]){
				dfs (i, 1);
			}
		}
		int ans = 0;
		FOR (i, 1, n){
			if (g[ g[i] ] == i){
				//ans = max (ans, solve (i, g[i]));
				//ans = max (ans, solve (g[i], i, gr));
				ans = max (ans, solve2 (g[i], i)+solve2 (i, g[i]) - 2);
			}
		}	
		cout << "Case #" << cas << ": " << max (ans, maxcir) << endl;
	}
}

