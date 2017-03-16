#include <stdio.h>

int T;
int SMax;
char S[10010];


int main() {

	scanf("%d",&T);

	for(int t = 1; t <= T;t++) {
		scanf("%d",&SMax);
		scanf("%s",S);
		int result = 0;
		int curShinessLvl = 0;
		
		for(int i = 0; i <= SMax;i++) {
			if(curShinessLvl >= i) {
				curShinessLvl += S[i]-'0';				
			} else if(S[i]-'0' > 0) {
				result += i - curShinessLvl;
				curShinessLvl = i + S[i]-'0';
			}
		}
		
		printf("Case #%d: %d\n",t,result);
	}
	return 0;

}
