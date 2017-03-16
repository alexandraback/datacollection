#include <cstdio>

int T, R, C, W;

int main(){
	scanf("%d", &T);
	for(int xx = 1; xx <= T; ++xx){
		scanf("%d%d%d", &R, &C, &W);
		int preFail = (R - 1) * (C / W);
		int maxFail = C / W - 1;
		int total = maxFail + W;
		if(C % W) total++;
		printf("Case #%d: %d\n", xx, total + preFail);
	}
}
