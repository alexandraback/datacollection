#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

int main()
{
//		freopen("B.in","r",stdin);freopen("B.out","w",stdout);
	freopen("B-small-attempt0.in","r",stdin);freopen("B-small-attempt0.out","w",stdout);
//	freopen("A-small-attempt1.in","r",stdin);freopen("A-small-attempt1.out","w",stdout);
//	freopen("A-small-attempt2.in","r",stdin);freopen("A-small-attempt2.out","w",stdout);
	//freopen("A-large.in","r",stdin);freopen("A-large.out","w",stdout);
	int ii,i,x1,x,y,y1,tt;
    scanf("%d",&tt);
	for(ii=1;ii<=tt;ii++)
	{
		scanf("%d%d",&x,&y);
		printf("Case #%d: ",ii);
		if (x>0)  x1=x;
		else
			x1=-x;
		if (y>0)  y1=y;
		else
			y1=-y;
		for(i=1;i<=x1;i++)
		{
			if (x>0)  printf("WE");
			else
				printf("EW");
		}
		for(i=1;i<=y1;i++)
		{
			if (y>0)  printf("SN");
			else
				printf("NS");
		}
		printf("\n");

	}
	return 0;
}