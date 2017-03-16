#include<stdio.h>
#include<algorithm>

using namespace std;

int ans[20], cnt;
int A, B;

int main() {
	freopen("C-large.in", "r", stdin);
	freopen("C-large.out", "w", stdout);
	int ntest;
	scanf("%d", &ntest);
	for(int test = 1; test <= ntest; test++) {
		scanf("%d%d", &A, &B);
		long long res = 0;
		for(int x=A; x<B; x++) {
			int u = 1; cnt = 0;
			while(u <= x) u *= 10;
			for(int p=10; p<u; p*=10) {
				if(x % p < p / 10) continue;
				int y = (x%p)*(u/p) +  x/p;
				if(y > x && y <= B) {
					ans[cnt++] = y;
				}
			}
			sort(ans, ans+cnt);
			res += unique(ans, ans+cnt) - ans;
		}

		printf("Case #%d: %I64d\n", test, res);
	}
	return 0;
}