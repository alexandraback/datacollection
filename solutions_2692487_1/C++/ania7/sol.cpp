#include <cstdio>
#include <algorithm>
using namespace std;

#define maxn 1000100
#define MX 1000100

int a,n;
int t[maxn];

void add(int x) {
	a += x;
	if (a > MX) {
		a = MX;
	}
}

int test() {
	scanf("%d%d", &a, &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &t[i]);
	}
	if (a == 1) {
		return n;
	}
	sort(t,t+n);
	int res = n;
	int pos = 0;
	int cur = 0;
	while (pos < n && t[pos] < a) {
		add(t[pos]);
		pos++;
	}
	res = min(res, n-pos+cur);
	while (pos < n) {
		cur++;
		add(a-1);
		while (pos < n && t[pos] < a) {
			add(t[pos]);
			pos++;
		}
		res = min(res, n-pos+cur);
	}
	return res;
}

int main() {
	int tt;
	scanf("%d", &tt);
	for (int ttt = 1; ttt <= tt; ttt++) {
		printf("Case #%d: %d\n", ttt, test());
	}
	return 0;
}
