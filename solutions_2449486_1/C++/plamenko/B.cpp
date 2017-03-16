#define _CRT_SECURE_NO_DEPRECATE
//#define _CRT_RAND_S

//#include <windows.h>
//#include <tchar.h>
//#include <atlbase.h>
//#include <winerror.h>

#include <stdint.h>
#include <climits>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <map>
#include <set>
#include <list>
#include <queue>
#include <deque>
#include <string>
#include <bitset>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

int a[128][128];
int mc[128];
int mr[128];

int solve(int n, int m) {
	for (int i = 0; i < n; i++)
		mr[i] = 0;
	for (int j = 0; j < m; j++)
		mc[j] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			mr[i] = max(mr[i], a[i][j]);
			mc[j] = max(mc[j], a[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] != min(mr[i], mc[j])) return 0;
		}
	}
	return 1;
}

int main() {
	int T; scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		int n, m;
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				scanf("%d", &a[i][j]);
		int r = solve(n, m);
		printf("Case #%d: %s\n", t, (r ? "YES" : "NO"));
	}
	return 0;
}
