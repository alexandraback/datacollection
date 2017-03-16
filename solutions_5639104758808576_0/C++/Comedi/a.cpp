#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <vector>
#include <string>
#include <set>
#include <map>
using namespace std;
typedef long long lint;
int t, smax;
char s[1005];

int main() {
	scanf("%d", &t);
	for(int cas = 1; cas <= t; cas++) {
		scanf("%d", &smax);
		scanf("%s", s);
		int ans = 0, now = 0;
		for(int i = 0; i <= smax; i++) {
			int num = s[i] - '0';
			if(now < i) {
				ans += i - now;
				now = i;
			}
			now += num;
		}
		printf("Case #%d: %d\n", cas, ans);
	}
	return 0;
}
