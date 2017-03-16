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
	 else if(x==3 && (( r==2 && c==3) || (r==3 && c==2) || ( r==4 && c==3) || (r==3 && c==4) || (r==3 && c==3)) ) 
		 printf("Case #%d: GABRIEL\n",i);
	 else if(x==4 && (( r==4 && c==4)  || ( r==4 && c==3) || (r==3 && c==4)) ) 
		 printf("Case #%d: GABRIEL\n",i);
	 else
		 printf("Case #%d: RICHARD\n",i);
 }
 return 0;
}