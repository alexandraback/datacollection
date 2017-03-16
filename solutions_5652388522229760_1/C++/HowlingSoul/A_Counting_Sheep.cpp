#include <stdio.h>
#include <string.h>
int dig[15];
bool chk(){
	int i;
	for (i = 0; i <= 9; i++){
		if (dig[i] == 0) return false;
	}
	return true;
}
int main(){
	freopen("A-large.in", "r", stdin);
	freopen("A_large.out", "w", stdout);
	int t, tc;
	scanf("%d", &tc);
	for (t = 1; t <= tc; t++){
		int n, tm, ttm;
		memset(dig, 0, sizeof(dig));
		scanf("%d", &n);
		if (n == 0) printf("Case #%d: INSOMNIA\n", t);
		else{
			tm = n;
			while (true){
				ttm = tm;
				while (ttm > 0){
					dig[ttm % 10] = 1;
					ttm /= 10;
				}
				if (chk()){
					printf("Case #%d: %d\n", t, tm);
					break;
				}
				tm += n;
			}
		}
	}
	return 0;
}