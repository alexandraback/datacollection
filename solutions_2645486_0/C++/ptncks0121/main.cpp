#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>
#include <deque>
#include <utility>
#include <bitset>

using namespace std;
typedef long long ll;
const int INF = 987654321;
const ll LINF = 1e15;

void precalc();

const int N_ = 100;

int TC, TCC;
int E, R, N;
int V[N_];

int solve (int x, int e) {
	int ret = 0;
	if(x >= N) return 0;
	for(int n = 0; n <= e; n++) {
		ret = max(ret, solve(x + 1, min(E, e - n + R)) + n * V[x]);
	}
	return ret;
}

int main() {
    freopen("input.txt", "r", stdin);

    int i, j, k;

    precalc();
    freopen("output.txt", "w", stdout);

    scanf("%d", &TC);
    while(++TCC <= TC) {
        printf("Case #%d: ", TCC);

		scanf("%d%d%d", &E, &R, &N);
		for(i = 0; i < N; i++) scanf("%d", &V[i]);

		printf("%d\n", solve(0, E));
    }
    return 0;
}

void precalc() {
}
