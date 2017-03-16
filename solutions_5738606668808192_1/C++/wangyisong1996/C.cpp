#include <stdio.h>
#include <map>

inline int getrand() {
	static int ret = 1531871;
	return ret = ret * 16807LL % 2147483647LL;
}

const int N = 32;
const int J = 500;

int s[N];
long long numbers[11];
int ans[11];

void gen() {
	s[0] = s[N - 1] = 1;
	for (int i = 1; i + 1 < N; i++) {
		s[i] = (getrand() >> 16) & 1;
	}
	for (int i = 2; i <= 10; i++) {
		long long tmp = 1;
		long long sum = 0;
		for (int j = 0; j < N; j++) {
			if (s[j]) sum += tmp;
			tmp *= i;
		}
		numbers[i] = sum;
	}
}

const int A = 10000;

int prs[A];
bool f[A];
int pr_cnt;

void init() {
	for (int i = 2; i < A; i++) {
		if (f[i]) continue;
		prs[++pr_cnt] = i;
		for (int j = i + i; j < A; j += i) f[j] = 1;
	}
}

bool find_ans(const long long &n, int &ans) {
	for (int i = 1; i <= pr_cnt; i++) {
		if (n % prs[i] == 0) {
			ans = prs[i];
			return 1;
		}
	}
	return 0;
}

int main() {
	// freopen("C-small-attempt0.out", "w", stdout);
	freopen("C-large.out", "w", stdout);
	printf("Case #1:\n");
	std::map<long long, bool> M;
	int cnt = 0;
	int gen_cnt = 0;
	init();
	while (cnt < J) {
		gen();
		if (M[numbers[10]]) continue;
		M[numbers[10]] = 1;
		++gen_cnt;
		if (gen_cnt % 100 == 0) {
			// printf("gen cnt %d\n", gen_cnt);
		}
		int i;
		for (i = 2; i <= 10; i++) {
			if (!find_ans(numbers[i], ans[i])) break;
		}
		if (i <= 10) continue;
		++cnt;
		for (i = N - 1; i >= 0; i--) printf("%d", s[i]);
		for (i = 2; i <= 10; i++) printf(" %d", ans[i]);
		putchar('\n');
	}
}