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
#include <ctime>
#include <stack>
#ifdef SAMMAX
#include <ctime>
clock_t beg;
#endif

const double pi = 3.1415926535897932384626433832795;
double EPS = 10e-6;
const int INF = 2000000000;

//#pragma comment(linker, "/stack:1500000000")
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
LL gcd(LL a, LL b){if (a==0) return b;return gcd(b%a,a);}

using namespace std;

void ifd() 
{
#ifdef SAMMAX
	freopen("in.txt", "r", stdin); 
	freopen("out.txt", "w", stdout); 
	beg = clock();
#else
	//freopen("robots.in", "r", stdin); 
	//freopen("robots.out", "w", stdout);
#endif	
}
void tme()
{
#ifdef SAMMAX
	fprintf(stderr,"*** Total time: %.3lf ***\n",1.0*(clock()-beg)/CLOCKS_PER_SEC);
#endif
}

int t, n, m, k;
int d[111][111];
int main()  
{
    ifd();
	
	cin >> t;
	FOR(cs, 1, t + 1) {
		cin >> n >> m;
		
		FOR(i, 0, 111)
			FOR(j, 0, 111)
				d[i][j] = 0;

		FOR(i, 0, n)
			FOR(j, 0, m) {
				cin >> k;
				d[i][j] = k;
			}
		
		bool ok = true;
		FOR(i, 0, n)
			FOR(j, 0, m) {
				k = d[i][j];
				bool ii = true;
				bool jj = true;
				FOR(p, 0, m)
					ii &= (d[i][p] <= k);
				FOR(p, 0, n)
					jj &= (d[p][j] <= k);
				ok &= (ii || jj);
			}
		
		if (ok)
			printf("Case #%d: YES\n", cs);
		else
			printf("Case #%d: NO\n", cs);
	}


	tme();
    return 0;
}
