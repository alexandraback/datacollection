#include <bits/stdc++.h>
using namespace std;
int nTest;
int C,D,V;
int a[333];
int mark[333];
int solve1(){
	for (int i = 1; i <= D; i++) {
		mark[a[i]] = 1;
	}
	int ans = 0;
	int next = 1;
	while (next <= V){
		int now = next;
		if (mark[next]){
			next *= 2;
			for (int i = now + 1; i <= next; i++) if (mark[i]) next += i;
		} else {
			ans++;
			next *= 2;
			for (int i = now + 1; i <= next; i++) if (mark[i]) next += i;
		}
	}
	return ans;
}
int solve2(){
	return 0;
}
int main(){
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);
	scanf("%d", &nTest);
	for (int test = 1; test <= nTest; test++){
		scanf("%d %d %d", &C, &D, &V);
		for (int i = 1; i <= D; i++) scanf("%d", a + i);
		sort(a, a + D);

		for (int i = 1; i <= V; i++) mark[i] = 0;

		int ans = 0;
		if (C == 1) ans = solve1();
		else ans = solve2();

		printf("Case #%d: %d\n", test, ans);
	}
	return 0;
}