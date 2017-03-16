#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int tt = 1;
char bd[105][105];
void solve(void)
{
	int R,C,M;
	scanf("%d %d %d",&R,&C,&M);
	int im = 0;
	int P = R*C-M;
	int i,j;
	int nnr;
	int last = 0;
	if(R==1||C==1||P==1)
	{
		for(i=0;i<R;i++)
			for(j=0;j<C;j++)
			if(P>0)
			{
				bd[i][j] = '.';
				P--;
			}
			else
			{
				bd[i][j] = '*';
			}
		for(i=0;i<R;i++)
			for(j=0;j<C;j++)
			if(bd[i][j]=='.')
			{
				bd[i][j] = 'c';
				i = R+R;
				j = C+C;
			}
	}
	else
	{
		im = 1;


		for(i=2;i<=R;i++)
		{
			int nr = P/i;
			if(P%i)
				nr++;
			if(nr>C)
				continue;
			if(nr<2)
				continue;
			if(P%i==0)
			{
				nnr = i;
				im = 0;

			}
			else if(P%i!=1&&P/i>=2)
			{
				nnr = i;
				im = 0;
			}
			else if(P%i==1&&i!=2&&P/i>2)
			{
				nnr = i;
				last = 1;
				im = 0;
			}
			else
			continue;

			break;
		}
		for(i=0;i<R;i++)
				for(j=0;j<C;j++)
					bd[i][j] = '*';
		if(im==0)
        {


		int nnnr = P/nnr;

		for(i=0;i<nnr;i++)
			for(j=0;j<nnnr;j++)
				bd[i][j] = '.';
		for(i=0;i<P%nnr;i++)
			bd[i][nnnr] = '.';
		if(last==1)
		{
			bd[nnr-1][nnnr-1] = '*';
			bd[1][nnnr] = '.';
		}
		for(i=0;i<R;i++)
			for(j=0;j<C;j++)
			if(bd[i][j]=='.')
			{
				bd[i][j] = 'c';
				i = R+R;
				j = C+C;
			}
        }
	}
	printf("Case #%d:\n",tt++);
	if(im)
		printf("Impossible\n");
	else
	{
		for(i=0;i<R;i++)
		{
			for(j=0;j<C;j++)
				printf("%c",bd[i][j]);
				printf("\n");
		}

	}
}
int main(void)
{
	freopen("C-large.in","r",stdin);
	freopen("C.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		solve();
	}

	return 0;
}
