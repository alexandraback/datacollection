#include<bits/stdc++.h>
using namespace std;

const int maxn=55;

int main()
{
	int l,N,T,i,a[maxn<<1][maxn],j,k,t,book[2505]={0};
	freopen("B-large.in","r",stdin);
	freopen("out.out","w",stdout);
	scanf("%d",&T);
	for(i=1;i<=T;i++)
	{
		memset(a,0,sizeof(a));
		memset(book,0,sizeof(book));
		scanf("%d",&N);
		for(j=0;j<2*N-1;j++)
		{
			for(k=0;k<N;k++)
			{
				scanf("%d",&a[j][k]);
			}
		}
		printf("Case #%d: ",i);
		for(j=0;j<2*N-1;j++)
		{
			for(k=0;k<N;k++)
			{
				book[a[j][k]]++;
			}
		}
		for(l=1;l<=2500;l++)
		{
			if(book[l]&1)
			{
				printf("%d ",l);
			}
		}
		printf("\n");
	}
}
