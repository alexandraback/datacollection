/*************************************************************************

       Author:            palayutm
       Created Time :     Sun 08 May 2016 06:58:10 PM CST

       File Name:         e.cc
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
typedef pair<int, int> PII;
typedef unsigned long long ull;

const ll mod = 1e9+7;
const ll LINF = 1e18;
const int INF = 1e9;
const double EPS = 1e-8;

/**************************************END************************************/

int ans = 0;
int X, Y, Z, K;

int sum[355];
vector<pair<PII, int> > vec;
vector<int> ttt;
int a[150];
int b[150];
int c[150];

void dfs (int p, vector<int>& ans){
	if (SIZE(ans) + SIZE(vec)-p < SIZE (ttt)){
		return;
	}
	if (p == SIZE (vec)){
		ttt = ans;
		return;
	}
	int x = vec[p].first.first, y = vec[p].first.second, z = vec[p].second;
	int xx = x*11+y, yy = x*11+z, zz = y*11+z;
	if (a[xx] < K && b[yy] < K && c[zz] < K){
		a[xx] ++;
		b[yy] ++;
		c[zz] ++;
		ans.PB (p);
		dfs (p+1, ans);
		a[xx] --;
		b[yy] --;
		c[zz] --;
		ans.pop_back();
	}
	dfs(p+1, ans);
}

int main (){
	int T;
	cin >> T;
	FOR (cas, 1, T){
		cin >> X >> Y >> Z >> K;
		ans = 0;
		clr (a, 0);
		clr (b, 0);
		clr (c, 0);
		vec.clear();
		ttt.clear();
		FOR (i, 1, X){
			FOR (j, 1, Y){
				FOR (k, 1, Z){
					vec.PB (MP (MP(i, j), k));
				}
			}
		}
		vector<int> txx;
		dfs (0, txx);
		printf ("Case #%d: %d\n", cas, SIZE (ttt));
		FOR (i, 0, SIZE (ttt)-1){
			int p = ttt[i];
			cout << vec[p].first.first << " " << vec[p].first.second << " " << vec[p].second << endl;
		}
	}
}

