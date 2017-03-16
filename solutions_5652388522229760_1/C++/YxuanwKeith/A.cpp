#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long LL;

int Test, Num, Now;
bool Flag[10];

int main() {
	//freopen("A.in", "r", stdin), freopen("A.out", "w", stdout);
	
	scanf("%d", &Test);
	for (int i = 1; i <= Test; i ++) {
		scanf("%d", &Now);
		memset(Flag, 0, sizeof Flag);
		if (Now == 0) {
			printf("Case #%d: INSOMNIA\n", i);
			continue;
		}
		Num = 0;
		int Ans = 1; 
		while (Num < 10) {
			LL p = 1ll * Now * Ans;
			while (p) {
				if (!Flag[p % 10]) Num ++;
				Flag[p % 10] = 1;
				p /= 10;
			}
			if (Num == 10) {
				printf("Case #%d: %lld\n", i, 1ll * Ans * Now);
				break;
			}
			Ans ++;
		}
	}
}