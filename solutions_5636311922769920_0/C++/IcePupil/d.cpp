#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <queue>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
int K, C, S;

int main()
{
	freopen("d.in", "r", stdin);
	freopen("d.out", "w", stdout);
	int test, nCase = 0;
	scanf("%d", &test);
	while (test --) {
		scanf("%d%d%d", &K, &C, &S);
		int D = K / C;
		if (K % C) D ++;
		nCase ++;
		printf("Case #%d:", nCase);
		if (D > S) {
			printf(" IMPOSSIBLE\n");
			continue;
		}
		for (int i = 0; i < K; i += C) {
			long long r = 1;
			for (int j = 1; j <= C; j ++) {
				r = (r - 1) * K + min(i + j, K);
			}
			printf(" %lld", r);
		}
		printf("\n");
	}
	return 0;
}
