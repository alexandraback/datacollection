
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;

vector<long long> good;

bool palindrome(long long x) {
	char tmp[102];
	sprintf(tmp, "%lld", x);
	int len = strlen(tmp);
	for (int i = 0; i < len; i ++)
		if (tmp[i] != tmp[len - i - 1]) return false;
	return true;
}

void work() {
	long long a, b;
	scanf("%lld%lld", &a, &b);
	int ans = lower_bound(good.begin(), good.end(), b + 1) - good.begin();
	ans -= lower_bound(good.begin(), good.end(), a) - good.begin();
	printf("%d\n", ans);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	good.clear();
	for (int i = 1; i <= 10000000; i ++) {
		if (palindrome(i) && palindrome((long long)i * i))
			good.push_back((long long)i * i);
	}

	int T;
	scanf("%d", &T);
	for (int test = 0; test < T; test ++) {
		printf("Case #%d: ", test + 1);
		work();
	}

	return 0;
}