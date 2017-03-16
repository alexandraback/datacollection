#include <stdio.h>
#include <iostream>
using namespace std;

int T, n, ans;

void solve( int id ) {
	int now = 0;
	char c;

	ans = 0;
	scanf("%d%*c%c",&n, &c);
	now = c-'0';
	for (int i = 1;i <= n;++i) {
		
		scanf("%c", &c);
		if (c > '0') {
			if (now < i) {
				ans += i - now;
				now = i;
			}
		}
		now += c-'0';
	}
	printf("Case #%d: %d\n", id, ans);
}

int main() {
	//printf("sdf");
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	scanf("%d", &T);
	//printf("sdf");
	for (int i = 1;i <= T;++i){
		solve( i );
	}
	return 0;
}