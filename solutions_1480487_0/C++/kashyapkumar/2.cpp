/*********************************HEADER FILES************************************/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
#include <cassert>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define SZ(x) ((int)(x).size())
#define FORV(i,x) FOR(i,0,SZ(x))  
#define DBG(x) cout<<(#x)<<" : "<<(x)<<endl
#define PB push_back
#define ALL(x) x.begin(),x.end()

#define ACC(x) accumulate(ALL(x)) 
#define FORE(i,a,b) for(int i=(a);i<=(b);i++)
#define ROFE(i,a,b) for(int i=(b);i>=(a);i--)
#define MP make_pair
#define left(x) (x<<1)
#define right(x) (left(x)+1)
#define PI pair<int,int>
#define PD pair<double,double>
#define F first
#define S second 
#define LL long long
#define ULL unsigned long long
#define MAX 50010

double pts[100], tot, n;

bool ok(double x, int p, double rem)
{
	double req = 0.0;
	FOR(i, 0, n) if(i != p && pts[i] < x) req += (x - pts[i]);
	if(rem <= req) return true;
	return false;
}

double solve(int p)
{
	double lo = 0.0, hi = 1.0 * tot;
	FOR(i, 0, 100)
	{
		double mid = (lo + hi) / 2.0, rem = tot - mid;
		//printf("mid = %lf\n", mid);
		if(ok((double) (pts[p] + mid), p, (double)rem)) hi = mid;
		else lo = mid;
	}
	return lo / tot;
}

int main()
{
	int cases; scanf("%d", &cases); 
	FOR(c, 1, cases + 1)
	{
		scanf("%lf", &n); tot = 0;
		FOR(i, 0, n) scanf("%lf", &pts[i]), tot += pts[i];
		printf("Case #%d: ", c); //printf("tot = %d\n", tot);
		FOR(i, 0, n) printf("%lf ", solve(i) * 100); printf("\n");
	}
	return 0;
}