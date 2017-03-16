#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int main()
{
	int i,t,x,r,c;
	scanf("%d",&t);
	for(i = 1; i <= t; i++)
	{
		scanf("%d %d %d",&x,&r,&c);
		if( x >= 7 )
			printf("Case #%d: RICHARD\n",i);
		else if(x>r && x>c)
			printf("Case #%d: RICHARD\n",i);
		else if( (r*c)%x != 0 )
			printf("Case #%d: RICHARD\n",i);
		else if( (x+1)/2 > min(r,c) )
			printf("Case #%d: RICHARD\n",i);
		else if( x==1 || x==2 || x==3 )
			printf("Case #%d: GABRIEL\n",i);
		else if( x==4 && min(r,c) > 2 )
			printf("Case #%d: GABRIEL\n",i);
		else if( x==4 )
			printf("Case #%d: RICHARD\n",i);
		else if( x==5 && !( min(r,c)==3 && max(r,c)==5 ) )
			printf("Case #%d: GABRIEL\n",i);
		else if( x==5 )
			printf("Case #%d: RICHARD\n",i);
		else if( x==6 && min(r,c) > 3 )
			printf("Case #%d: GABRIEL\n",i);
		else if( x==6 )
			printf("Case #%d: RICHARD\n",i);
	}
	return 0;
}