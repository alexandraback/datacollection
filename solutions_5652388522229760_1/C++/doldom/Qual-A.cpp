#include <cstdio>
using namespace std;

int solve(int n) {
	if (n == 0) return 0;
	bool used[10] = {0};
	int ret = 0;
	while (++ret) {
		int num = n * ret;
		while (num) {
			used[num%10] = true;
			num /= 10;
		}
		bool flag = true;
		for (int i=0; i<10; ++i)
			if (used[i] == false)
				flag = false;
		if (flag) break;
	}
	return n * ret;
}

int main() {
	freopen("qual\\A-large.in", "r", stdin);
	freopen("qual\\A-large.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int N=1; N<=T; ++N) {
		int n;
		scanf("%d", &n);
		int ans = solve(n);
		printf("Case #%d: ", N);
		if (ans)
			printf("%d\n", ans);
		else
			puts("INSOMNIA");
	}
}