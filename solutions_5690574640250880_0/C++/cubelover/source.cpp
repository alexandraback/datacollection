#include<cstdio>

int main()
{
	freopen("C-small-attempt2.in","r",stdin);
	freopen("C-small-attempt2.out","w",stdout);
	int tc,tcn;
	scanf("%d",&tcn);
	for(tc=1;tc<=tcn;tc++)
	{
		printf("Case #%d:\n",tc);

		char str[50][50];
		bool possible=false;
		int i,j,k,l,r,c,m;
		scanf("%d%d%d",&r,&c,&m);
		for(i=0;i<r;i++)for(j=0;j<c;j++)str[i][j]='*';
		str[0][0]='c';
		if(r==1)
		{
			possible=true;
			for(i=1;i<c;i++)if(i+m<c)str[0][i]='.';
		}
		else if(c==1)
		{
			possible=true;
			for(i=1;i<r;i++)if(i+m<r)str[i][0]='.';
		}
		else
		{
			if(m==r*c-1)possible=true;
			else
			{
				str[0][1]=str[1][1]=str[1][0]='.';
				for(i=2;i<=r;i++)
				{
					for(j=2;j<=c;j++)if(r*c-i*2-j*2+4>=m&&r*c-i*j<=m)break;
					if(j<=c)break;
				}
				if(i<=r)
				{
					possible=true;
					for(k=2;k<i;k++)str[k][0]=str[k][1]='.';
					for(l=2;l<j;l++)str[0][l]=str[1][l]='.';
					for(k=2;k<i;k++)for(l=2;l<j;l++)if((k-2)*(j-2)+(l-2)<(i-2)*(j-2)-(m-c*(r-i)-r*(c-j)+(r-i)*(c-j)))str[k][l]='.';
				}
			}
		}
		if(possible)
		{
			for(i=0;i<r;i++)
			{
				for(j=0;j<c;j++)putchar(str[i][j]);
				puts("");
			}
		}
		else puts("Impossible");
	}
}