/*
 * =====================================================================================
 *
 *       Filename:  b.cc
 *        Version:  1.0
 *        Created:  05/09/2015 02:50:16 PM
 *       Revision:  none
 *       Compiler:  GNU C++
 *
 *                     I  don't  want  to  be  alone.
 *
 * =====================================================================================
 */
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define PB              push_back
#define SIZE(x)         (int)x.size()
#define clr(x,y)        memset(x,y,sizeof(x))
#define MP(x,y)         make_pair(x,y)
#define RS(n)           scanf ("%s", n)
#define ALL(t)          (t).begin(),(t).end()
#define FOR(i,n,m)      for (int i = n; i <= m; i ++)
#define ROF(i,n,m)      for (int i = n; i >= m; i --)
#define IT              iterator
#define FF              first
#define SS              second

typedef long long               ll;
typedef unsigned int            uint;
typedef unsigned long long      ull;
typedef vector<int>             vint;
typedef vector<string>          vstring;
typedef pair<int, int>          PII;

void RI (int& x){
	x = 0;
	char c = getchar ();
	while (!(c>='0' && c<='9' || c=='-'))     c = getchar ();
	bool flag = 1;
	if (c == '-'){
		flag = 0;
		c = getchar ();
	}
	while (c >= '0' && c <= '9'){
		x = x * 10 + c - '0';
		c = getchar ();
	}
	if (!flag)      x = -x;
}
void RII (int& x, int& y){RI (x), RI (y);}
void RIII (int& x, int& y, int& z){RI (x), RI (y), RI (z);}
void RC (char& c){
	c = getchar ();
	while (c == ' '||c == '\n')     c = getchar ();
}
char RC (){
	char c = getchar ();
	while (c == ' '||c == '\n')     c = getchar ();
	return c;
}

/**************************************END define***************************************/

const ll mod = 1e9+7;
const ll LINF = 1e18;
const int INF = 1e9;
const double EPS = 1e-8;

const int N = 100005;

vector<int> g[N];
int a[N];
ll st[N], ed[N], sum[N];

void init (){
	clr (a, 0);
	FOR (i, 0, N-1)	g[i].clear ();
	clr (st, 0);
	clr (ed, 0);
	clr (sum, 0);
}

void dfs (int u, int fa){
	sum[u] = a[u];
	FOR (i, 0, SIZE (g[u])-1){
		int v = g[u][i];
		if (v == fa)	continue;
		dfs (v, u);
		ed[u] = max (ed[u], max (ed[v]+1, sum[v]));
		sum[u] += sum[v];
	}
}

int main (){
	int T;
	RI (T);
	FOR (cas, 1, T){
		init ();
		int n, s;
		RII (n, s);
		FOR (i, 1, n-1){
			int u, v;
			RII (u, v);
			g[u].PB (v);
			g[v].PB (u);
		}
		FOR (i, 1, n){
			RI (a[i]);
		}
		dfs (s, -1);
		cout << ed[3] << endl;
		cout << ed[4] << endl;
		printf ("Case #%d: ", cas);
		cout << ed[s] << endl;
	}
}


