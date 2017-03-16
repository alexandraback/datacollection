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
#define REP(i,n) for(int64 i=0; i<(int64)n; i++)
typedef long long int64;
#define MAXN 100100

int64 ord[MAXN], v[MAXN];
int64 ra[MAXN], rb[MAXN];

bool cmpo(int64 a, int64 b) {
	return v[a]>v[b];
}

int main() {
	int64 nt;

	scanf("%lld",&nt);
	REP(ct,nt) {
		int64 e,r,n;
		scanf("%lld%lld%lld",&e,&r,&n);

		set<int64> s,sn;
		rb[0]=e; ra[n+1]=0;
		s.insert(0);
		sn.insert(0);
		s.insert(n+1);
		sn.insert(-n-1);
		
		for (int64 i=1;i<=n;i++) {
			scanf("%lld",&v[i]);
			ord[i-1]=i;
		}

		sort(ord,ord+n,cmpo);

		int64 res=0;
		REP(i,n) {
			int64 k=ord[i];
			int64 kd=*s.lower_bound(k);
			int64 ke=-*sn.lower_bound(-k);

			ra[k]=min(e*1LL,rb[ke]+(k-ke)*r);
			rb[k]=max(0LL,ra[kd]-(kd-k)*r);
			res+=(ra[k]-rb[k])*v[k];

			s.insert(k);
			sn.insert(-k);
		}
			
		printf("Case #%lld: %lld\n",ct+1,res);
	}
	return 0;
}

