#include <stdio.h>
#include <algorithm>
using namespace std;

typedef long long I;

I a[101];
int A[100];
I b[101];
int B[100];

I f[102][102];

int N,M;

void com(int x,int y)
{
	f[x][y]=0;
	int i=x,j=y;
	I ra=a[x],rb=A[x]==B[y]?b[y]:0,s=0;
	while(i<N || j<M)
	{
		I t=min(ra,rb);
		s+=t;
		ra-=t;rb-=t;
		if(f[x][y]<f[i+1][j+1]+s)
		{
			f[x][y]=f[i+1][j+1]+s;
		}
		if(i<N && ra==0)
		{
			++i;
			ra+=A[i]==A[x]?a[i]:0;
		}
		else if(ra==0)break;
		if(j<M && rb==0)
		{
			++j;
			rb+=B[j]==A[x]?b[j]:0;
		}
		else if(rb==0)break;
	}
	i=x;j=y;
	ra=A[x]==B[y]?a[x]:0,rb=b[y],s=0;
	while(i<N || j<M)
	{
		I t=min(ra,rb);
		s+=t;
		ra-=t;rb-=t;
		if(f[x][y]<f[i+1][j+1]+s)
		{
			f[x][y]=f[i+1][j+1]+s;
		}
		if(i<N && ra==0)
		{
			++i;
			ra+=A[i]==B[y]?a[i]:0;
		}
		else if(ra==0)break;
		if(j<M && rb==0)
		{
			++j;
			rb+=B[j]==B[y]?b[j]:0;
		}
		else if(rb==0)break;
	}
}

int main()
{
	freopen("C-large.in","r",stdin);
	freopen("C-large.out","w",stdout);
	int T,Tc=0;
	scanf("%d",&T);
	while(++Tc<=T)
	{
		printf("Case #%d: ",Tc);
		int i,j;
		scanf("%d %d",&N,&M);
		for(i=0;i<N;i++)
		{
			scanf("%I64d %d",&a[i],&A[i]);
		}
		a[N]=0;
		for(i=0;i<M;i++)
		{
			scanf("%I64d %d",&b[i],&B[i]);
		}
		b[M]=0;
		memset(f,0,sizeof(f));
		for(i=N;i>=0;i--)
		{
			for(j=M;j>=0;j--)
			{
				com(i,j);
			}
		}
		printf("%I64d\n",f[0][0]);
	}
	return 0;
}
