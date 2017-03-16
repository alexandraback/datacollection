#include <stdio.h>

int main()
{
	int sc[31]={0,1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,9,9,9,10,10,10};
	int ssc[31]={-1,-1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,9,9,9,10,10,10,-1,-1};
	int t,T,N,S,p,i,tmp,c;
//	for(i=0;i<31;i++) printf("%d)%d ", i,sc[i]);printf("\n");
	scanf("%d", &T);
	for(t=0;t<T;t++) {
		scanf("%d %d %d",&N,&S,&p);
//		printf("%d %d %d\n", N,S,p);
		c=0;
		for(i=0;i<N;i++) {
			scanf("%d", &tmp);
			if(sc[tmp]>=p) c++;
			else if(S>0 && ssc[tmp]>=p) { S--; c++; }
		}
		printf("Case #%d: %d\n", t+1, c);
	}
}
