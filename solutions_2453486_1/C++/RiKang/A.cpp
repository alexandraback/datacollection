#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<vector>

using namespace::std;

char a[15][15];
int ca,p=0;

void input()
{
	int i;
	for(i=1;i<=4;i++)
		scanf("%s",&a[i][1]);
}
void process()
{
	int i,j,o;
	p=0;
	o=0;
		for(j=1;j<=4;j++)
			if(a[j][j]=='O' || a[j][j]=='.')
				o++;
		if(o==0)
			p=1;
		o=0;
		for(j=1;j<=4;j++)
			if(a[j][5-j]=='O' || a[j][5-j]=='.')
				o++;
		if(o==0)
			p=1;
	for(i=1;i<=4;i++)
	{
		o=0;
		for(j=1;j<=4;j++)
			if(a[i][j]=='O' || a[i][j]=='.')
				o++;
		if(o==0)
			p=1;
	}
	for(j=1;j<=4;j++)
	{
		o=0;
		for(i=1;i<=4;i++)
			if(a[i][j]=='O' || a[i][j]=='.')
				o++;
		if(o==0)
			p=1;
	}
		o=0;
		for(j=1;j<=4;j++)
			if(a[j][j]=='X' || a[j][j]=='.')
				o++;
		if(p==0 && o==0)
			p=2;
		o=0;
		for(j=1;j<=4;j++)
			if(a[j][5-j]=='X' || a[j][5-j]=='.')
				o++;
		if(p==0 && o==0)
			p=2;
	for(i=1;i<=4;i++)
	{
		o=0;
		for(j=1;j<=4;j++)
			if(a[i][j]=='X' || a[i][j]=='.')
				o++;
		if(p==0 && o==0)
			p=2;
	}
	for(j=1;j<=4;j++)
	{
		o=0;
		for(i=1;i<=4;i++)
			if(a[i][j]=='X' || a[i][j]=='.')
				o++;
		if(p==0 && o==0)
			p=2;
	}
		o=0;
	for(j=1;j<=4;j++)
	{
		for(i=1;i<=4;i++)
			if( a[i][j]=='.')
				o++;
	}
	if(p==0 && o==0)
		p=3;
}
void output()
{
	if(p==1)
		printf("Case #%d: X won\n",ca);
	else if(p==2)
		printf("Case #%d: O won\n",ca);
	else if(p==3)
		printf("Case #%d: Draw\n",ca);
	else
		printf("Case #%d: Game has not completed\n",ca);
}

int main()
{
	int i,t;
	freopen("A-large.in","rt",stdin);
	freopen("A-large.out","wt", stdout);
	scanf("%d",&t);
	while(t--)
	{
		ca++;
		input();
		process();
		output();
	}
	return 0;
}