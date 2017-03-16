#include <cstdio>
#include <iostream>

using namespace std;
int t, ans, tt;
char a[1000];
int main() {
	scanf("%d",&t);
	gets(a);
	for (int q = 1; q <= t; q++) {
		gets(a);
		ans = 0;
		tt = strlen(a);
		for (int i = 0; i < tt; i++) {
			if (a[i] == a[i - 1]) continue;
			ans++;
		}
		if (a[tt - 1] == '+')ans--;
		printf("Case #%d: %d\n", q, ans);
	}
}