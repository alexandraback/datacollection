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

int d[20];

bool chk(int64 x) {
	int qd=0;

	for (; x>0; x/=10)
		d[qd++]=x%10;

	REP(i,qd/2)
		if (d[i]!=d[qd-1-i])
			return 0;

	return 1;
}

int64 res[1001000];

int main() {
	int nt;
	int64 a,b;

	int qr=0;
	REP(x,10000001) {
		if (!chk(x)) continue;
		int64 xs=x*1LL*x;
		if (chk(xs)) res[qr++]=xs;
	}
		
	scanf("%d",&nt);
	REP(ct,nt) {
		scanf("%lld%lld",&a,&b);
		printf("Case #%d: %d\n",ct+1,lower_bound(res,res+qr,b+1)-lower_bound(res,res+qr,a));
	}
	return 0;
}

