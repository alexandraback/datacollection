#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int main()
{
	//	freopen("A.in","r",stdin);freopen("A.out","w",stdout);
//	freopen("A-small-attempt0.in","r",stdin);freopen("A-small-attempt0.out","w",stdout);
//	freopen("A-small-attempt1.in","r",stdin);freopen("A-small-attempt1.out","w",stdout);
//	freopen("A-small-attempt2.in","r",stdin);freopen("A-small-attempt2.out","w",stdout);
	freopen("A-large.in","r",stdin);freopen("A-large.out","w",stdout);
	

    int tt,i,j,ii;
	double k1,x,g,r,t;


	scanf("%d",&tt);
	for(ii=1;ii<=tt;ii++)

	{
		scanf("%lf%lf",&r,&t);
		k1=((1-2*r)+sqrt((2*r-1)*(2*r-1)+8*t))/4.0;
		for(j=1;j<=20;j++)
		{
			x=(int)(k1+j-10);
			if (x<1)  continue;
			if (x*x*2+(2*r-1)*x==t)  
			{
				g=x;
				break;
			}
			if (x*x*2+(2*r-1)*x>t)
			{
				g=x-1;
				break;
			}
		}
		printf("Case #%d: %.0lf\n",ii,g);
	}

	
	
	
	
	
	
	
	
	return 0;

}