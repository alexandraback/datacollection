#include <cmath>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <cctype>
#include <stack>
using namespace std;

typedef long long int int64;

#define EPS 10e-9
#define INF 0x3f3f3f3f
#define REP(i,n) for(int i=0; i<(n); i++)

int64 r, x;

int main()
{	
	int t;
	scanf("%d", &t);
	REP(k, t) {
		scanf("%lld %lld", &r, &x);
		int64 i = 1;
		int64 res = 0;
		int64 h = x;
		while (1) {
			int64 y = (i*i) - ((i-1) * (i-1)) + 2*r;
			if (y > h) break;
			res++;
			h = h - y;
			i = i + 2;
		}
		printf("Case #%d: %lld\n", k+1, res);
	}
	return 0;
}