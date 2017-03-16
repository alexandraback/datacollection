#include<cstdio>
#include<cmath>

int TestCase,Case;

int MIN(int a,int b){return a<b?a:b;}

int r,R,C,M,i,j,k,Sum;

char Sol[100][100];

int main()
{
//	freopen("c.in","rb",stdin);
//	freopen("c.out","wb",stdout);
	scanf("%d",&TestCase);
	for(Case=1;Case<=TestCase;Case++)
	{
		scanf("%d%d%d",&R,&C,&M);
		if(R*C==M)
		{
			printf("Case #%d:\nImpossible\n",Case);
			continue;
		}
		for(i=0;i<R;i++)
			for(Sol[i][C]=0,j=0;j<C;j++)
				Sol[i][j]='*';
		if(C==1)
		{
			Sum=0;
			for(j=0,i=1;i<R*C-M;i++)
				Sol[i][j]='.';
		}
		else if(R==1)
		{
			Sum=0;
			for(i=0,j=1;j<R*C-M;j++)
				Sol[i][j]='.';
		}
		else 
		{
			Sum=R*C-M;
			if(Sum==1)
			{
				Sum=0;
				Sol[0][0]='.';
			}
			else
			{
				if(Sum<4)
				{
					printf("Case #%d:\nImpossible\n",Case);
					continue;
				}
				for(r=MIN(Sum/2,R);r>=2;r--)
				{
					if(r*C<Sum)
					{
						printf("Case #%d:\nImpossible\n",Case);
						break;
					}
					if((Sum%r)==1)
					{
						if(Sum==2*r+1||r==2)continue;
						for(i=0;i<r;i++)
							for(j=0;j<(Sum/r)-1;j++)
								Sol[i][j]='.';
						for(i=0;i<r-1;i++)
							Sol[i][Sum/r-1]='.';
						Sol[0][Sum/r]=Sol[1][Sum/r]='.';
						Sum=0;
						break;
					}
					else
					{
						for(i=0;i<r;i++)
							for(j=0;j<(Sum/r);j++)
								Sol[i][j]='.';
						for(i=0;i<(Sum%r);i++)
							Sol[i][Sum/r]='.';
						Sum=0;
						break;
					}
				}
				if(r==1)printf("Case #%d:\nImpossible\n",Case);
			}	
		}
		if(Sum)continue;
		printf("Case #%d:\n",Case);
		Sol[0][0]='c';
		for(i=0;i<R;i++)
			puts(Sol[i]);
	}
	return 0;
}
