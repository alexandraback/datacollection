#include <stdio.h>

int main()
{
int T,N,S,P,t;
int i,j;

scanf("%d",&T);
for(i = 0; i < T; i++) {
	int max;
	
	max = 0;
	scanf("%d", &N);
	scanf("%d", &S);
	scanf("%d", &P);
	for(j = 0; j < N; j++) {
		scanf("%d",&t);
		if(P == 0) max++;
		   else if(t != 0) {
			if(t+2 >= 3*P) max++;
			   else if((t+4 >= 3*P) && (S > 0)) {max++; S--;}
			}
		
		}
	printf("Case #%d: %d\n",i+1,max);
	}
return 0;
}
