#include<iostream>
#include<string.h>
#include<stdio.h>
#include<memory.h>
using namespace std;

int n1,i1;
double c,f,x,tot,chan,p1,p2;

int main()
{
	scanf("%d",&n1);
	
	for(i1=1;i1<=n1;i1++)
	{
		scanf("%lf %lf %lf",&c,&f,&x);
		tot=0;chan=2;
		while(true)
		{
			p1=x/chan;
			p2=c/chan+x/(chan+f);
			
			if(p2<p1)
			{
				tot+=c/chan;
				chan=chan+f;
			}
			else
			{
				tot+=x/chan;
				break;
			}
		}
		printf("Case #%d: %0.7f\n",i1,tot);
	}
	return 0;
}
