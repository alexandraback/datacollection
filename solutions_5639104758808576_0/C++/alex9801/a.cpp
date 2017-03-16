#include <stdio.h>

#define TEST_NUM 1

char inname[100];
char outname[100];

char ori[1010];
int arr[1010];

void process()
{
	int n,r=0,c,i;
	scanf("%d%s",&n,ori);
	for(i=0;i<=n;i++)
		arr[i]=ori[i]-'0';
	c=arr[0];
	for(i=1;i<=n;i++)
	{
		if(arr[i]&&c<i)
		{
			r+=i-c;
			c=i;
		}
		c+=arr[i];
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