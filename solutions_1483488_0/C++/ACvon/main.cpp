#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <map>

using namespace std;

const int N = 100;
const int M = 2000007;

int sv[N];
int a[N], b[N];
int A, B, top;
map<int, int> vis;

int is(int x) {
	int i, j, t, m = 0, n = x, ans = 0;
	vis.clear();
	while(x) {
		a[m++] = x%10;
		x /= 10;
	}
	for(i = 0; i < m; ++i) 		b[i] = a[m-i-1];
	for(i = 0; i < m; ++i)		b[i + m] = b[i];

	for(i = 0; i < m; ++i) {
		if(b[i] == 0)	continue;
		t = 0;
		for(j = i; j < i + m; ++j) {
			t = t*10 + b[j];
		}
		if(t >= A && t <= B && t > n){
			if(vis[t] == 0) {
				vis[t] = 1;
				++ans;
			}
		}
	}
	return ans;
}

int main() {
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);

	int cas = 0, t, n;
	int res;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &A, &B);
		res = 0;

		for(n = A; n < B; ++n) {
			res += is(n);
		}
		printf("Case #%d: %d\n", ++cas, res);
	}
	return 0;
}
