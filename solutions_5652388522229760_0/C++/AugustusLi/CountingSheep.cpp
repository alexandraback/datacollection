#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <unordered_map>
#include <map>

using namespace std;

typedef __int64 I;

const int N = 12;
const double eps = 0.00001;
const int INF = 0x3fffffff;

bool used[N];
int cnt = 0;

int tries = 200;

bool countUsed(int num) {
	while (num) {
		int r = num % 10;
		if (used[r] == false) {
			used[r] = true;
			cnt++;
		}
		num /= 10;
	}
	if (cnt >= 10) return true;
	else return false;
}


int main() {
	FILE* stream;
	freopen_s(&stream, "A-small-attempt0.in", "r", stdin);
	freopen_s(&stream, "A-small-attempt0.out", "w", stdout);
	int t;
	scanf_s("%d", &t);
	for (int cas = 1; cas <= t; cas++) {
		int n;
		scanf_s("%d", &n);
		cnt = 0;
		memset(used, 0, sizeof(used));

		bool flag = false;
		int ans = 0;
		for (int i = 1; i <= tries; i++) {
			ans += n;
			flag = countUsed(ans);
			if (flag) break;
		}
		if (flag) {
			printf("Case #%d: %d\n", cas, ans);
		}
		else {
			printf("Case #%d: INSOMNIA\n", cas);
		}
	}
	return 0;
}