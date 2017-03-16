#include <iostream>
#include <algorithm>
using namespace std;

int T,R,C,M;
char G[55][55];
void Tran()
{
	for(int i=0;i<50;i++)
	{
		for(int j=0;j<i;j++)
		{
			char c = G[i][j];
			G[i][j] = G[j][i];
			G[j][i] = c;
		}
	}
}
int main()
{
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	bool trans;
	bool ok;
	scanf("%d",&T);
	for(int cas=1;cas<=T;cas++)
	{
		scanf("%d %d %d",&R,&C,&M);
		trans = 0;
		if(R>C)
		{
			trans = 1;
			swap(R,C);
		}
		for(int i=0;i<50;i++)
		{
			for(int j=0;j<50;j++)
				G[i][j]='.';
		}
		G[R-1][C-1]='c';
		ok = 0;
		if(R==1)
		{
			if(M<=R*C-2)
			{
				for(int i=0;i<M;i++)
				{
					G[0][i] = '*';
				}
				ok = 1;	
			}
			else
			{
				ok = 0;	
			}
		}
		else if(R==2)
		{
			if(M%2==0)
			{
				for(int i=0;i<M/2;i++)
				{
					G[0][i] = '*';
					G[1][i] = '*';
				}
				ok = 1;	
			}
			else
			{
				ok = 0;	
			}
		}
		else
		{
			int safe_num = (R-2)*(C-2);
			if(M<=safe_num)
			{
				for(int i=0;i<R-2;i++)
				{
					for(int j=0;j<C-2;j++)
					{
						G[i][j]='*';
						M--;
						if(M==0) break;
					}
					if(M==0) break;
				}
				ok = 1;	
			}
			else if(M>R*C-4)
			{
				ok = 0;	
			}
			else if( (M-safe_num)%2==0 )
			{
				for(int i=0;i<R-2;i++)
				{
					for(int j=0;j<C-2;j++)
					{
						G[i][j]='*';	
					}
				}
				M-=safe_num;
				if(M>=0) for(int i=0;i<R-2;i++)
				{
					G[i][C-2] = '*';
					G[i][C-1] = '*';
					M-=2;
					if(M==0) break;
				}
				if(M>=0) for(int i=0;i<C-2;i++)
				{
					G[R-2][i] = '*';
					G[R-1][i] = '*';
					M-=2;
					if(M==0) break;
				}
				ok = 1;	
			}
			else
			{
				ok = 0;	
			}
		}
		if(trans)
		{
			swap(R,C);
			Tran();
		}
		printf("Case #%d:\n",cas);
		if(ok)
		{
			for(int i=0;i<R;i++)
			{
				for(int j=0;j<C;j++)
				{
					printf("%c",G[i][j]);	
				}
				printf("\n");
			}
		}
		else
		{
			printf("Impossible\n");
		}
	}
	return 0;	
}
