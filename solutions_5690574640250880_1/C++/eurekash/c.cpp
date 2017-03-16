#include <cstdio>
#include <cstring>
int r,c,m,a[50][50];
bool inside(int x,int y)
{
	return x>=0&&x<r&&y>=0&&y<c;
}
bool solve()
{
	int rem=r*c-m;
	memset(a,-1,sizeof a);
	if(r==1)  
	{
		for(int i=0;i<rem;i++) a[0][i]=0;
		a[0][0]=1;
		return true;
	}
	if(c==1)
	{
		for(int i=1;i<rem;i++) a[i][0]=0;
		a[0][0]=1;
		return true;
	}
	if(rem==1)
	{
		a[0][0]=1;
		return true;
	}
	if(rem==2||rem==3||rem==5||rem==7)  return false;
	for(int p=2;p<=r;p++)
		for(int q=2;q<=c;q++)
		{
			for(int p1=0;p1<=p-2;p1++)
				for(int q1=0;q1<=q-2;q1++)
					for(int p2=0;p2<=p1;p2++)for(int q2=0;q2<=q1;q2++)
					{
						if(p*q-p1*q1+p2*q2==rem)
						{
							for(int i=0;i<p;i++)for(int j=0;j<q;j++)a[i][j]=0;
							for(int i=1;i<=p1;i++)for(int j=1;j<=q1;j++)a[p-i][q-j]=-1;
							for(int i=0;i<p2;i++)for(int j=0;j<q2;j++)a[p-p1+i][q-q1+j]=0;
							a[0][0]=1;
							return true;
						}
					}
		}
	fprintf(stderr,"%d %d %d\n",r,c,m);
	return false;
}
int main()
{
	int t,tt;
	scanf("%d",&t);
	for(tt=1;tt<=t;tt++)
	{
		scanf("%d%d%d",&r,&c,&m);
		printf("Case #%d:\n",tt);
		if(!solve()) puts("Impossible");
		else
		{
			for(int i=0;i<r;i++)
			{
				for(int j=0;j<c;j++)
					if(a[i][j]==1) putchar('c');
					else if(a[i][j]==0)  putchar('.');
					else putchar('*');
				putchar('\n');
			}

		}
	}

	return 0;
}


