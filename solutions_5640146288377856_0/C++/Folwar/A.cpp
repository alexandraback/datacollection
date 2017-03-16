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

#define REP(i,N) for (int i = 0; i < (N); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, b, a) for (int i = (b) - 1; i >= a; i--)
#define DP(arg...) fprintf(stderr, ## arg) //COMPILER SPECIFIC!!!

typedef long long ll;

int T;
int R,C,W;

// C, W
int DC[21][21];



void solve(int _case) {
	scanf("%d%d%d", &R, &C, &W);

	int sol = (C / W) * R;
	sol += W;
	if (C % W == 0) sol--;

	printf("Case #%d: %d\n", _case, sol);
}

int main() {
	scanf("%d", &T);
	REP(t,T) solve(t+1);
	return 0;
}
