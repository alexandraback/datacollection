#include"stdio.h"
#include"string.h"
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int n;
	int a,b;
	int i,j,k;
	int count=0;
	scanf("%d",&n);
	for(count=1;count<=n;count++)
	{
		scanf("%d%d",&a,&b);
		double c[100005];
	
		for(i=0;i<a;i++)
		{
			scanf("%lf",&(c[i]));
		}
		double max=1<<29;
		double allright=1.0;
		for(i=0;i<a;i++)
		{
			allright*=c[i];
		}
		//0
		max=allright*(b-a+1)+(1-allright)*(b-a+1+b+1);
	//	printf("%.6lf\n",max);
		double right=1.0;


		for(i=a;i>=1;i--)
		{
			//double right=1.0;
			if(a-i-1>=0)
				right*=c[a-i-1];
			/*for(j=0;j<a-i;j++)
			{
				right*=c[j];
			}*/
			double num=(right*(b-a+1+2*i)+(1-right)*(b-a+1+b+1+2*i));
		//	printf("%.6lf\n",num);
			if(max>num)
			{
				max=num;
			}
		}
		if(max>(b+2))
		{
			max=double(b+2);
		}
		printf("Case #%d: %.6lf\n",count,max);

	}


	return 0;
}