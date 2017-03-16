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
int n, num[maxn];
char input[maxn];

int main() {
//freopen("in", "r", stdin);
//freopen("A-small-attempt0.in", "r", stdin);
//freopen("A-small-attempt0.out", "w", stdout);
//freopen("A-large.in", "r", stdin);
//freopen("A-large.out", "w", stdout);
	int test;	scanf("%d", &test);
	for (int ti = 1; ti <= test; ti++) {
		scanf("%d", &n);
		scanf("%s", input);
		for (int level = 0; level <= n; level++)
			num[level] = input[level] - '0';

		int res = 0, cur = 0;
		for (int level = 0; level <= n; level++) {
			int add = max(0, level - cur);
			cur += add + num[level];
			res += add;
		}

		printf("Case #%d: %d\n", ti, res);
	}
}
