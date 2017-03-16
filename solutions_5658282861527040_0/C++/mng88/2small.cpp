#include <cstdio>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;
#define INF 2000000000
#define INFLL (1LL<<62)
#define SS ({int x;scanf("%d", &x);x;})
#define SSL ({lint x;scanf("%lld", &x);x;})
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i,m,n) for(int i=(m);i<(n);i++)
#define ull unsigned long long
#define lint long long
#define MX 10000001


int main() {
	
	int t,a,b,k;
	t=SS;	
	rept(testCase, 1, t+1) {

		a=SS;
		b=SS;
		k=SS;
		int ans = 0;
		rep(i,a) {
			rep(j,b) {
				if((i&j) <k)
					ans++;
			}
		}
		printf("Case #%d: %d\n",testCase, ans);
	}
	return 0;
}




