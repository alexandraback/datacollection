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
double p[100010];

bool isSet(int mask, int i)
{
	if(mask & (1 << i)) return true;
	return false;
}

double solve()
{
	double ret = B + 2.0;
	FOR(b, 0, A + 1)
	{
		double tret = 0.0;
		FOR(mask, 0, (1 << A))
		{
			double tp = 1.0; int n = 0; bool cor = true;
			FOR(i, 0, A - b) cor &= isSet(mask, i);
			FOR(i, 0, A)
				if(isSet(mask, i)) tp *= p[i];
				else tp *= (1.0 - p[i]);
			n = 2 * b + B - A + 1;
			if(!cor) n += B + 1;
			tret += tp * n;
		}
		ret = min(ret, tret);
	}
	return ret;
}

int main()
{
	int cases; scanf("%d", &cases); 
	FOR(c, 1, cases + 1)
	{
		scanf("%d %d", &A, &B);
		FOR(i, 0, A) scanf("%lf", &p[i]);
		memset(memo, -1, sizeof memo);
		printf("Case #%d: ", c);
		printf("%lf\n", solve());
	}
	return 0;
}