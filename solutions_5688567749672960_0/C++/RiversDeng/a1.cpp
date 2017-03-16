#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int N = 1e6;

int n, f[N + 1], g[N + 1], ans[N + 1];
bool v[N + 1];

inline int REV(const int &x){
	int num = x, ret = 0;
	for (; num; num /= 10) (ret *= 10) += num % 10;
	return ret;
}

void pretreat(){
	int l(0), r(1);
	f[1] = 1, g[1] = 1, v[1] = 1;
	while (l < r){
		int x = f[++ l];
		ans[x] = g[l];
		if (! v[x + 1] && x + 1 <= N){
			v[x + 1] = 1;
			f[++ r] = x + 1;
			g[r] = g[l] + 1;
		}
		int y = REV(x);
		if (! v[y] && y <= N){
			v[y] = 1;
			f[++ r] = y;
			g[r] = g[l] + 1;
		}
	}
}

int main(){

	pretreat();

	int tcase;
	scanf("%d", &tcase);
	
	for (int t = 1; t <= tcase; ++ t){
		scanf("%d", &n);
		printf("Case #%d: %d\n", t, ans[n]);
	}

	return 0;
}
