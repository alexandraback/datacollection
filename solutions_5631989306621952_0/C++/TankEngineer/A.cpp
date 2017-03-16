#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1005;

int n;

char s[N];

char ans[N];

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		static int id = 0;
		printf("Case #%d: ", ++id);
		scanf("%s", s);
		n = strlen(s);
		ans[n] = '\0';
		int l = 0, r = n - 1, b = n - 1;
		while (l <= r) {
			int maxs = -1, maxp = -1;
			for (int i = b; i >= 0; --i) {
				if (s[i] > maxs) {
					maxs = s[i];
					maxp = i;
				}
			}
			ans[l++] = maxs;
			for (int i = b; i > maxp; --i) {
				ans[r--] = s[i];
			}
			b = maxp - 1;
		}
		puts(ans);
	}
	return 0;
}
