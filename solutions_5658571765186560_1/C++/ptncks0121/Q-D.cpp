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

void init() {
}

int X, R, C;

void solve() {
	scanf("%d%d%d", &X, &R, &C);
	if (R > C) swap(R, C);

	string ans;
	if (X == 1) {
		ans = "GABRIEL";
	}
	else if (X == 2) {
		ans = ((R * C) % 2 == 0) ? "GABRIEL" : "RICHARD";
	}
	else if (X == 3) {
		if (R == 1) ans = "RICHARD";
		else ans = ((R * C) % 3 == 0) ? "GABRIEL" : "RICHARD";
	}
	else if (X == 4) {
		if (R <= 2) ans = "RICHARD";
		else if ((R * C) % 4 != 0) ans = "RICHARD";
		else if (R % 4 == 0 || C % 4 == 0) ans = "GABRIEL";
		else if (R % 2 == 0 && C % 2 == 0) ans = "GABRIEL";
		else ans = "RICHARD";
	}
	else if (X >= 5) { 
		ans = "RICHARD";
	}

	printf("Case #%d: %s\n", TCC, ans.c_str());
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