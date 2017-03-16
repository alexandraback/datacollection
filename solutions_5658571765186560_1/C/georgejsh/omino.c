#include<stdio.h>

int main()
{
 int t;
 int i;
 int x,r,c;
 for(scanf("%d",&t),i=1;i<=t;i++)
 {
	 scanf("%d%d%d",&x,&r,&c);
	 if(x==1)
		printf("Case #%d: GABRIEL\n",i);
	 else if(x==2 && (r*c)%2!=1)
		printf("Case #%d: GABRIEL\n",i);
	 else if((r%x==0  && c>=x-1) || (c%x==0 && r>=x-1))
		 printf("Case #%d: GABRIEL\n",i);
	 else
		 printf("Case #%d: RICHARD\n",i);
 }
 return 0;
}