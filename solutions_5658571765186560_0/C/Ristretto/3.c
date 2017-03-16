#include<stdio.h>

#define RICHARD 0
#define GABRIEL 1

int main(){

	int t=0, x=0, r=0, c=0, i=0, win=0, m=0, n=0, tmp=0;
	char *winner[]={"RICHARD","GABRIEL"};

	scanf("%d",&t);

	for (i=1;i<=t;i++) {
		scanf("%d %d %d", &x, &r, &c);
		m = r>c ? c : r;
		n = r>c ? r : c;
		switch(x){
		case 1: win = GABRIEL; break;
		case 2: win = (m*n)%2==0 ? GABRIEL : RICHARD; break;
		case 3: tmp = 100*m + n; win = (tmp==203||tmp==303||tmp==304) ? GABRIEL : RICHARD; break;
		case 4: tmp = 100*m + n; win = (tmp==304||tmp==404) ? GABRIEL : RICHARD; break;
		default: fprintf(stderr, "ERROR."); return 1;
		}
		printf("Case #%d: %s\n", i, winner[win]);
	}

	return 0;
}
