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

int N;
int tb[(int)2e6];

void init() {
	for (int i = 1; i <= (int)1e6; i++) tb[i] = i;
	for (int i = 1; i <= (int)1e6; i++) {
		tb[i + 1] = min(tb[i + 1], tb[i] + 1);
		int j; char str[10];
		sprintf(str, "%d", i);
		reverse(str, str + strlen(str));
		sscanf(str, "%d", &j);
		if (j > i) tb[j] = min(tb[j], tb[i] + 1);
	}
}


void solve() { 
	scanf("%d", &N);
	printf("Case #%d: %d\n", TCC, tb[N]);
	fprintf(stderr, "Case #%d: %d\n", TCC, tb[N]);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &TC);
	init();
	while (++TCC <= TC) {
		solve();
	}
	return 0;
}