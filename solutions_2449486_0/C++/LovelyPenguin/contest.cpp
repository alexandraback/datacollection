#include <functional>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstring>
#include <cassert>
#include <bitset>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int INF = 1000 * 1000 * 1000;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define ALL(v) v.begin(), v.end()
#define SZ(v) (int) v.size()
#define MP make_pair
#define PB push_back

#define TASK ""

int a[111][111];

int main() {
	#ifdef EDDY
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#else 
	//	freopen(TASK ".in", "r", stdin);
	//	freopen(TASK ".out", "w", stdout);
	#endif

	int T;

	scanf("%d", &T);

	int tc = 0;

	while (T--) {
		printf("Case #%d: ", ++tc);
		int N, M;
		scanf("%d%d", &N, &M);
		REP(i, N)
			REP(j, M) {
				scanf("%d", &a[i][j]);
			}
		bool bad = false;
		REP(i, N) {
			bool check = true;
			int me = -1;
			REP(j, M) {
				me = max(me, a[i][j]);
			}
			REP(j, M)
				if (a[i][j] < me) 
					REP(k, N) 
						if (a[k][j] > a[i][j]) {
							bad = true;
						}
		}
		REP(j, M) {
			bool check = true;
			int me = -1;
			REP(i, N) {
				me = max(me, a[i][j]);
			}
			REP(i, N)
				if (a[i][j] < me) 
					REP(k, M) 
						if (a[i][k] > a[i][j]) {
							bad = true;
						}
		}
		puts(bad ? "NO" : "YES");
	}

	return 0;
}