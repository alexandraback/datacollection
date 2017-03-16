#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++)

const int MAX = 1000 + 1 + 1;
char line[MAX];

int main() {
	int ts;
	cin >> ts;
	loop(ti, ts) {
		int ans = 0, t = 0, n;
		cin >> n>> line;
		loop(i, n+1) {
			ans = max(ans, i - t);
			t += line[i] - '0';
		}
		printf("Case #%d: %d\n", ti+1, ans);
	}
}
