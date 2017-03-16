#include <stdio.h>

#define TEST_NUM 3

char inname[100];
char outname[100];

int arr[1010];

void process()
{
	int n,r=1000,t,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	for(i=1;i<=1000;i++)
	{
		t=i;
		for(j=0;j<n;j++)
			t+=(arr[j]-1)/i;
		r=t<r?t:r;
	}
	printf("%d",r);
}

void pre_process()
{
}

int main()
{
	sprintf(inname,"%d.in",TEST_NUM);
	sprintf(outname,"%d.out",TEST_NUM);
	freopen(inname,"r",stdin);
	freopen(outname,"w",stdout);
	int tn,ti;
	scanf("%d",&tn);
	pre_process();
	for(ti=1;ti<=tn;ti++)
	{
		printf("Case #%d: ",ti);
		process();
		printf("\n");
	}
	return 0;
}