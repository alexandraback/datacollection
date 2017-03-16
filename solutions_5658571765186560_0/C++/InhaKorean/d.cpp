#include <stdio.h>
int T, CC=1;
int main(){
	scanf("%d", &T);
	while(T--){
		bool ans;

		int X,R,C;
		scanf("%d%d%d", &X, &R, &C);
		if(R*C % X > 0) ans = false;
		else if(X == 1) ans = true;
		else if(X == 2) ans = (R*C%2 == 0);
		else if(X == 3) {
			if(R == 1 || C == 1) ans = false;
			else ans = true;
		}
		else if(X == 4){
			if(R < 3 || C < 3) ans = false;
			else ans = true;
		}
		else ans = false;

		if(ans) printf("Case #%d: GABRIEL\n", CC++);
		else printf("Case #%d: RICHARD\n", CC++);
	}
	return 0;
}
