#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

long long bar[50], ans[10000005];

bool check(const long long k) {
	long long tmp = k;
	int cnt = 0;
	while (tmp) {
	  bar[++cnt] = tmp % 10;
	  tmp /= 10;
	}
	for (int i = 1; i <= cnt - i + 1; ++i) {
	  if (bar[i] != bar[cnt - i + 1]) return false;
	}
	return true;
}

int main() {
  freopen("C.in", "r", stdin);
  freopen("C2.out", "w", stdout);
	for (long long i = 1; i <= 10000001; ++i) {
	  if (check(i) && check(i * i)) ans[i] = ans[i - 1] + 1; else ans[i] = ans[i - 1];
	}
	int T;
	scanf("%d", &T);
	for (int V = 1; V <= T; ++V) {
		long long a, b;
		cin >> a >> b;
		long long t1 = 0, t2 = 0;
		
		t1 = (long long)sqrt((double)a) - 2;
		if (t1 < 0) t1 = 0;
		while (t1 * t1 < a) ++t1;
		t2 = t1;
		t2 = (long long)sqrt((double)b) - 2;
		if (t2 < 0) t2 = 0;
		while (t2 * t2 <= b) ++t2;
		
		long long ret = ans[t2 - 1] - ans[t1 - 1];
		printf("Case #%d: %I64d\n", V, ret);
	}
	return 0;
}

