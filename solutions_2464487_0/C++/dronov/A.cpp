#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <string>

using namespace std;

#define MAXN 1000
#define INF 1000000000

const double pi = 3.14159265358979;

double get(int r) {
	return ((r + 1) * (r + 1) - r * r);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int test;
	scanf("%d", &test);
	for (int i = 1; i <= test; i++) {
		int r;
		double t;
		int ans = 0;
		cin >> r >> t;
		double p = get(r);
		ans++;
		t -= p;
		int x = r + 2;
		while (true) {
			if (t - get(x) >= 0) {
				ans++;
				t -= get(x);
			} else
				break;
			x += 2;
		}
		printf("Case #%d: %d\n", i, ans);
	}

	return 0;
}