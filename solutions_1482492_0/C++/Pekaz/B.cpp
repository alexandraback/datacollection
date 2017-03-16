#include <stdio.h>
#include <math.h>

struct car_info
{
	double t;
	double x;
};
car_info car[3];

int main()
{
	int t,tcase;
	int i,j,n,A;
	double desti,ac,re,V,temp,temp2;

	FILE *in,*out;
	in=fopen("B-small-attempt1.in","r");
	out=fopen("output.txt","w");

	fscanf(in,"%d",&tcase);
	for(t=0;t<tcase;t++)
	{
		fscanf(in,"%lf",&desti);
		fscanf(in,"%d",&n);
		fscanf(in,"%d",&A);
		for(i=0;i<n;i++)
			fscanf(in,"%lf%lf",&car[i].t,&car[i].x);
		fprintf(out,"Case #%d:\n",t+1);
		for(i=0;i<A;i++)
		{
			fscanf(in,"%lf",&ac);
			re=0;
			if(n==1)
				re=sqrt(2*desti/ac);
			else
			{
				V=(car[1].x-car[0].x)/car[1].t;
				temp=(2*V+sqrt(4*V*V+8*ac*car[0].x))/(2*ac);
				temp2=(2*V-sqrt(4*V*V+8*ac*car[0].x))/(2*ac);
				if(temp2>=0 && temp2<temp)
					temp=temp2;
				if(temp*V+car[0].x>desti)
					re=sqrt(2*desti/ac);
				else
				{
					if((desti-car[0].x)/V<sqrt(2*desti/ac))
						re=sqrt(2*desti/ac);
					else
						re=(desti-car[0].x)/V;
				}
			}
			fprintf(out,"%lf\n",re);
		}
	}

	return 0;
}