#include <stdio.h>

int main()
{
	int T,c=1;
	scanf("%d",&T);
	while(T--)
	{
		int R,C,W;
		scanf("%d%d%d",&R,&C,&W);
		C=R*C;

		if(W==C)
		{
			printf("Case #%d: %d\n",c++,W);
		}
		else
		{
			// W < C
			if(C/W < 2)
			{
				printf("Case #%d: %d\n",c++,W + C/W);
			}
			else
			{
				// C/W >=2
				printf("Case #%d: %d\n",c++,W + C/W - 1*(C%W == 0 ? 1 : 0));
			}
		}
	}
}