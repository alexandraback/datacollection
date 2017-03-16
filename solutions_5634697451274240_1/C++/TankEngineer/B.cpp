#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

char s[105];

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%s", s);
		int l = strlen(s);
		int ans = 0;
		for (int i = 0; i + 1 < l; ++i) {
			if (s[i] != s[i + 1]) {
				++ans;
			}
		}
		if (s[l - 1] == '-') {
			++ans;
		}
		static int id = 0;
		printf("Case #%d: %d\n", ++id, ans);
	}
	return 0;
}
