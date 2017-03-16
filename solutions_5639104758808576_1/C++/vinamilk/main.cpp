#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

const int nm = 1002;

int n;
char s[nm];

void solve(int test) {
	printf("Case #%d: ", test);
	scanf("%d%s", &n, s);
	int kq = 0, sum = s[0] - 48;
	for (int i = 1; i <= n; ++i) {
		if (sum < i) {
			kq += i - sum;
			sum = i;
		}
		sum += s[i] - 48;
	}
	printf("%d\n", kq);
}

int main() {
#ifdef LOCAL
	freopen("A-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; ++i)
		solve(i);
}
