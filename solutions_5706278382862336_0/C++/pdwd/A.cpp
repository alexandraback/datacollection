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

LL GCD(LL a, LL b) { return b ? GCD(b, a%b) : a; }

int go()
{
	return 0;
}

char s[200];

int go(LL P, LL Q, int left)
{
	if((P == 1 && Q == 1) || (P == 0 && Q == 1)) return 0;
	if(!left)
	{
		return -1;
	}
	LL D;
	int res = -1;
	FORQ(i,1,left)
	{
		P *= 2;
		D = GCD(P,Q);
		P /= D;
		Q /= D;
		if(P >= Q)
		{
			res = i;
			return go(P-Q,Q,left-i) == -1 ? -1 : res;
		}
	}
	return res;
}

int main()
{
	int T;
	scanf("%d", &T);
	REP(c,T)
	{
		scanf("%s", s);
		LL P = 0, Q = 0;
		int n = strlen(s), br = 0;
		REP(i,n)
			if(s[i] == '/')
			{
				br = i;
				LL mn = 1;
				FORD(j,i,0)
				{
					P += mn*(LL)(s[j]-'0');
					mn *= 10;
				}
				break;
			}
		LL mn = 1;
		FORD(j,n,br+1)
		{
			Q += mn*(LL)(s[j]-'0');
			mn *= 10;
		}
		int res = go(P,Q,40);
		printf("Case #%d: ", c+1);
		if(res > -1) printf("%d\n", res);
		else printf("impossible\n");
	}
	return 0;
}