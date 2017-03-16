#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"

int fp[5]={1,4,9,121,484};

int main()
{
	int T;
	int t=1;
	int A,B;
	int flag;
	scanf("%d",&T);
	while(t<=T)
	{
		flag=0;
		scanf("%d%d",&A,&B);
		for(int i=0;i<5;i++)
			if(fp[i]>=A&&fp[i]<=B)flag++;
		printf("Case #%d: %d\n",t,flag);
		t++;
	}
	return 0;
}