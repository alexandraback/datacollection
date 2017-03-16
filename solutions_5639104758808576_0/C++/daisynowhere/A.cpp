#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); i++)

int main() {
	int Tc;
	scanf("%d", &Tc);
	rep (ri, Tc) {
		int n;
		string s;
		cin >> n >> s;
		int cur = 0, ans = 0;
		rep (i, n + 1) {
			if (s[i] > '0' && cur < i) {
				ans += i - cur;
				cur += i - cur;
			}
			cur += s[i] - '0';
		}
		printf("Case #%d: %d\n", ri + 1, ans);
	}
}
