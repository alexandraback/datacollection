#include<cstdio>
#include<algorithm>
using namespace std;

int a[1500], x[1500], t, n;

int main(){
	scanf("%d", &t);
	for (int c = 1; c <= t; c++){
		scanf("%d", &n);
		for (int i = 0; i < n; i++){
			scanf("%d", &a[i]); a[i]--;
			x[i] = i;
		}

		int ans = 0;
		do{
			for (int i = 2; i <= n; i++){
				bool tt = true;
				for (int j = 0; j < i; j++){
					if (a[x[j]] != x[(j + i - 1) % i] && a[x[j]] != x[(j + 1) % i]){
						tt = false; 
						break;
					}
				}
				if (tt) ans = ans > i? ans: i;
			}
		}while (next_permutation(x, x + n));

		printf("Case #%d: %d\n", c, ans);
	}
	return 0;
}
