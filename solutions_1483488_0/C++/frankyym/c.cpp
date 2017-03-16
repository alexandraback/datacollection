#include <cstdio>

using namespace std;

typedef long long ll;

bool is_cycle(int a, int b) {
	int _a = a, base = 1, cnt = 0;
	while (_a != 0) {
		_a /= 10;
		++cnt;
		base *= 10;
	}
	base /= 10;

	for (int i=0; i<cnt; ++i) {
		int last = a % 10;
		//if (last == 0) return false;
		a /= 10;
		a += last * base;
		if (a == b) return true;
	}
	return false;
}

int main() {
	is_cycle(13, 31);
	int T, A, B;
	scanf("%d", &T);
	for (int t=0; t<T; ++t) {
		scanf("%d%d", &A, &B);
		printf("Case #%d: ", t+1);

		int ret = 0;
		for (int a=A; a<B; ++a)
			for (int b=a+1; b<=B; ++b)
				if (is_cycle(a, b)) ++ret;
		printf("%d\n", ret);
	}
	return 0;
}
