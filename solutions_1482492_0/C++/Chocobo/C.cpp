#include<stdio.h>
#include<stdlib.h>
#include<math.h>

using namespace std;
int N,n;
double t[2005],x[2005];

int main()
{
	int z,T,A,i;
	double D,ans,a,v,t1,t2,tmeet,time;
	system("ren *.in input.in");
	freopen("input.in","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&T);
	for(z=1 ; z<=T ; z++)
	{
		scanf("%lf %d %d",&D,&N,&A);
		for(i=0 ; i<N ; i++)
		{
			scanf("%lf %lf",&t[i],&x[i]);
		}printf("Case #%d:\n",z);
		for(n=0 ; n<A ; n++)
		{
			scanf("%lf",&a);
			t1 = sqrt(D*2/a);
			if(N==1)
				printf("%.7lf\n",t1);
			for(i=1 ; i<N ; i++)
			{
				v = (x[i]-x[i-1])/(t[i]-t[i-1]);
				t1 = sqrt(D*2/a);
				tmeet = (v+sqrt(v*v+2*a*x[i-1]))/a;
				if(tmeet>=t1)
				{
					printf("%.7lf\n",t1);
				}
				else
				{
					printf("%.7lf\n",tmeet+(D-tmeet*v)/v);
				}
			}
		}
		
	}
	//for(;;);
	scanf(" ");
	
	return 0;
}
