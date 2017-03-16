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

int a[128];

int main() {
	int T; scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		int n, s, p;
		scanf("%d %d %d", &n, &s, &p);
		for (int i = 0; i < n; i++)
			scanf("%d", a + i);
		
		int r = 0, q = 0;
		for (int i = 0; i < n; i++) {
			if ((a[i] + 2) / 3 >= p) {
				r++;
			}
			else if (a[i] >= 2 && ((a[i] + 4) / 3 >= p)) {
				q++;
			}
		}
		printf("Case #%d: %d\n", t, r + min(q, s));
	}
	
	return 0;
}
