#include <stdio.h>
#include <stdlib.h>

int main()
{
	int T,tcase,answer,R,C,W;


	scanf("%d",&T);
	for(tcase=1;tcase<=T;tcase++)
	{
		scanf("%d %d %d", &R, &C, &W);
		answer = (R-1)*(C/W) + (C-W)/W + W;
		if(C-W > 0 && (C%W) != 0)
			answer++;
		printf("Case #%d: %d\n",tcase,answer);
	}

	return 0;
}

