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
int a[12], ans[12], d[12], e[12], bi[5000], nb;

int main() {
	puts("Case #1:");
	int nT, r, n, m, k;
	scanf("%d%d%d%d%d", &nT, &r, &n, &m, &k);
	nb = 0;
	REP(b, 1 << n) {
		if (rand() % 2 == 0) bi[nb++] = b;
	}
	while (r--) {
		REP(i, k) scanf("%d", &e[i]);
		sort(e, e+k);
		int itr = 100;
		double maP = 0;
		while (itr--) {
			REP(i, n) {
				bool ok = 0;
				while (!ok) {
					a[i] = rand()%(m-1)+2;
					REP(j, k) if (e[k] % a[i] == 0) {ok = 1; break;}
				}
			}
			map<int,int> e2cnt;
			REP(j, nb) {
				int b = bi[j];
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

