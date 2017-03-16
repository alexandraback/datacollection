#include <stdio.h>
#include <vector>
#include <minmax.h>
#include <stdlib.h>

typedef std::vector < int > vi;
typedef std::pair < int, int > pii;
typedef std::vector < std::pair < int, int > > vii;

void init(void) {
}

void read(void) {
}

void make_sub(int mask, const vii &orig, vii &sub) {
	int i = 0;
	while(mask) {
		if (mask & 1) {
			sub.push_back(orig[i]);
		}
		mask = mask >> 1;
		++i;
	}
}

bool is_sub(const vii &sub, const vii &s) {
	int i = 0;
	int j = 0;
	int N = sub.size();
	int M = s.size();
	while (i < N) {
		while ((j < M) && (sub[i].second != s[j].second)) {
			++j;
		}
		if (j >= M) {
			return false;
		}
		++i;
	}
	return true;
}

int count_sub(vii sub, vii s) {
	int res = 0;
	int i = 0;
	int j = 0;
	int N = sub.size();
	int M = s.size();
	while (i < N) {
		while ((j < M) && (sub[i].second != s[j].second)) {
			++j;
		}
		if (j >= M) {
			break;
		}
		int cur = min(sub[i].first, s[j].first);
		res += cur;
		sub[i].first -= cur;
		s[j].first -= cur;
		if ((sub[i].first <= 0) || (rand() % 2)) {
			++i;
		}
		if ((s[j].first <= 0)|| (rand() % 2)) {
			++j;
		}
	}
	return res;
}

void solve(void) {
	int N, M;
	vii a, b;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; ++i) {
		pii cur;
		scanf("%d %d", &cur.first, &cur.second);
		a.push_back(cur);
	}

	for (int i = 0; i < M; ++i) {
		pii cur;
		scanf("%d %d", &cur.first, &cur.second);
		b.push_back(cur);
	}

	int NN = 1 << N;
	int best = -1;
	for (int i = 0; i < NN; ++i) {
		vii sub;
		make_sub(i, a, sub);
		if (is_sub(sub, b)) {
			for (int k = 0; k < 30000; ++k) {
				int cur = count_sub(sub, b);
				if (cur > best) {
					best = cur;
				}
			}
		}
	}

	printf("%d\n", best);
}

int main(void) {
	freopen("c.in", "rt", stdin);
	freopen("c.out", "wt", stdout);

	int T = 0;
	scanf("%d", &T);
	for (int i = 0; i < T; ++i) {
		printf("Case #%d: ", i + 1);
		init();
		read();
		solve();
	}

	fcloseall();

	return 0;
}
