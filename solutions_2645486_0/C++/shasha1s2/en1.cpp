#include<cstdio>
using namespace std;
int main()
{
	int T,test,E,R,N,i,max,sum,k,j;
	scanf("%d",&T);
	for(test=1;test<=T;test++)
	{
		scanf("%d%d%d",&E,&R,&N);
		int a[N];
		max=0;
		for(i=0;i<N;i++)
		{
			scanf("%d",&a[i]);
		}
		if(E>=R)
		{
			k=0;
			for(i=0;i<N;i++)
			{
				sum=0;
				for(j=0;j<N;j++)
				{
					if(j==k)
						sum+=a[k]*E;
					else
						sum+=a[j]*R;
				}
				k++;
				if(sum>max)
					max=sum;
			}
		}
		else
		{
			max=0;
			for(i=0;i<N;i++)
			{
				max+=(a[i]*E);
			}
		}
		printf("Case #%d: %d\n",test,max);
	}
	return 0;
}