#include <stdio.h>

int main(){
	int T, t, x, y, i;
	scanf("%d", &T);
	for(t = 1; t <= T; ++t){
		scanf("%d %d", &x, &y);
		printf("Case #%d: ", t);
		while(x != 0){
			if(x < 0){
				putchar('E');
				putchar('W');
				x += 1;
			}else{
				putchar('W');
				putchar('E');
				x -= 1;
			}
		}
		while(y != 0){
			if(y < 0){
				putchar('N');
				putchar('S');
				y += 1;
			}else{
				putchar('S');
				putchar('N');
				y -= 1;
			}
		}
		printf("\n");
	}
}