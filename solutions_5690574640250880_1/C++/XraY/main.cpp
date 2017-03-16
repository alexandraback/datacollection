#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <cassert>
#include <ctime>


using namespace std;

#ifdef WIN32
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

typedef long double ld;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<ll> vll;
typedef vector<vll> vvll;

ll rdtsc() {
    ll tmp;
    asm("rdtsc" : "=A"(tmp));
    return tmp;
}

inline int myrand() {
	return abs((rand() << 15) ^ rand());
}

inline int rnd(int x) {
	return myrand() % x;
}

#define TASKNAME "text"
#define pb push_back
#define mp make_pair
#define EPS (1e-9)
#define INF ((int)1e9)
#define sqr(x) ((x) * (x))         
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define sz(x) ((int)(x).size())

const char* vers = ".*c";
const int maxn = 50 + 10 + 1;
char ans[maxn][maxn];

bool solve(int w, int h, int k) {
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j)
			ans[i][j] = vers[1];
	
	if (k == 1) {
		ans[0][0] = vers[2];
		return 1;
	}

	if (h == 1 || w == 1) {
		for (int i = 0; i < h; ++i)
			for (int j = 0; j < w && k; ++j, --k)
				ans[i][j] = vers[0];
		ans[0][0] = vers[2];
		return 1;
	}

	int k0 = k;
	if (!(k & 1)) {
		if (k == 2)
			return 0;
		for (int i = 0; i < w && k; ++i)
			ans[0][i] = ans[1][i] = vers[0], k -= 2;
		if (k) {
			for (int i = 0; i < h; ++i)
				for (int j = 0; j < w && k; ++j)
					if (ans[i][j] != vers[0]) {
						ans[i][j] = vers[0];
						--k;
					}
			if (k0 % w == 1)
				swap(ans[k0 / w][1], ans[k0 / w - 1][w - 1]);
		}
		ans[0][0] = vers[2];	   	
		return 1;
	}
	
	if (k < 9)
		return 0;
	if (min(w, h) == 2)
		return 0;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			ans[i][j] = vers[0], --k;
	for (int j = 3; j < w && k; ++j)
		ans[0][j] = ans[1][j] = vers[0], k -= 2;
	if (k) {
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w && k; ++j)
				if (ans[i][j] != vers[0]) {
					ans[i][j] = vers[0];
					--k;
				}
		}

		if (k0 % w == 1)
			swap(ans[k0 / w][1], ans[k0 / w - 1][w - 1]);
	}
	ans[0][0] = vers[2];
	return 1;
}

bool solve(int testCase) {
	printf("Case #%d:\n", testCase);
	int h, w, k;
	if (scanf("%d%d%d", &h, &w, &k) < 3)
		return 0;
	if (solve(w, h, w * h - k)) {
		int cnt = 0;
		for (int i = 0; i < h; ++i) {
			ans[i][w] = 0;
			printf("%s\n", ans[i]);
			for (int j = 0; j < w; ++j)
				cnt += ans[i][j] == '*';
		}
		assert(cnt == k);
	} else
		printf("Impossible\n");
	return 1;
}

int main() {
	srand(rdtsc());
#ifdef DEBUG
	freopen(TASKNAME".in", "r", stdin);
	freopen(TASKNAME".out", "w", stdout);
#endif
	
	int maxt;
	while (scanf("%d", &maxt) == 1) {
		for (int t = 0; t < maxt; ++t)
			assert(solve(t + 1));
		
		#ifdef DEBUG
			eprintf("%.18lf\n", (double)clock() / CLOCKS_PER_SEC);
		#endif
	}
	return 0;
}
