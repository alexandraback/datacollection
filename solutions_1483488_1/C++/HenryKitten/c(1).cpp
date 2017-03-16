#include <stdio.h>
#include <string.h>

const int pow10[] = {1,10,100,1000,10000,100000,1000000,10000000};
const int fact[] = {1,2,6,24,120,720,5040,40320};
const int nchoose2[] = {0,0,1,3,6,10,15,21,28,36,45};

int main()
{
	int ncas;
	scanf("%d",&ncas);
	for(int t=1;t<=ncas;t++)
	{
		bool used[2000001] = {0};
		int y = 0;
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=a;i<=b;i++)
		{
			char si[20];
			if(used[i]) continue;
			sprintf(si,"%d",i);
		//	printf("i:%d\n",i);
			int slen = strlen(si);

			int same = 1;
			int ii = i;
			used[i] = 1;
			for(int j=1;j<slen;j++)
			{
				ii = (ii%10)*pow10[slen-1] + ii/10;
			//	printf("%d,%d\n",i,ii);
				if(ii <= b && ii >= a && used[ii] == 0)
				{
					used[ii] = 1;
					same++;
				}
			}
			y += nchoose2[same];
		}
		printf("Case #%d: %d\n",t,y);
	}
	return 0;
}
