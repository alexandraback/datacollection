#include <stdio.h>
int main(){
	int t, p;
	scanf("%d", &t);
	for(p=1;p<=t;p++){
		int x,r,c;
		scanf("%d%d%d", &x, &r, &c);
		printf("Case #%d: ", p);
		if ((x+1)/2 > r || (x+1)/2 > c){
			printf("RICHARD\n");
			continue;
		}
		if (x==1) {
			printf("GABRIEL\n");
			continue;
		}
		if (x==2) {
			if ((r*c)%2 == 0)
				printf("GABRIEL\n");
			else
				printf("RICHARD\n");
			continue;
		}
		if (x == 3) {
			if ((r*c)%3 == 0)
				printf("GABRIEL\n");
			else
				printf("RICHARD\n");
			continue;
		}
		if (r > c){
			int t = r;
			r = c;
			c = t;
		}
		if (r == 2) {
			printf("RICHARD\n");
			continue;
		}
		if (r >= 3) {
			if (c == 4)
				printf("GABRIEL\n");
			else
				printf("RICHARD\n");
			continue;
		}
	}
}
