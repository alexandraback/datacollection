#include <stdio.h>

int main(void)
{
	int T, execTime;
	int Flag;
	int X, R, C;

	freopen("D-small-attempt2.in.txt", "r", stdin);
	//freopen("in.txt", "r", stdin);
	scanf("%d", &T);
	freopen("Result.txt", "w", stdout);
	for(execTime = 0; execTime < T; execTime++) {
		Flag = 0;
		scanf("%d %d %d", &X, &R, &C);
		
		if(X == 1) 
			Flag = 1;
		if(X == 2) {
			if(R % 2 == 0 || C % 2 == 0)
				Flag = 1;
		}
		if(X == 3) {
			if((R % 3 == 0 && C % 2 == 0) || (R % 2 == 0 && C % 3 == 0) ||(R % 3 ==0 && C % 3 == 0))
				Flag = 1;
		}
		if(X == 4) {
			if((R % 4 == 0 && C > 2) || (R > 2 && C % 4 == 0))
				Flag = 1;
			else
				Flag = 0;
		}
		if(!Flag)
			printf("Case #%d: RICHARD\n", execTime+1);
		else
			printf("Case #%d: GABRIEL\n", execTime+1);
	}
	return 0;
}