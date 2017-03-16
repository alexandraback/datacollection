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

int memo[100010], A, B;
double p[100010], pp[100010];


int main()
{
	int cases; scanf("%d", &cases); 
	FOR(c, 1, cases + 1)
	{
		scanf("%d %d", &A, &B);
		double ret = B + 2.0; double x = 1.0;
		FOR(i, 0, A) scanf("%lf", &p[i]);
		FOR(i, 0, A) x *= p[i], pp[i] = x;
		memset(memo, -1, sizeof memo);
		printf("Case #%d: ", c);
		double c = 1.0, nc;
		FOR(b, 0, A + 1)
		{
			c = pp[A - b];
			nc = 1.0 - c;
			ret = min(ret, c * (2 * b + B - A + 1) + nc * (2 * b + B - A + 1 + B + 1));
		}
		printf("%lf\n", ret);
	}
	return 0;
}