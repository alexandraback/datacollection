#include <cstdio>
#include <cstring>
int a[55][55],x,y,sx,sy,i,j,flg,n,m,tmp,P,cas,CAS;

void write()
{
	int i,j;
	if (flg)
	for (i=1; i<=m; ++i,printf("\n"))
	for (j=1; j<=n; ++j)
	{
		if (a[j][i]==1) printf("*"); else
		if (a[j][i]==9) printf("c"); else printf(".");
	} else
	for (i=1; i<=n; ++i,printf("\n"))
	for (j=1; j<=m; ++j)
	{
		if (a[i][j]==1) printf("*"); else
		if (a[i][j]==9) printf("c"); else printf(".");
	}
}

void work1()
{
	if (m==1)
	{
		flg=1;
		tmp=n,n=m,m=tmp;
	}
	for (i=1; i<=m; ++i)
	{
		if (i==m) printf("c"); else
		if (i<=P) printf("*"); else printf(".");
		if (flg) printf("\n");
	}
	if (!flg) printf("\n");
}

void work2()
{
	if ((P&1) || (n*m-P==2 && n*m>=4))
	{
		printf("Impossible\n");
		return;
	}
	if (m==2)
	{
		flg=1;
		tmp=n,n=m,m=tmp;
	}
	for (i=1; i<=P/2; ++i) a[1][i]=a[2][i]=1;
	a[1][m]=9;
	write();
}

void work3()
{
	for (i=1; i<=n; ++i,printf("\n"))
	for (j=1; j<=m; ++j)
	if (i+j==2) printf("c"); else printf("*");
}

void work4()
{
	a[n][m]=9;
	sx=sy=1;
	x=y=1;
	while (P)
	{
		--P;
		a[x][y]=1;
		if (x==n-2 && y==m-2) break;
		--x,++y;
		if (x<1 || y>m-2)
		{
			if (sx==n-2) ++sy; else ++sx;
			x=sx,y=sy;
		}
	}
	if (P==0)
	{
		write();
		return;
	}
	j=0;
	while (P)
	{
		if (++j==m-2) break;
		a[n-1][j]=a[n][j]=1;
		if (P==1)
		{
			a[n-2][m-2]=0;
			write();
			return;
		}
		P-=2;
	}
	i=0;
	while (P)
	{
        if (++i==n-2) break;
		a[i][m-1]=a[i][m]=1;
		if (P==1)
		{
            a[n-2][m-2]=0;
			write();
			return;
		}
		P-=2;
	}
	if (P==0) write(); else
	if (P==2)
	{
		a[n-1][m-2]=a[n][m-2]=1;
  		write();
	} else
	if (P==4)
	{
        a[n-1][m-2]=a[n][m-2]=a[n-2][m-1]=a[n-2][m]=1;
		write();
	} else printf("Impossible\n");
}

void fffff()
{
	if (n*m-P==1)
	{
		work3();
		return;
	}
	flg=0;
    if (n==1 || m==1)
	{
		work1();
		return;
	}
	if (n==2 || m==2)
	{
		work2();
		return;
	}
	work4();
}

int main()
{
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	scanf("%d",&CAS);
	for (cas=1; cas<=CAS; ++cas)
	{
		printf("Case #%d:\n",cas);
		memset(a,0,sizeof a);
		scanf("%d%d%d",&n,&m,&P);
		fffff();
	}
	return 0;
}
