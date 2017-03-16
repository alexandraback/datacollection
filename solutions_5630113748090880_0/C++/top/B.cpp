#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 60;

int n;
struct xxx {
	int x[N];
} x[N+N];
vector<xxx> y[N];
bool use[N+N];

inline void solve () {
	scanf ("%d", &n);

	for (int i = 0;i < n;i ++) {
		y[i].clear ();
	}

	int m = n+n-1;
	for (int i = 0;i < m;i ++) {
		use[i] = false;
		for (int j = 0;j < n;j ++) {
			scanf ("%d", &x[i].x[j]);
		}
	}

	int t = -1;
	for (int i = 0;i < n;i ++) {
		int noi = -1u/2;
		for (int j = 0;j < m;j ++) {
			if (not use[j] and x[j].x[i] < noi) {
				noi = x[j].x[i];
			}
		}
		for (int j = 0;j < m;j ++) {
			if (not use[j] and x[j].x[i] == noi) {
				y[i].push_back (x[j]);
				use[j] = true;
			}
		}
		if (y[i].size () < 2) {
			t = i;
		}
	}

	for (int i = 0;i < n;i ++) {
		int a;
		if (i == t) {
			a = y[i][0].x[t];
		} else if (y[i][0].x[t] == y[t][0].x[i]) {
			a = y[i][1].x[t];
		} else {
			a = y[i][0].x[t];
		}
		printf ("%d ", a);
	}
	printf ("\n");
}

int main () {
	int t;
	scanf ("%d", &t);

	for (int i = 1;i <= t;i ++) {
		printf ("Case #%d: ", i);
		solve ();
	}
}