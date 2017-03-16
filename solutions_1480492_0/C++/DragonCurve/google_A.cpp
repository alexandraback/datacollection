#include <stdio.h>
double abs(double p)
{
	return p>0?p:-p;
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t1,t,n,i,j,k;
	double loc_now1,loc_now2,loc_tmp;
	double time,min;
	char tmp;
	double v[100],loc[100];
	scanf("%d",&t);
	int flag=0;
	for(t1=1;t1<=t;t1++)
	{
		min = 1000000000;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf(" %c %lf %lf",&tmp,v+i,loc+i);
		}
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(abs(loc[i] - loc[j])<=5)
					continue;

				if(v[i] > v[j] && loc[i] < loc[j])
				{
					time = (loc[j] - loc[i] - 5) / (v[i] - v[j]);
				}
				else if(v[i]<v[j] && loc[i] > loc[j])
				{
					time = (loc[i] - loc[j] - 5) / (v[j] - v[i]);
				}
				else
					continue;
				loc_now1 = loc[i] + v[i] * time;
				loc_now2 = loc[j] + v[j] * time;
				flag = 0;
				for(k=0;k<n;k++)
				{
					loc_tmp = loc[k] + v[k] * time;
					if(abs(loc_tmp - loc_now1)<=5 && abs(loc_tmp - loc_now2)<=5 && k!=i && k!=j)
					{
						flag = 1;
						break;
					}
				}
				if(flag == 1 && time <min)
					min = time;
			}
		}
		if(min == 1000000000)
			printf("Case #%d: Possible\n",t1);
		else
			printf("Case #%d: %lf\n",t1,min);
	}
	return 0;
}