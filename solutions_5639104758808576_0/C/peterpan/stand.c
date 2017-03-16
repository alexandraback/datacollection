#include <stdio.h>
#include <stdlib.h>

int main()
{
	int T,tcase,answer,s_max,s,total,shyness;


	scanf("%d",&T);
	for(tcase=1;tcase<=T;tcase++)
	{
		scanf("%d",&s_max);
		answer = 0;
		total = 0;
		getchar();
		for(shyness=0; shyness<=s_max; shyness++)
		{
			s = getchar()-'0';
			if(s > 0)
			{
				if(total < shyness)
				{
					answer += shyness-total;
					total = shyness;
				}
				total += s;
			}
		}
		printf("Case #%d: %d\n",tcase,answer);
	}

	return 0;
}

