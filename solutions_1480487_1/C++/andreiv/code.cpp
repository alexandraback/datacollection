#include <cstdio>
double v[250];


int main()
{
	int t,tt,i,n;
	
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&t);
	for (tt=1;tt<=t;++tt)
	{
		scanf("%d",&n);
		double sum=0,med,N=n;
		for (i=1;i<=n;++i) {scanf("%lf",&v[i]);sum+=v[i];}
		double x=0,y=200,z,sum2,aux;
		aux=sum;sum=sum*2;
		while (x<y)
		{z=(x+y)/2;
		    sum2=0;
		    for (i=1;i<=n;++i)
				if (v[i]<z)
					sum2+=z; else
						sum2+=v[i];
			if ((sum2>sum) && (y!=z))
				y=z; else
					if ((sum2<sum) && (x!=z))
					x=z; else
						if (sum2==sum)
							break; else
								break;
				
		}
		sum=aux;
		printf("Case #%d:",tt);
		//double ss=0;
		//each sum*2/n
		for (i=1;i<=n;++i)
		{
			
			if (v[i]>=z) printf(" 0.000000"); else
			{v[i]=z-v[i];
			 v[i]=(v[i]*100)/sum;
			 //ss+=v[i];
			 printf(" %lf",v[i]);
			}
			
			
			
		}
		//printf("\n%lf\n",ss);
		printf("\n");
	}
return 0;
}