#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>

#include<algorithm>
#include<utility>
#include<string>

#include<deque>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>

using namespace std;

#define FOR(i,N) for (int i = 0; i < (N); i++)
#define FORI(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, b, a) for (int i = (b) - 1; i >= a; i--)
#define DP(arg...) fprintf(stderr, ## arg) //COMPILER SPECIFIC!!!


typedef long long ll;
typedef long double ld;

#define MAXFARM 10000

int T, t;

ld C, F, X;

void solve() {
	ld ans = 10000000000;

	for (int p = 0; p <= MAXFARM; p++) {
		ld mt = 0, mf = 2;
		FOR(x,p) {
			mt += C / mf;
			mf += F;
		}
		mt += X / mf;
		if (mt > ans) break;
		ans = min(ans, mt);
	}

	printf("Case #%d: %.7Lf\n", t+1, ans);

}

int main() {
	scanf("%d", &T);
	for (t = 0; t < T; t++) {
		scanf("%Lf%Lf%Lf", &C, &F, &X);
		solve();
	}

	return 0;
}
