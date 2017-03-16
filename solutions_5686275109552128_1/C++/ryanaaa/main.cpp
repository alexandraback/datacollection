#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
#define MP(a, b) make_pair(a, b)
#define FOREACH(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)

const int maxn = 1000 + 5;
int n, piz[maxn];

int work(int Y) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += ((piz[i] - 1) / Y);
	}
	return sum;
}

int main() {
//freopen("in", "r", stdin);
// freopen("B-small-attempt0.in", "r", stdin);
// freopen("B-small-attempt0.out", "w", stdout);
// freopen("B-large.in", "r", stdin);
// freopen("B-large.out", "w", stdout);
	int test;	scanf("%d", &test);
	for (int ti = 1; ti <= test; ti++) {
		scanf("%d", &n);
		int maxPiz = 0;
		for (int i = 0; i < n; i++) scanf("%d", piz + i), maxPiz = max(maxPiz, piz[i]);

		int res = maxPiz;
		for (int Y = 1; Y < maxPiz; Y++) {
			int tmp = Y + work(Y);
			res = min(res, tmp);
		}

		printf("Case #%d: %d\n", ti, res);
	}
}
