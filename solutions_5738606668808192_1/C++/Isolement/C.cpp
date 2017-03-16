#include<cstdio>
int n,N,J,ans,a[50];
void g(int,int);
void f(int x,int y)
{
	if(x+2*y>N-2)
		g(x,y);
	else if(y==0)
	{
		for(int j=0;j<N;j++)
			printf("%d",a[j]);
		for(int j=0;j<9;j++)
			printf(" %d",j+3);		
		printf("\n");ans++;
		if(ans!=J)
			g(x,y);
	}
	else
	{
		a[x]=1;a[x+1]=1;
		f(x+2,y-1);
	}
}
void g(int x,int y)
{
	int z;
	for(int i=x-1;i>=0;i--)
	{
		if(i==1)
			return;
		if(a[i]==1)
		{
			a[i]=0;a[i-1]=0;z=i;
			break;
		}
	}
	f(z,y+1);
}
int main()
{
	//freopen("out.txt","w",stdout);
	scanf("%d",&n);
	for(int casei=1;casei<=n;casei++)
	{
		scanf("%d%d",&N,&J);
		printf("Case #%d:\n",casei);
		ans=0;
		for(int i=0;i<(N-2)/2&&ans!=J;i++)
		{
			for(int i=0;i<N;i++)a[i]=0;
			a[0]=1;a[1]=1;a[N-2]=1;a[N-1]=1;
			f(2,i);
		}
	}
}
