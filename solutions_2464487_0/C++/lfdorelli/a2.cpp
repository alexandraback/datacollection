#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <list>
#include <set>
#include <queue>
#include <gmpxx.h>

using namespace std;

typedef long long int LL;
typedef pair<int,int> pii;
typedef long double T;

#define F first
#define S second
#define pb push_back
#define mp make_pair

#define pi acos(-1)

T  need(LL n, LL r)
{
	return pi * (n-1) * n * (2*n+2*r+1) / 2.0;

}

bool can(LL n, T has, LL r)
{
	return need(n, r) <= has;
}

int main (void)
{
	int C; cin >> C;

	for(int cas = 1; cas <= C; ++cas)
	{
		long double r, t;

		cin >> r >> t;

		long long int res = 0;
		long double area = 0.0;

		while(1)
		{
			area += (2*r+1) ;
			r += 2.0;
			if(area <= t) res++;
			else break;
		} 

		printf("Case #%d: %lld\n", cas, res);
	}
	


	return 0;
}
