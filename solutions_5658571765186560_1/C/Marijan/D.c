#include <stdio.h>

int main() {
	int i,T,tt,N;
	scanf("%d\n",&T);
	for (tt=1;tt<=T;tt++) {
		int X,R,C;
		scanf("%d %d %d\n",&X,&R,&C);
		int tmp;
		if (R>C) tmp=R,R=C,C=tmp;
		printf("Case #%d: %s\n",tt,
			X<7&&C>=X&&R*C%X==0&&R>=X-1
			?"GABRIEL":"RICHARD");
	}
	return 0;
}
