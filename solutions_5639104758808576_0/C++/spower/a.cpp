#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

char digs[1002];
int main() {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	int t, s;
	scanf("%d", &t);
	for(int cas = 1; cas <= t; cas++) {
		scanf("%d%s", &s, digs);
		int sum = 0, ans = 0;
		for(int i = 0; i <= s; i++) {
			if(sum < i) {
				ans += i-sum;
				sum = i;
			}
			sum += digs[i] - '0';
		}
		printf("Case #%d: %d\n", cas, ans);
	}
	return 0;
}