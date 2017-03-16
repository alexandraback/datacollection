#include <stdio.h>

#define TEST_NUM 5

char inname[100];
char outname[100];

char ori[10010];
int arr[150000];
int d[8][8]=
{
	{0,1,2,3,4,5,6,7},
	{1,4,3,6,5,0,7,2},
	{2,7,4,1,6,3,0,5},
	{3,2,5,4,7,6,1,0},
	{4,5,6,7,0,1,2,3},
	{5,0,7,2,1,4,3,6},
	{6,3,0,5,2,7,4,1},
	{7,6,1,0,3,2,5,4}
};

void process()
{
	int n,c=0,l,i,j;
	long long x;
	scanf("%d%lld%s",&l,&x,ori);
	if(x>11)
	{
		x-=11;
		x%=4;
		x+=11;
	}
	for(i=0;i<l;i++)
		arr[i]=ori[i]-'i'+1;
	for(i=1;i<x;i++)
		for(j=0;j<l;j++)
			arr[i*l+j]=arr[j];
	n=l*x;
	for(i=0;i<n;i++)
	{
		if(c==1)
			break;
		c=d[c][arr[i]];
	}
	c=0;
	for(;i<n;i++)
	{
		if(c==2)
			break;
		c=d[c][arr[i]];
	}
	c=0;
	for(;i<n;i++)
		c=d[c][arr[i]];
	if(c==3)
		printf("YES");
	else
		printf("NO");
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