#include<stdio.h>
#include<malloc.h>
int r,c,w,sum;
int main()
{
	int cases;
	scanf("%d",&cases);
	int countcase=0;
	while(countcase<cases)
	{
		sum=0;
		countcase++;
		printf("Case #%d: ",countcase);
		scanf("%d%d%d",&r,&c,&w);
		if(w==1)
		{
			printf("%d\n",(r*c));
			continue;
		}
		sum+=(c/w)*(r-1);
		if(c%w==0)
		{
			sum+=(c/w-1);
		}
		else
		{
			sum+=(c/w);
		}
		sum+=1;
		sum+=(w-1);
		printf("%d\n",sum);
	}
}
