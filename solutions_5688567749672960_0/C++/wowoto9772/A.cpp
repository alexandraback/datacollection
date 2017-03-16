#include <stdio.h>
#include <memory.h>
#include <queue>

using namespace std;

bool chk[1000005];

int R(int a){
	int t = 0;
	while (a){
		t = t * 10 + a % 10;
		a /= 10;
	}return t;
}

int main()
{
	freopen("A-small-attempt1.in", "r", stdin);
	freopen("A-small-attempt1.out", "w", stdout);

	int t;
	scanf("%d", &t);

	 for (int T = 1; T <= t; T++){
		int n;
		scanf("%d", &n);

		queue <int> a, c;
		a.push(1), c.push(1);

		memset(chk, 0, sizeof(chk));
		chk[1] = true;

		while (!a.empty()){
			int af = a.front(), cf = c.front();
			a.pop(), c.pop();
			if (af == n){
				printf("Case #%d: %d\n", T, cf);
				break;
			}
			
			if (!chk[af + 1]){
				chk[af + 1] = true;
				a.push(af + 1), c.push(cf + 1);
			}
			if (!chk[R(af)]){
				chk[R(af)] = true;
				a.push(R(af)), c.push(cf + 1);
			}
		}
	}
}