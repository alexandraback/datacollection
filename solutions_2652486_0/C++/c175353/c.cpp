#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define FOR(i,a,b) for(int i=int(a);i<=int(b);++i)
#define REP(i,n) FOR(i,0,(n)-1)
#define debug(x) cout<<(#x)<<":"<<x<<endl
#define PB push_back
#define MP make_pair
typedef long long int64;

#define N 10010
int a[3], ans[3], d[7], e[7];

int main() {
	puts("Case #1:");
	int nT, r, n, m, k;
	scanf("%d%d%d%d%d", &nT, &r, &n, &m, &k);
	while (r--) {
		REP(i, k) scanf("%d", &e[i]);
		sort(e, e+k);
		int itr = 50000;
		double maP = 0;
		while (itr--) {
			REP(i, n) a[i] = rand()%(m-1)+2;
			map<int,int> e2cnt;
			REP(b, 1<<n) {
				int mul = 1;
				REP(i, n) if (b & (1<<i)) mul *= a[i];
				++e2cnt[mul];
			}
			double prob = 1;
			REP(i, k) prob *= 1.*e2cnt[e[i]] / (1<<n);
			if (prob > maP) {
				maP = prob;
				memcpy(ans, a, sizeof(a));
			}
		}
		REP(i, n) printf("%d", ans[i]);
		puts("");
	}
}

