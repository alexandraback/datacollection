#include <stdio.h>

#define TEST_NUM 7

char inname[100];
char outname[100];

int isPossible(int x,int r,int c)
{
	if(r*c%x)
		return 0;
	if(x==1||x==2)
		return 1;
	if(x==3)
	{
		if(r==3&&c==1||r==1&&c==3)
			return 0;
		return 1;
	}
	if(x==4)
	{
		if(r<=2||c<=2)
			return 0;
		return 1;
	}
}

void process()
{
	int x,r,c;
	scanf("%d%d%d",&x,&r,&c);
	if(isPossible(x,r,c))
		printf("GABRIEL");
	else
		printf("RICHARD");
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