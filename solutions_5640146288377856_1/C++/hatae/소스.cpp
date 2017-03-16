#pragma warning(disable:4996)
#include <stdio.h>

int main(){
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i){
		int r, c, w;
		scanf("%d%d%d", &r, &c, &w);
		int ans = c / w;
		ans *= r;
		if (c % w == 0){
			ans += w - 1;
		}
		else{
			ans += w;
		}
		printf("Case #%d: %d\n", i + 1, ans);
	}
	return 0;
}