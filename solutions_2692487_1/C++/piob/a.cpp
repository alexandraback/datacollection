#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iostream>
#define REP(a,b) for(int a=0; a<(b); ++a)
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FWDS(a,b,c,d) for(int a=(b); a<(c); a+=d)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define FE(a,b) for(typeof((b).end()) a=(b).begin(); a!=(b).end(); ++a)
#define PII pair<int, int>
#define PLL pair<long long, long long>
#define x first
#define y second

using namespace std;

typedef long long LL;

int n;
LL a;
LL T[110];

int solve(){
	if(a == 1) return n;
	int r = n;
	LL c = a;
	int d = 0;
	FWD(i,0,n){
		while(c <= T[i]){
			++d;
			c += (c-1);
		}
		c += T[i];
		r = min(r, d + n - i - 1);
	}
	return r;
}

int main(){
	int Z;
	scanf("%d", &Z);
	FWD(z,1,Z+1){
		printf("Case #%d: ", z);
		scanf("%lld %d", &a, &n);
		FWD(i,0,n)
			scanf("%lld", &T[i]);
		sort(T, T+n);
		printf("%d\n", solve());
	}	
	return 0;
}

