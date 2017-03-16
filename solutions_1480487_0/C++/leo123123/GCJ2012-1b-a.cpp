#include <iostream>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

int num[205];
double res[205];
bool have[205];

int main()
{
	freopen("G://GCJ/A-small.in","r",stdin);
	freopen("G://GCJ/1.out","w",stdout);
	int T;
	scanf("%d",&T);
	for (int i=0;i<T;i++)
	{
		int N;
		memset(res,0,sizeof(res));
		memset(have,0,sizeof(have));
		scanf("%d",&N);
		double sum=0;
		for (int j=0;j<N;j++)
		{
			scanf("%d",&num[j]);
			sum+=num[j];
		}
		double sumx=sum;
		sum=2*sum;
		double avg=sum/N;
		int NN=N;
		for(int j=0;j<N;j++)
		{
			if(num[j] > avg)
			{
				sum-=num[j];
				have[j]=true;
				NN--;
			}
		}
		for(int j=0;j<N;j++)
		{
			if(have[j] == false)
				res[j]=(sum/NN-num[j])/sumx*100;
		}
		printf("Case #%d: ",i+1);
		for(int j=0;j<N;j++)
		{
			printf("%f",res[j]);
			if(j != N-1)
				printf(" ");
		}
		printf("\n");
	}	
	return 0;
}