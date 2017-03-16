#include <bits/stdc++.h>
using namespace std;
int nTest;
int C,D,V;
int a[333];
int mark[333];
int solve1(){
	for (int i = 1; i <= V; i++) mark[i] = 0;
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
	int ans = 0;
	long long next = 1;
	sort(a, a + D);
	while (next <= V){
		long long now = next;

		int co = 0;
		for (int i = 1; i <= D; i++) if (a[i] == next) co = 1;
		if (co){
			next *= 2;
			next += ((long long)C - 1LL) * now;
			for (int i = 1; i <= D; i++) {
				if (a[i] > now && a[i] <= next) next += (long long)C * (long long)a[i];
			}

		} else {
			ans++;
			next *= 2;
			next += ((long long)C - 1LL) * now;

			long long sum = 0;
			for (int i = 1; i <= D; i++){
				if (a[i] > now && a[i] <= next) next += (long long)C * (long long)a[i];
			}
		}
		printf("%lld\n", next);
	}
	return ans;
}
int main(){
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);
	scanf("%d", &nTest);
	for (int test = 1; test <= nTest; test++){
		scanf("%d %d %d", &C, &D, &V);
		for (int i = 1; i <= D; i++) scanf("%d", a + i);

		int ans = solve2();

		printf("Case #%d: %d\n", test, ans);
	}
	return 0;
}