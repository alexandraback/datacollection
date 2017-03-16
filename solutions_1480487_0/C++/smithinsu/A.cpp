#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstdlib>
#include<climits>
#include<cstring>
using namespace std;
#define PB push_back
#define INF 1000000000
#define MOD 1000000007
void precompute(void)
{
}
int main()
{
	int test=0,t;
	int i,total,score[1024],ltotal,l,n,j,left,flag[1024];
	long double need;

	precompute();
	while(scanf("%d",&t)!=EOF)
	{
		test=0;
		while(t--)
		{
			test++;
			printf("Case #%d: ",test);
		//	fprintf(stderr,"Case #%d: started\n",test);
			scanf("%d",&n);
			
			total=0;
			ltotal=0;
			l=0;

			for(i=0;i<n;i++)
			{
				scanf("%d",&score[i]);
				total+=score[i];
			}

			for(i=0;i<n;i++)
			{
				left=total;
				for(j=0;j<n;j++)
				{
					if(score[j]<score[i])
					{
						left-=(score[i]-score[j]);
					}
				}
				if(left>=0.000000001)
				{
					flag[i]=0;
					ltotal+=score[i];
					l++;
				}
				else
				{
					flag[i]=1;
				}
			/*	if(score[i]*n<total)
				{
					ltotal+=score[i];
					l++;
				}*/
			}

			need=1.0;
			need*=(total+ltotal);
			need/=(l);
		//	printf("need=%Lf %d\n",need,l);
			for(i=0;i<n;i++)
			{
				if(flag[i]==1)
				{
					printf("0.000000 ");
				}
				else
				{
					printf("%Lf ",100.0*(need-score[i]+0.0)/(total));
				}
			}
			printf("\n");
		}
	}
	return 0;
}
