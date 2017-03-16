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

char S[1050];
int M;

void solve() {
	scanf("%d%s", &M, S);
	int sum = 0;
	for (int i = 0; i <= M; i++) sum += S[i] - '0';
	for (int x = S[0] - '0'; x <= 9 * M + sum; x++) {
		int n = x;
		bool good = true;
		for (int i = 1; i <= M; i++) {
			if (n >= i) n += S[i] - '0';
			else good = false;
		}
		if (good) {
			printf("Case #%d: %d\n", TCC, x - (S[0] - '0'));
			break;
		}
	}
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