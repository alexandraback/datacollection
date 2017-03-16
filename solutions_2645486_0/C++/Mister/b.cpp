#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <cmath>
#include <cstdio>
using namespace std;
int req[10005], after[10005], A[10005], V[10005], spend[10005];
bool cmp(int a,int b) {
	return V[a] > V[b];
}
int main() {
	int T;
	scanf("%d",&T);
	for(int cn=1;cn<=T;++cn) {
		int E,R,N;
		long long ans = 0;
		scanf("%d%d%d",&E,&R,&N);
		set<int> S;
		set<int>::iterator it;
		for(int i=1;i<=N;++i) {
			scanf("%d",&V[i]);
			A[i] = i;
		}
		sort(A+1,A+N+1,cmp);
		S.insert(0);
		S.insert(N+1);
		after[0] = E;
		req[N+1] = 0;
		for(int i=1;i<=N;++i) {
			int x = A[i];
			it = S.lower_bound(x); // first one larger than it
			int b = *it;
			--it;
			int a = *it;
			int maxe = min((long long)E,after[a]+(long long)R*(x-a));
			int minafter = max(0LL,req[b]-(long long)R*(b-x));
			after[x] = minafter;
			req[x] = maxe;
			spend[x] = (req[x] - after[x]);
			ans += (long long)V[x] * spend[x];
			S.insert(x);
		}
		printf("Case #%d: %lld\n",cn,ans);
	}
}
