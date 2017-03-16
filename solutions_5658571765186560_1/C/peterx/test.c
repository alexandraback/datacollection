#include <stdio.h>

int main()
{
	int T,k,X,L,R;
	freopen("in.txt","r",stdin);
	scanf("%d",&T);
	freopen("Result.txt","w",stdout);

	for (k=1;k<=T;k++)
	{
		scanf("%d %d %d",&X,&R,&L);
		if (R*L%X) 
		{
			printf("Case #%d: RICHARD\n", k); 
			continue;
		}

		if (X==3)
		{
			if (((R>=3) && (L>=2))  || ((L>=3) && (R>=2)))
				printf("Case #%d: GABRIEL\n", k); 
			else
				printf("Case #%d: RICHARD\n", k);
		} 

		if (X==4)
		{
			if (((R>=3) && (L>=4))  || ((L>=3) && (R>=4)))
				printf("Case #%d: GABRIEL\n", k); 
			else
				printf("Case #%d: RICHARD\n", k);	
		}

		if (X<=2) 
			printf("Case #%d: GABRIEL\n", k); 

		if (X>=5)
				printf("Case #%d: RICHARD\n", k); 
	}

}