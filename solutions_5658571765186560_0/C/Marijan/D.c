#include <stdio.h>

int main() {
	int i,T,tt,N;
	scanf("%d\n",&T);
	for (tt=1;tt<=T;tt++) {
		int X,R,C;
		scanf("%d %d %d\n",&X,&R,&C);
		printf("Case #%d: %s\n",tt,
			X==1||
			X==2&&R*C%2==0||
			X==3&&R*C%3==0&&R+C>4||
			X==4&&(R*C==16||R*C==12)
			?"GABRIEL":"RICHARD");
	}
	return 0;
}
