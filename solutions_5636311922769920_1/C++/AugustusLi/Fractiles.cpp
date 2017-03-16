#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <unordered_map>
#include <map>

using namespace std;

typedef __int64 I;

const int N = 109;
const double eps = 0.00001;
const int INF = 0x3fffffff;

I rslt[N];

I getGoldNum(I k, I c, I start) {
	I ret = 0;
	for (I i = 0; i < c; i++) {
		ret = ret*k + start;
		start = (start + 1) % k;
	}
	return ret;
}

int main() {
	FILE* stream;
	freopen_s(&stream, "D-large.in", "r", stdin);
	freopen_s(&stream, "D-large.out", "w", stdout);
	int t;
	scanf_s("%d", &t);
	for (int cas = 1; cas <= t; cas++) {
		I k, c, s;
		scanf_s("%I64d%I64d%I64d", &k, &c, &s);
		if (k > c*s) {
			printf("Case #%d: IMPOSSIBLE\n", cas);
		}
		else {
			int ans = 0;
			for (ans = 1; ans * c < k; ans++);
			int start = 0;
			for (int i = 0; i < ans; i++) {
				rslt[i] = getGoldNum(k, c, start);
				start = (start + c) % k;
			}
			printf("Case #%d:", cas);
			for (int i = 0; i < ans; i++) {
				printf(" %I64d", rslt[i]+1);
			}
			printf("\n");
		}
	}
	return 0;
}