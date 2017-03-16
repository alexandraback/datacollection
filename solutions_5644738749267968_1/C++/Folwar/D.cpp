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

int N;
int t, T;

ld WN[2000], WK[2000];
bool crossed[2000];

void solve() {
	sort(WN, WN+N);
	sort(WK, WK+N);

	FOR(i,N) crossed[i] = false;
	
	int war = 0, dwar;
	int n = 0;
	for (int k = 0; k < N; k++) {
		if (WK[k] > WN[n]) n++;
		else war++;
	}

	bool ok = true;
	for (dwar = 1; dwar <= N && ok; dwar++) {
		for (int k = 0; k < dwar; k++)
			if (WN[N - dwar + k] < WK[k]) ok = false;		

	}
	if (ok == false) dwar--;
	dwar--;



	printf("Case #%d: %d %d\n", t, dwar, war);
}

int main() {
	scanf("%d", &T);

	for (t = 1; t <= T; t++) {
		scanf("%d", &N);
		FOR (n,N) scanf("%Lf", &WN[n]);
		FOR (n,N) scanf("%Lf", &WK[n]);
		solve();
	}
}
