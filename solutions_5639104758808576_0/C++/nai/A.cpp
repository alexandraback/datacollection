#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		char temp[1024];
		int Smax;
		scanf("%d %s", &Smax, temp);
		int ans = 0;
		int stoodup = 0;
		for (int i = 0; i <= Smax; i++) {
			int num = temp[i] - '0';
			if (num > 0 && stoodup < i) {
				ans += i - stoodup;
				stoodup = i;
			}
			stoodup += num;
		}
		printf("Case #%d: %d\n", t+1, ans);
	}
	return 0;
}
