#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <memory.h> 
#include <math.h> 
#include <assert.h> 
#include <stack> 
#include <queue> 
#include <map> 
#include <set> 
#include <algorithm> 
#include <string> 
#include <functional> 
#include <vector> 
#include <deque> 
#include <utility> 
#include <bitset> 
#include <limits.h>  

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
#define memset0(x) memset(x, 0, sizeof (x));
int TC, TCC;


void init() {
}

int D, P[1050];

void solve() {
	int ans = 0;

	scanf("%d", &D);
	for (int i = 0; i < D; i++) scanf("%d", P + i), ans = max(ans, P[i]);

	for (int maxh = 1; maxh <= 1000; maxh++) {
		int ret = 0;
		for (int i = 0; i < D; i++) {
			if (P[i] > maxh) ret += (P[i] - 1) / maxh;
		}
		ret += maxh;
		ans = min(ans, ret);
	}

	printf("Case #%d: %d\n", TCC, ans);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &TC);
	while (++TCC <= TC) {
		init();
		solve();
	}
	return 0;
}