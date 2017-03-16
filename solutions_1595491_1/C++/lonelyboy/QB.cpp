#include <stdio.h>
#include <string.h>
int n, s, p, in[200];


int solve() {
	int t[50];
	memset(t, -1, sizeof(t));
	for(int i = 0; i <= 10; ++i) {
		for(int j = i; j <= i + 2; ++j) {
			for(int l = j; l <= i + 2; ++l) {
				int sum = i + j + l;
				if(l < p) continue;
				if(l - i < 2) {
					t[sum] = 0;
				} else if(t[sum] == -1){
					t[sum] = 1;
				}
			}
		}
	}
	int ret = 0;
	for(int i = 0; i < n; ++i) {
		if(t[in[i]] == 0) ++ret;
		else if(t[in[i]] == 1) {
			if(s) {
				++ret;
				--s;
			}
		}
	}
	return ret;
}

int main() {
	int t;
	freopen("B-large.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	scanf("%d", &t);
	for(int i = 0; i < t; ++i) {
		scanf("%d %d %d", &n, &s, &p);
		for(int j = 0; j < n; ++j) scanf("%d", in + j);
		printf("Case #%d: %d\n", i + 1, solve());

	}
	//scanf("%d", &t);
	return 0;
}
