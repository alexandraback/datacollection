#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int length(long long a) {
	int ret = 0;
	while (a) {
		a = a / 10;
		ret ++;
	}
	return ret;
}

long long rev(long long a) {
	long long ret = 0;
	while (a) {
		ret = ret * 10 + a % 10;
		a = a / 10;
	}
	return ret;
}

long long getans(long long N) {
	long long ans = 1;
	while (N > 1) {
		if (N % 10 == 0) {
			ans += 9;
			N -= 9;
		} else if (N % 10 != 1) {
			ans += (N % 10) - 1;
			N -= (N % 10) - 1;
		}
		if (N == 1)
			break;
		
		long long revN = rev(N);
		if (revN >= N) {
			ans += 10;
			N -= 10;
			continue;
		}

		int num0 = max(0, (length(N) - 1) / 2);
		long long a = 10;
		for (int i = 0; i < num0; i++)
			a *= 10;

		if (N % a == 0) {
			ans ++;
			N --;
			continue;
		}

		if (N % a != 1) {
			ans += (N % a) - 1;
			N -= (N % a) - 1;
			continue;
		}

		N = revN;
		ans ++;
	}
	return ans;
}

long long D[100000001];

void test(void) {
	printf("START\n");
	for (int i = 1; i <= 100000000; i++)
		D[i] = 0;
	D[1] = 1;
	queue <long long> Q;
	Q.push(1);
	while (!Q.empty()) {
		long long x = Q.front();
		Q.pop();
		if (x + 1 <= 100000000 && D[x + 1] == 0) {
			D[x + 1] = D[x] + 1;
			Q.push(x + 1);
		}
		if (rev(x) <= 100000000 && D[rev(x)] == 0) {
			D[rev(x)] = D[x] + 1;
			Q.push(rev(x));
		}
	}

	for (int i = 1; i <= 100000000; i++) {
		if (D[i - 1] + 1 != D[i]) {
//			printf("Change %d -> %lld\n", i, rev(i));
		}
	}

	for (int i = 1; i <= 100000000; i++) {
//		printf("%d %lld\n", i, D[i]);
		if (D[i] != getans(i)) {
			printf("FAIL %d %lld %lld\n", i, D[i], getans(i));
			break;
		}
	}
	printf("DONE\n");
}


int main(void) {
	// test();
	int testnum;
	scanf("%d", &testnum);
	for (int testcase = 1; testcase <= testnum; testcase++) {
		long long N;
		scanf("%lld", &N);
		printf("Case #%d: %lld\n", testcase, getans(N));
	}
	return 0;
}
