#include <cstdio>
#include <iostream>
#include <cstring>
#include <cctype>
#include <cmath>
#include <stack>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
#define INF 0x3f3f3f3f
#define REP(i,n) for(int i=0; i<(int)n; i++)
typedef long long int64;

int main() {
	int nt;

	scanf("%d",&nt);
	REP(ct,nt) {
		int64 r,t;
		scanf("%lld%lld",&r,&t);

		int64 s0=2*r+1;
		int64 es=0, di=min((int64)sqrt(t)*2,t/s0)+1;
		while (di>es) {
			int64 me=(es+di+1)/2;
			if (me*s0+2*(me*(me-1)) <= t) es=me;
			else di=me-1;
		}

		printf("Case #%d: %lld\n",ct+1,es);
	}
	return 0;
}
