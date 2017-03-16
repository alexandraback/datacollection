#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define DEBUG(x) cout << ">>> " << #x << " = " << (x) << endl;
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define REP(i,a) for(int i=0;i<(a);++i)

#define INF (1<<29)
typedef long long ll;

int T, N;
ll S[600];

ll sums[100000*30];

int main() {
	scanf("%d", &T);
	REP(t,T) {
		REP(i,100000*30) sums[i] = -1;
		scanf("%d", &N);
		REP(i,N) scanf("%lld", S+i);
		unsigned int i = 0;
		unsigned int f1 = -1U, f2 = -1U;
		while (i < (1<<N)) {
			ll sum = 0;
			unsigned int mask = 1<<(N-1);
			int j = 0;
			while (mask) {
				if (i&mask) sum += S[j];
				mask >>= 1; ++j;
			}
			if (sums[sum] == -1) sums[sum] = i;
			else {
				f1 = sums[sum]; f2 = i; break;
			}
			++i;
		}
		printf("Case #%d:\n", t+1);
		if (f1 == -1U) printf("Impossible\n");
		else {
			unsigned int comm = f1 & f2;
			f2 = f2 & ~comm;
			f1 = f1 & ~comm;
			bool first = true;
			unsigned int mask = 1<<(N-1);
			int j = 0;
			while (mask) {
				if (f1&mask) {
					if (!first) printf(" ");
					else first = false;
					printf("%lld", S[j]);
				}
				mask >>= 1; ++j;
			}
			printf("\n");
			first = true;
			mask = 1<<(N-1);
			j = 0;
			while (mask) {
				if (f2&mask) {
					if (!first) printf(" ");
					else first = false;
					printf("%lld", S[j]);
				}
				mask >>= 1; ++j;
			}
			printf("\n");
		}
	}
	return 0;
}
