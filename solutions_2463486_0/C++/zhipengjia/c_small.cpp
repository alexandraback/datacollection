
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

bool palindrome(int x) {
	char tmp[102];
	sprintf(tmp, "%d", x);
	int len = strlen(tmp);
	for (int i = 0; i < len; i ++)
		if (tmp[i] != tmp[len - i - 1]) return false;
	return true;
}

void work() {
	int a, b;
	scanf("%d%d", &a, &b);
	int ans = 0;
	for (int i = a; i <= b; i ++) {
		int t = (int)sqrt(i + 1e-3);
		if (t * t != i) continue;
		if (palindrome(t) && palindrome(i)) ans ++;
	}
	printf("%d\n", ans);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int test = 0; test < T; test ++) {
		printf("Case #%d: ", test + 1);
		work();
	}

	return 0;
}