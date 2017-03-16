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
#include <unordered_map>

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

int tb[10+(int)2e6];
ll p10[20];
ll r10[20];

void precalc() {
	for (int i = 1; i <= (int)2e6; i++) tb[i] = i;
	for (int i = 1; i <= (int)2e6; i++) {
		tb[i + 1] = min(tb[i + 1], tb[i] + 1);
		int j; char str[10];
		sprintf(str, "%d", i);
		reverse(str, str + strlen(str));
		sscanf(str, "%d", &j);
		if (j <= (int)2e6 && j > i) tb[j] = min(tb[j], tb[i] + 1);
	}

	p10[0] = r10[0] = 1;
	p10[1] = r10[1] = 10;
	for (int i = 2; i <= 15; i++) {
		p10[i] = p10[i - 1] * 10;
		r10[i] = r10[i - 1] + p10[i / 2] + p10[(i + 1) / 2] - 1;
	}
}

void init() {
}

ll N;
char S[100];

void solve() {
	scanf("%lld", &N); 

	--N;
	
	ll val = 0;

	sprintf(S, "%lld", N); 
	int X = strlen(S) - 1;
	for (int i = X; i >= 0; i--) {
		val += (S[i] - '0') * min(p10[i], p10[X - i]);
	}
	
	ll ans = min(val, N - p10[X]) + r10[X] + 1;

	++N;
	if (N <= 100) ans = tb[N];
	if (N <= (int)2e6) assert(ans == tb[N]);

	printf("Case #%d: %lld\n", TCC, ans);
	fprintf(stderr, "Case #%d: %lld\n", TCC, ans);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &TC);
	precalc();
	while (++TCC <= TC) {
		init();
		solve();
	}
	return 0;
}