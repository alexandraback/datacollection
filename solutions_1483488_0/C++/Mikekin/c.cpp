#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>

using namespace std;

const int mo = 2000001;
long long ans;
int f[mo], g[mo], t, l, r, ten[8];

void init()
{
	ans = 0; int tmp, c, k;
	cin >> l >> r;
	for (int i = l; i <= r; i++) {
		tmp = i; c = i;
		for (k = 0; k < 8; k++) {
			if (ten[k] > i) {
				--k;
				break;
			}
		}
		for (int j = 0; j < 9; j++) {
			c = c % 10 * ten[k] + c / 10;
			if (c >= ten[k]) tmp = min(tmp, c);
		}
		if (f[tmp] != t) {
			f[tmp] = t; g[tmp] = 1;
		} else ++g[tmp];
	}
}

void work()
{
	ans = 0;
	for (int i = 1; i <= r; i++) {
		if (f[i] != t) continue;
		if (g[i] < 2) continue;
		ans += (g[i] * (g[i] - 1)) / 2; 
	}
}

int main(){
	freopen("c.in","r",stdin);
	freopen("c.txt","w",stdout);
	ten[0] = 1;
	for (int i = 1; i < 8; i++) ten[i] = ten[i - 1] * 10;
	int tt; cin >> tt; t = 0;
	while (++t <= tt) {
		init();
		work();
		printf("Case #%d: %I64d\n", t, ans);
	}
	return 0;
}
