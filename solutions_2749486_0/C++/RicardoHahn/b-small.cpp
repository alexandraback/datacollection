#include <stdio.h>

int main()
{
	int t;
	scanf("%d",&t);

	for(int ccnt=1; ccnt<=t; ++ccnt)
	{
		int x,y;
		scanf("%d %d",&x,&y);

		printf("Case #%d: ",ccnt);
		char * d;
		if(x==0)
			d = "";
		else if (x<0)
			d = "EW";
		else
			d = "WE";

		if(x<0) x = -x;

		while(x--)
			printf("%s",d);

		if(y==0)
			d = "";
		else if (y<0)
			d = "NS";
		else
			d = "SN";

		if(y<0) y = -y;

		while(y--)
			printf("%s",d);

		printf("\n");
	}
	return 0;
}



