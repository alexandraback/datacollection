#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <bitset>		//UWAGA - w czasie kompilacji musi byc znany rozmiar wektora - nie mozna go zmienic
#include <cassert>
#include <iomanip>		//do setprecision
#include <ctime>
#include <complex>
using namespace std;

#define FOR(i,b,e) for(int i=(b);i<(e);++i)
#define FORQ(i,b,e) for(int i=(b);i<=(e);++i)
#define FORD(i,b,e) for(int i=(b)-1;i>=(e);--i)
#define REP(x, n) for(int x = 0; x < (n); ++x)

#define ST first
#define ND second
#define PB push_back
#define MP make_pair
#define LL long long
#define ULL unsigned LL
#define LD long double

const double pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342;

bool check(LL r, LL t, LL s)
{
	LL a1 = 1+2*(r-1);
	return (2*a1+(s-1)*4)*s/2 <= t && (2*a1+(s-1)*4)*s/2 > 0;
}

int result(LL r, LL t)
{
	int k = min(t/(1.0*r),sqrt(1.0*t))+1;
	int p = 1;	
	while(p+1 < k)
	{
		LL s = (p+k)/2;
		if(check(r,t,s)) p = s;
		else k = s;
	}
	return p;
}

int main()
{
	int T;
	scanf("%d", &T);
	REP(c,T)
	{		
		LL r, t;
		scanf("%lld %lld", &r, &t);r++;
		printf("Case #%d: %d\n", c+1, result(r,t));
	}
	return 0;
}