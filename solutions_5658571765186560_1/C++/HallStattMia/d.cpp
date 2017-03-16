#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<vector>
using namespace std;
int x,r,c;

void task()
{
	scanf("%d%d%d",&x,&r,&c);
	if(x>=7){printf("RICHARD\n");return;}
	if(x==1)printf("GABRIEL\n");
	if(x==2)
	{
		if(r*c%2==0)printf("GABRIEL\n");
		else printf("RICHARD\n");
	}
	if(x==3)
	{
		if(r*c%3==0 &&min(r,c)>=2)printf("GABRIEL\n");
		else printf("RICHARD\n");
	}
	if(x==4)
	{
		if(r*c%4==0 &&min(r,c)>=3)printf("GABRIEL\n");
		else printf("RICHARD\n");
	}
	if(x==5)
	{
		if(r*c%5==0 &&min(r,c)>=4)printf("GABRIEL\n");
		else printf("RICHARD\n");
	}
	if(x==6)
	{
		if(r*c%6==0 &&min(r,c)>=4)printf("GABRIEL\n");
		else printf("RICHARD\n");
	}
}
int main()
{
	int T;
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	scanf("%d",&T);
	for(int ti=1;ti<=T;ti++)
	{
		printf("Case #%d: ",ti);
		task();
	}
}

