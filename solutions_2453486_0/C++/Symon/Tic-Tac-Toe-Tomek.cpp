#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

typedef int LL;

char str[7][7];
LL who()
{
	LL x,o,t,r,c;
	for(r=0;r<=3;r++)
	{
		x=0;
		o=0;
		t=0;
		for(c=0;c<=3;c++)
		{
			if(str[r][c]=='X'){x++;}
			else if(str[r][c]=='O'){o++;}
			else if(str[r][c]=='T'){t++;}
		}
		if(x==4||(x==3&&t==1)){return 1;}
		if(o==4||(o==3&&t==1)){return 2;}
	}
	for(c=0;c<=3;c++)
	{
		x=0;
		o=0;
		t=0;
		for(r=0;r<=3;r++)
		{
			if(str[r][c]=='X'){x++;}
			else if(str[r][c]=='O'){o++;}
			else if(str[r][c]=='T'){t++;}
		}
		if(x==4||(x==3&&t==1)){return 1;}
		if(o==4||(o==3&&t==1)){return 2;}
	}
	r=0;
	c=0;
	x=0;
	o=0;
	t=0;
	while(r<=3)
	{
		if(str[r][c]=='X'){x++;}
		else if(str[r][c]=='O'){o++;}
		else if(str[r][c]=='T'){t++;}
		r++;
		c++;
	}
	if(x==4||(x==3&&t==1)){return 1;}
	if(o==4||(o==3&&t==1)){return 2;}
	r=0;
	c=3;
	x=0;
	o=0;
	t=0;
	while(r<=3)
	{
		if(str[r][c]=='X'){x++;}
		else if(str[r][c]=='O'){o++;}
		else if(str[r][c]=='T'){t++;}
		r++;
		c--;
	}
	if(x==4||(x==3&&t==1)){return 1;}
	if(o==4||(o==3&&t==1)){return 2;}
	return 0;
}
int main()
{
	LL t,i,incmplt,j,win,cas=0;
	freopen("ain.txt","r",stdin);
	freopen("aout.txt","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		for(i=0;i<=3;i++){scanf("%s",str[i]);}
		incmplt=0;
		for(i=0;i<=3;i++)
		{
			for(j=0;j<=3;j++)
			{
				if(str[i][j]=='.'){incmplt=1;break;}
			}
			if(incmplt){break;}
		}
		win=who();
		if(win==1){printf("Case #%d: X won\n",++cas);continue;}
		if(win==2){printf("Case #%d: O won\n",++cas);continue;}
		if(win==0&&incmplt==0){printf("Case #%d: Draw\n",++cas);continue;}
		printf("Case #%d: Game has not completed\n",++cas);
	}
	return 0;
}