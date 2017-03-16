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

int T, N, A;
int S[120];

int can[120][120];

int main() {
	scanf("%d", &T);
	REP(t,T) {
		scanf("%d%d", &A, &N);
		REP(i,N) scanf("%d", S+i);
		sort(S, S+N);
		//REP(i,N) printf("%d ", S[i]);
		//printf("\n");
		REP(i,120) can[0][i] = 0;
		can[0][0] = A;
		FOR(step,1,N) {
			int nSize = S[step-1];
			can[step][0] = 0;
			FOR(i,1,119) can[step][i] = can[step-1][i-1];
			REP(i,120) {
				int size = can[step-1][i];
				if (!size) continue;
				int ops = i;
				while (ops < 120) {
					if (size > nSize) {
						can[step][ops] = max(can[step][ops], size+nSize);
					}
					++ops;
					size += size-1;
				}
			}
		}
		/*
		REP(step,N+1) {
			REP(i,10) printf("%d ", can[step][i]);
			printf("\n");
		}*/
		REP(i,120) {
			if (can[N][i]) {
				printf("Case #%d: %d\n", t+1, i);
				break;
			}
		}
	}
	return 0;
}
