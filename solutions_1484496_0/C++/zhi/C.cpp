#include <cstdio>
#include <algorithm>

using namespace std;

int sum[1<<20],index[1<<20];

inline bool bit(int x,int i)
{
	return ((x>>i)&1);
}

inline bool cmp(int a,int b)
{
	return (sum[a]>sum[b]);
}

int main()
{
	int i,j,k,m,T,N,S[500];
	scanf("%d",&T);
	for(i=0;i<T;i++)
	{
		scanf("%d",&N);
		for(j=0;j<N;j++)
			scanf("%d",&S[j]);
		for(j=0;j<(1<<N);j++)
			sum[j]=0;
		for(j=0;j<(1<<N);j++)
			for(k=0;k<N;k++)
				if(bit(j,k))
					sum[j]+=S[k];
		for(j=0;j<(1<<N);j++)
			index[j]=j;
		sort(index,index+(1<<N),cmp);
		printf("Case #%d:\n",i+1);
		for(j=1;j<(1<<N);j++)
			if(sum[index[j-1]]==sum[index[j]])
			{
				int a[2],b;
				a[0]=index[j-1];
				a[1]=index[j];
				b=~(a[0]&a[1]);
				a[0]&=b;
				a[1]&=b;
				for(m=0;m<2;m++)
				{
					bool flag=false;
					for(k=0;k<N;k++)
						if(bit(a[m],k))
						{
							if(flag)
								printf(" ");
							printf("%d",S[k]);
							flag=true;
						}
					printf("\n");
				}
				break;
			}
	}
	return 0;
}
