#include<stdio.h>
#include<string.h>

int main(){
	int i, j, k, m, n;
	int T;
	scanf("%d", &T);
	for(int re = 1; re <= T; re++){
		int A, B;
		scanf("%d%d", &A, &B);
		int ans = 0;
		for(i = A; i < B; i++){
			k = i;
			for(j = 1; j <= k; j *= 10);
			j /= 10;
			do{
				k = j * (k % 10) + k / 10;
				if(k > i && k <= B){
					ans++;
				}
			}while(k != i);
		}
		printf("Case #%d: %d\n", re, ans);
	}
}
