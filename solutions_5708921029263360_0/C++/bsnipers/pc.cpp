#include <stdio.h>

int main()
{
	int cas;
	scanf("%d",&cas);
	for(int T=1; T<=cas; T++){
		int a,b,c,d;
		scanf("%d %d %d %d",&a,&b,&c,&d);
		if(d>c)
			d=c;
		printf("Case #%d: %d\n",T,a*b*d);
		int now=1,shift=0;
		for(int i=1; i<=a; i++){
			now=shift;
			for(int j=1; j<=b; j++){
				for(int k=0; k<d; k++){
					printf("%d %d %d\n",i,j,now+1);
					now=(now+1)%c;
				}
			}
			shift=(shift+1)%c;
		}
	}
	return 0;
}
