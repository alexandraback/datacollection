#include <cstdio>
#include <algorithm>

using namespace std;

int N;
long long E, R;
int v[10001];

long long solve(int st, int ed, long long e1, long long e2) {
	if (st >= ed) {
		return 0;
	}
	if (st == ed - 1) {
		return (e1 - e2) * v[st];
	}
	long long pos = -1, maxi = -1;
	for (int i = st; i < ed; i++) {
		if (v[i] > maxi) {
			maxi = v[i];
			pos = i;
		}
	}
	long long canUse = min(E, e1 + (pos - st) * R);
	long long rest = max(0LL, e2 - (ed - pos - 1) * R);
	long long use = canUse - rest;
	//printf("%lld %lld %lld\n", canUse, rest, pos);
	return use * maxi + solve(st, pos, e1, max(canUse - R, 0LL)) + solve(pos + 1, ed, min(E, rest + R), e2);
}

int main() {
	int test;
	scanf("%d", &test);
	for (int t = 1; t <= test; t++) {
		scanf("%lld%lld%d", &E, &R, &N);
		for (int i = 0; i < N; i++) {
			scanf("%d", &v[i]);
		}
		if (R > E) {
			R = E;
		}
		printf("Case #%d: %lld\n", t, solve(0, N, E, 0));
	}
}