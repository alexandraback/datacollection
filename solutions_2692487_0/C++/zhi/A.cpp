#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
typedef double LL;
int MIN(int a,int b)
{
	if(a<b)
		return a;
	return b;
}
int main()
{
	int T,A,N,m[100],min;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		scanf("%d%d",&A,&N);
		for(int j=0;j<N;j++)
			scanf("%d",&m[j]);
		sort(m,m+N);
		if(A==1)
			min=N;
		else
		{
			min=0;
			for(int j=0;j<N;j++)
				if(m[j]<A)
					A+=m[j];
				else
				{
					int cnt=0;
					min=N-j;
					for(int k=j;k<N;k++)
					{
						while(m[k]>=A)
						{
							A=2*A-1;
							cnt++;
						}
						A+=m[k];
						min=MIN(min,cnt+N-k-1);
						if(cnt>=min)
							break;
					}
					break;
				}
		}
		printf("Case #%d: %d\n",i+1,min);
	}
	return 0;
}
