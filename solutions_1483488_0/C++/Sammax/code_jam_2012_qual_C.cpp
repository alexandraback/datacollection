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

int t, ans, a, b, n, f;
int d[8];
set <pnt> ss;
int main() 
{
	ifd();
	
	d[0] = 1;
	FOR(i, 1, 8)
		d[i] = d[i - 1] * 10;

	cin >> t;
	FOR(cas, 1, t + 1) {
		ans = 0;
		cin >> a >> b;
		ss.clear();
		FOR(i, a, b + 1) {
			VI c;
			f = i;
			do {
				c.push_back(f % 10);
				f /= 10;
			} while (f);
			n = c.size();
			FOR(j, 0, n - 1) {
				int m = 0;
				int dd = d[n - 1];
				for (int k = j; k >= 0; k--) {
					m += c[k] * dd;
					dd /= 10;
				}
				for (int k = n - 1; k > j; k--) {
					m += c[k] * dd;
					dd /= 10;
				}
				if (m > i && m <= b) {
					ss.insert(mp(i, m));
				}
			}
		}
		printf("Case #%d: %d\n", cas, ss.size());
	}

	tme();
	return 0;
}