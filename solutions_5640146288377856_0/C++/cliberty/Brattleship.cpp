#include <stdio.h>

int main()
{
	int T,c=1;
	scanf("%d",&T);
	while(T--)
	{
		int R,C,W;
		scanf("%d%d%d",&R,&C,&W);

		/*int k = W%C;

		if(k


		if(W%C == 0)
		{
			printf("Case #%d: %d\n",c++,W/C + C-1);
		}
		else
		{
			printf("Case #%d: %d\n",c++,W/C + C);
		}*/

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