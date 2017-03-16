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
	//freopen("in.txt","r",stdin); 
	//freopen("out.txt","w",stdout); 
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

int t, n, m;
vector < pair <U LL, int> > A, B;
U LL dp[105][105], dp2[105][105];
U LL R(int a, int b);
U LL R2(int a, int b) {
	if (a >= n || b >= m)
		return 0;
	U LL res = 0;
	if (dp2[a][b] != -1)
		return dp2[a][b];
	U LL ct = B[b].first, type = B[b].second, profit = 0;
	FOR(i, a + 1, n + 1) {
		if (type == A[i - 1].second) {
			if (ct >= A[i - 1].first) {
				profit += A[i - 1].first;
				ct -= A[i - 1].first;
			}
			else {
				profit += ct;
				ct = 0;
				res = MAX(res, profit + R(i - 1, b + 1) - R2(i, b + 1));
			}
		}
		res = MAX(res, profit + R2(i, b + 1));
	}
	res = MAX(res, R2(a, b + 1));
	return dp2[a][b] = res;
}
U LL R(int a, int b) {
	if (a >= n || b >= m)
		return 0;
	U LL res = 0;
	if (dp[a][b] != -1)
		return dp[a][b];
	U LL ct = A[a].first, type = A[a].second, profit = 0;
	FOR(i, b + 1, m + 1) {
		if (type == B[i - 1].second) {
			if (ct >= B[i - 1].first) {
				profit += B[i - 1].first;
				ct -= B[i - 1].first;
			}
			else {
				profit += ct;
				ct = 0;
				res = MAX(res, profit + R2(a + 1, i - 1));
			}
		}
		res = MAX(res, profit + R(a + 1, i));
	}
	res = MAX(res, R(a + 1, b));
	return dp[a][b] = res;
}
int main() 
{
	ifd();
	freopen("in.txt","r",stdin); 
	freopen("out.txt","w",stdout); 

	cin >> t;
	FOR(cas, 1, t + 1) {
		cin >> n >> m;
		A.resize(n);
		B.resize(m);
		A.clear(); B.clear();
		FOR(i, 0, n) {
			cin >> A[i].first >> A[i].second;
		}
		FOR(i, 0, m) {
			cin >> B[i].first >> B[i].second;
		}
		FOR(i, 0, 105)
			FOR(j, 0, 105)
				dp[i][j] = dp2[i][j] = -1;
		printf("Case #%d: ", cas);
		U LL res1 = R(0,0);
		FOR(i, 0, 105)
			FOR(j, 0, 105)
				dp[i][j] = dp2[i][j] = -1;
		cout << MAX(R2(0, 0), res1) << endl;
	}

	tme();
	return 0;
}