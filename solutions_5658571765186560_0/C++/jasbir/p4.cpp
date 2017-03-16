#include<cstdio>
using namespace std;
int main()
{
	int ntc; scanf("%d",&ntc);
	for(int tc=1;tc<=ntc;tc++)
	{
		printf("Case #%d: ",tc);
		int X,R,C; scanf("%d %d %d",&X,&R,&C);
		if(R>C)
		{
			int tmp=R; R=C; C=tmp;
		}
		int ar=R*C;
		if(ar%X!=0)
		{
			printf("RICHARD\n"); continue;
		}
		if(X>C)
		{
			printf("RICHARD\n"); continue;
		}
		if(X>6)
		{
			printf("RICHARD\n"); continue;
		}
		if(X==1 || X==2 )
		{
			printf("GABRIEL\n");
		}
		
		if(X==3)
		{
			if(R<2) printf("RICHARD\n"); else printf("GABRIEL\n"); 
		}
		if(X==4 || X==5 || X==6)
		{
			if(R<3) printf("RICHARD\n"); else printf("GABRIEL\n"); 
		}
		
	}
}
