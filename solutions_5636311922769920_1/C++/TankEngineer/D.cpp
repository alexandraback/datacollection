#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		static int id = 0;
		printf("Case #%d:", ++id);
		int k, c, s;
		scanf("%d%d%d", &k, &c, &s);
		int bound = (k + c - 1) / c;
		if (s < bound) {
			printf(" IMPOSSIBLE\n");
		} else {
			for (int i = 0; i < k; i += c) {
				long long cur = 0;
				for (int j = i; j < i + c; ++j) {
					cur = cur * k + (j % k);
				}
				printf(" %lld", cur + 1);
			}
			printf("\n");
		}
	}
	return 0;
}
