#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <iostream>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <algorithm>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <string>

#ifndef ONLINE_JUDGE
	#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#else
	#define DEBUG(x) do {} while(0);
#endif

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define FOR(i, A, N) for(int (i) = (A); (i) < (N); (i)++)
#define REP(i, N) for(int (i) = 0; (i) < (N); (i)++)

using namespace std;
typedef long long ll;
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }

int n,m;
int T;
int F[1111];
int perm[11];

void solve() {
	scanf("%d", &n);
	REP(i, n) {
		scanf("%d", F+i);
		F[i]--;
	}
	int ans = 0;
	REP(i, 1<<n) {
		if(i == 0)
			continue;
		vector<int> V;
		REP(j, n) if(i&(1<<j)) V.pb(j);
		if(V.size()==1)
			continue;
		REP(j, V.size()) perm[j] = j;
		do {
			bool ok = true;
			REP(k, V.size()) {
				int prev = V[perm[(k-1+(int)V.size())%V.size()]];
				int nxt = V[perm[(k+1+(int)V.size())%V.size()]];
				if(prev != F[V[perm[k]]] && nxt != F[V[perm[k]]]) {
					ok = false;
					break;
				}
			}
			if(ok) {
				ans = max(ans, (int)V.size());
				break;
			}
		} while(next_permutation(perm, perm+V.size()));
	}
	printf("%d", ans);

}

int main() {
	scanf("%d", &T);
	REP(testc, T) {
		printf("Case #%d: ", testc+1);
		solve();
		printf("\n");
	}
	return 0;
}
