#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <string.h>

using namespace std;

const double pi = acos(-1.0);
const double eps = 1E-7;

typedef long long int64;
typedef unsigned long long uint64;
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
#define contain(S,X) (((S)&two(X))!=0)
#define containL(S,X) (((S)&twoL(X))!=0)
#define sqr(x) ((x)*(x))
#define Abs(x) ((x) < 0 ? (-(x)) : (x))
typedef pair<int,int> ipair;
#define SIZE(A) ((int)A.size())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)
#define ME(a) memset((a), 0, sizeof((a)))
#define MM(a, b) memcpy((a), (b), sizeof((a)))
#define FOR(i,n) for (int (i) = 0; (i) < (n); ++(i))
#define REP(i,a,b) for (int (i) = (a); (i) < (b); ++(i))

int Tests;
int x[100000], a[100000], n, t[100000];
vector<int> b[100000];
int q[100000], d[100000];
int tot, ans;

	int g(int u1, int u2) {
		int top = 0, tail = 1;
		q[1] = u1; d[1] = 1;
		int mx = 1;
		for (; top < tail; ) {
			++top;
			for (int v = 0; v < b[q[top]].size(); ++v) 
				if (b[q[top]][v] != u2) {
					q[++tail] = b[q[top]][v];
					d[tail] = d[top] + 1;
					mx = max(d[tail], mx);
				}
		}
		int res = mx;
		top = 0, tail = 1;
		q[1] = u2; d[1] = 1;
		mx = 1;
		for (; top < tail; ) {
			++top;
			for (int v = 0; v < b[q[top]].size(); ++v) 
				if (b[q[top]][v] != u1) {
					q[++tail] = b[q[top]][v];
					d[tail] = d[top] + 1;
					mx = max(d[tail], mx);
				}
		}
		return res + mx;
	}

	void f(int u) {
		if (x[u] <= 0) {
			if (t[0] == 2) {
				tot += g(t[1], t[2]);
			} else {
				ans = max(ans, t[0]);
			}
			return;
		}
		t[++t[0]] = u;
		--x[u];
		f(a[u]);
	}

int main() {
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);
	scanf("%d", &Tests); 
	for (int tts = 0; Tests--; ) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			x[i] = 0;
			b[i].clear();
		}
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			b[a[i]].push_back(i);
			++x[a[i]];
		}
		for (;;) {
			int ff = 0;
			for (int i = 1; i <= n; ++i)
				if (x[i] == 0) {
					x[i] = -1;
					--x[a[i]];
					ff = 1;
				}
			if (ff == 0) break;
		}
		ans = 0;
		tot = 0;
		for (int i = 1; i <= n; ++i)
			if (x[i] > 0) {
				t[0] = 0;
				f(i);
			}
		ans = max(ans, tot);
		printf("Case #%d: %d\n", ++tts, ans);
	}
	return 0;
}