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
		win = (m*n)%x==0 ? GABRIEL : RICHARD;
		switch(x){
		case 1: case 2: break;
		case 3: win = m==1 ? RICHARD : win; break;
		case 4: win = (m==1||m==2) ? RICHARD : win; break;
		case 5: win = (m==1||m==2||(m==3&&n==5)) ? RICHARD : win; break;
		case 6: win = (m==1||m==2||m==3) ? RICHARD : win; break;
		default: win = RICHARD; break;
		}
		printf("Case #%d: %s\n", i, winner[win]);
	}

	return 0;
}
