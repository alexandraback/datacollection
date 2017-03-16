#include <stdio.h>

int main()
{
	freopen("D-small-attempt0.in","r",stdin);
	freopen("pd0.out","w",stdout);
	int cas;
	scanf("%d",&cas);
	for(int T=1; T<=cas; T++){
		int x,r,c;
		scanf("%d %d %d",&x,&r,&c);
		if(r>c){
			int tmp=r;
			r=c;
			c=tmp;
		}
		printf("Case #%d: ",T);
		switch(x){
			case 1:
				printf("GABRIEL\n");
				break;
			case 2:
				if(r*c%2==0)
					printf("GABRIEL\n");
				else
					printf("RICHARD\n");
				break;
			case 3:
				if(r*c%3==0){
					if(r>=2 && c>=3)
						printf("GABRIEL\n");
					else
						printf("RICHARD\n");
				}else{
					printf("RICHARD\n");
				}
				break;
			case 4:
				if(r*c%4==0){
					if(r>=3 && c>=4)
						printf("GABRIEL\n");
					else
						printf("RICHARD\n");
				}else{
					printf("RICHARD\n");
				}
				break;
			case 5:
				if(r*c%5==0){
					if((r>=4 && c>=5) || (r==3 && c>=6))
						printf("GABRIEL\n");
					else
						printf("RICHARD\n");
				}else{
					printf("RICHARD\n");
				}
				break;
			case 6:
				if(r*c%6==0){
					if(r>=4 && c>=6)
						printf("GABRIEL\n");
					else
						printf("RICHARD\n");
				}else{
					printf("RICHARD\n");
				}
				break;
			default:
				printf("GABRIEL\n");
		}
	}
	return 0;
}
