#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

#define N 1020
#define M 200020
#define LL long long
#define inf 0x3f3f3f3f


int n, a[N];

int f(int x, int y) {
	if(x <= y) return 0;
	return (x - 1) / y;
}
int main() {
	//freopen("tt.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int cas, kk = 0;
	scanf("%d", &cas);
	while(cas--) {
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
		int ans = inf;
		for(int i = 1; i <= 1000; ++i) {
			int cnt = 0;
			for(int j = 1; j <= n; ++j) {
				if(a[j] > i)
					cnt += f(a[j], i);
			}
			ans = min(ans, cnt + i);
		}
		printf("Case #%d: %d\n", ++kk, ans);
	}
	return 0;
}