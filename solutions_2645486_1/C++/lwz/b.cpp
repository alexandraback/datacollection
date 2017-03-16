#include<cstdio>
using namespace std;
int main()
{
int N,T; scanf("%d",&N);
for(T=1;T<=N;T++)
{
	int a,s,n,m,k,v;
	int b[10000][2],bc;
	scanf("%d%d%d",&m,&k,&n);
	if( k>m ) k=m;
	scanf("%d",&v);
	bc=0;
	b[bc][0]=v;
	b[bc][1]=m;
	bc++;
	for(a=1;a<n;a++)
	{
		scanf("%d",&v);
		int t=m-k;
		while( bc>0 )
		{
			if( b[bc-1][0]>v ) break;
			if( b[bc-1][1]>t )
			{
				b[bc-1][1]-=t;
				t=0;
				break;
			}
			t-=b[bc-1][1];
			bc--;
		}
		b[bc][0]=v;
		b[bc][1]=m-t;
		bc++;
	}
	long long sm=0;
	for(a=0;a<bc;a++)
	{
//printf("%d %d\n",b[a][0],b[a][1]);
		sm+=(long long)b[a][0]*b[a][1];
	}
	printf("Case #%d: %I64d",T,sm);
	printf("\n");
}
	return 0;
}
