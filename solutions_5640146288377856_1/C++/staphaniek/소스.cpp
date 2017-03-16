#include<stdio.h>
#define max(a,b) a>b?a:b
int T, ans, R, C, W;
int main(){
	freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	for (int t = 1; t <= T; t++){
		scanf("%d %d %d", &R, &C, &W);
		ans = 0;
		if (C%W == 0){
			ans = (C / W) - 1 + W;
			ans *= R;
		}
		else{
			ans = (C / W) + W;
			ans *= R;
		}
		printf("Case #%d: %d\n", t, ans);
	}
	return 0;
}