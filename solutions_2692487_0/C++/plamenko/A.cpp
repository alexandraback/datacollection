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
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

int a[128];
//map<int, int> mc;

//int solve(int A) {
//}

struct atom {
	int r; ll A; int i; int n;
	atom(int r, ll A, int i, int n) : r(r), A(A), i(i), n(n) {}
};

int main() {
	int T; scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		ll A; int n; scanf("%lld %d", &A, &n);
		for (int i = 0; i < n; i++)
			scanf("%d", a + i);
		sort(a, a + n);

		vector<atom> q;
		q.push_back(atom(0, A, 0, n));
		int r = 0;
		for (int k = 0; k < (int) q.size(); k++) {
			atom t = q[k];
			for (; t.i < t.n && a[t.i] < t.A; t.i++)
				t.A += a[t.i];
			if (t.i == t.n) {
				r = t.r;
				break;
			}
			else {
				q.push_back(atom(t.r + 1, t.A + t.A - 1, t.i, t.n));
				q.push_back(atom(t.r + 1, t.A, t.i, t.n - 1));
			}
		}
		printf("Case #%d: %d\n", t, r);
	}
	//fprintf(stderr, "%d ms\n", clock());
	return 0;
}
