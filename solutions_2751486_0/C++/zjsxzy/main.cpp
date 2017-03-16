#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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

const int maxn = 1000000 + 50;
int n, cons[maxn], consNum[maxn], limit;
char str[maxn];

int isCons(char x) {
	return !(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u');
}

int main() {
	int test;	scanf("%d", &test);
	for (int ti = 1; ti <= test; ti++) {
		scanf("%s %d", str + 1, &limit);
		n = strlen(str + 1);
		for (int i = 1; i <= n; i++)
			cons[i] = isCons(str[i]);
		for (int i = 1; i <= n; i++)
			consNum[i] = cons[i] ? consNum[i - 1] + 1 : 0;

		LL res = 0;
		int j = 0;
		for (int i = 1; i <= n; i++) {
			if (consNum[i] >= limit)
				j = i - limit + 1;
			res += j;
		}

		printf("Case #%d: %lld\n", ti, res);
	}
	return 0;
}
