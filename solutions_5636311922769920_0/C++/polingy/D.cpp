#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cmath>

#include <iostream>
#include <iomanip>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <utility>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int max_K = 110;
const int max_C = 110;

ll ind[max_C][max_K];

int main()
{
	int T;
	scanf("%d", &T);

	int K, C, S;
	for (int tc = 1; tc <= T; ++tc) {
		printf("Case #%d: ", tc);
		scanf("%d%d%d", &K, &C, &S);
		if (S * C < K) {
			printf("IMPOSSIBLE\n");
		} else {
			int nextD = 1;
			for (int i = 1; i <= S && nextD <= K; ++i) {
				ll currIndex = nextD;
				++nextD;
				for (int j = 2; j <= C; ++j) {
					if (nextD <= K) {
						currIndex = (currIndex - 1) * K + nextD;
						++nextD;
					} else {
						currIndex = currIndex * K;
					}
				}
				printf("%lld ", currIndex);
			}
			printf("\n");
		}
	}
}
