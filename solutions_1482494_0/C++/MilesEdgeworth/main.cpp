#include <cstdio>
#include <algorithm>
#include <utility>

const int MAX_N =5005;
int T, N;

struct Level {
	Level(int _a = -1, int _b = -1, int _i = -1) : a(_a), b(_b), i(_i) {}
	int a, b, i;
	bool operator<(const Level& l) const {
		if (a == l.a && b == l.b) return i < l.a;
		if (a == l.a) return b < l.b;
		return a < l.a;
	}
} first[MAX_N], second[MAX_N];

int solve() {
	int stars = 0, total = 0;
	bool halfdone[MAX_N] = {};
	while (1) {
		bool torem[MAX_N] = {};
		bool found = false, left = false;
		for (int i = 0; i < N; ++i) {
			if (second[i].a == -1) continue;
			left = true;
			if (second[i].a <= stars) {
				torem[second[i].i] = found = true;
				if (halfdone[second[i].i]) stars += 1;
				else stars += 2;
				total++;
			}
		}
		if (!left) return total;
		if (!found) {
			for (int i = N-1; i >= 0; --i) {
				if (second[i].a == -1 || torem[second[i].i] || halfdone[second[i].i]) continue;
				if (second[i].b <= stars) {
					halfdone[second[i].i] = found = true;
					stars += 1;
					total++;
					break;
				}
			}
		}
		if (!found) return -1;

		for (int i = 0; i < N; ++i) {
			if (torem[first[i].i]) first[i] = Level();
			if (torem[second[i].i]) second[i] = Level();
		}
	}
}

int main() {
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		scanf("%d", &N);
		int a, b;
		for (int i = 0; i < N; ++i) {
			scanf("%d %d", &a, &b);
			first[i] = Level(a, b, i);
			second[i] = Level(b, a, i);
		}
		std::sort(first, first+N);
		std::sort(second, second+N);
		printf("Case #%d: ", t);
		int ans = solve();
		if (ans == -1) printf("Too Bad\n");
		else printf("%d\n", ans);
	}
}
