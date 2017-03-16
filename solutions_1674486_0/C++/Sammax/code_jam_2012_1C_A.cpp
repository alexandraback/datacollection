#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <complex>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <complex>
#include <stdio.h>
#include <cstdlib>
#include <memory.h>
#ifdef SAMMAX
#include <ctime>
clock_t beg;
#endif

const double pi = 3.1415926535897932384626433832795;

//#pragma comment(linker, "/stack:1000000000")
#define sz size()
#define mp make_pair
#define pb push_back
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define MEMS(a,b) memset(a,b,sizeof(a))
#define sqr(a) ((a)*(a))
#define HAS(a,b) ((a).find(b)!=(a).end())
#define MAX(a,b) ((a>=b)?a:b)
#define MIN(a,b) ((a<=b)?a:b)
#define ABS(a) ((a<0)?-(a):a)
#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define FORD(i,a,b) for (int i=(a);i>(b);--i)
#define VVI vector < vector <int> >
#define VI vector <int>
#define LL long long
#define U unsigned
#define pnt pair <int,int>
int gcd(int a,int b){if (a==0) return b;return gcd(b%a,a);}

using namespace std;

void ifd() 
{
#ifdef SAMMAX 
	freopen("in.txt","r",stdin); 
	freopen("out.txt","w",stdout); 
	beg = clock();
#else

#endif
}
void tme()
{
#ifdef SAMMAX
	fprintf(stderr,"*** Total time: %.3lf ***\n",1.0*(clock()-beg)/CLOCKS_PER_SEC);
#endif
}

int t, n, m, p;
VVI g;
bool f;
int tm[1010][1010];
void dfs(int v, int start) {
	if (start != v)
		tm[start][v]++;
	FOR(i, 0, g[v].size()) {
		dfs(g[v][i], start);
	}
}
int main() 
{
	ifd();
	
	cin >> t;
	FOR(cas, 1, t + 1) {
		cin >> n;
		g.clear();
		g.resize(n);
		f = false;
		FOR(i, 0, 1010)
			FOR(j, 0, 1010)
				tm[i][j] = 0;
		FOR(i, 0, n) {
			cin >> m;
			FOR(j, 0, m) {
				cin >> p;
				g[i].push_back(p - 1);
			}
		}
		printf("Case #%d: ", cas);
		FOR(i, 0, n) {
			dfs(i, i);
		}
		FOR(i, 0, 1010)
			FOR(j, 0, 1010)
				if (tm[i][j] > 1) {
					f = true;
					break;
				}
		if (f)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}

	tme();
	return 0;
}