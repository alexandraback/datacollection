#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
char s[10][10];

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	scanf("%d",&t);
	int cas=0;
	while(t--)
	{
		int i,j;
		printf("Case #%d: ",++cas);
		for(i=0;i<4;i++)
		{
			scanf("%s",s[i]);
		}
		int flag=0;
		int pp=0;
		for(i=0;i<4;i++)
		{
			int T=0,X=0,O=0;
			for(j=0;j<4;j++)
			{
				if(s[i][j]=='T')
				{
					T++;
				}
				if(s[i][j]=='X')
				{
					X++;
				}
				if(s[i][j]=='O')
				{
					O++;
				}
				if(s[i][j]=='.')
				{
					pp=1;
				}
			}
			if(T+X==4)
			{
				flag=1;
				break;
			}
			if(T+O==4)
			{
				flag=2;
				break;
			}
		}
		if(flag==0)
		{
			for(j=0;j<4;j++)
			{
				int T=0,X=0,O=0;
				for(i=0;i<4;i++)
				{
					if(s[i][j]=='T')
					{
						T++;
					}
					if(s[i][j]=='X')
					{
						X++;
					}
					if(s[i][j]=='O')
					{
						O++;
					}
				}
				if(T+X==4)
				{
					flag=1;
					break;
				}
				if(T+O==4)
				{
					flag=2;
					break;
				}
			}
		}
		if(flag==0)
		{
			int T=0,X=0,O=0;
			for(i=0;i<4;i++)
			{
				if(s[i][i]=='T')
				{
					T++;
				}
				if(s[i][i]=='X')
				{
					X++;
				}
				if(s[i][i]=='O')
				{
					O++;
				}
			}
			if(T+X==4)
			{
				flag=1;
			}
			if(T+O==4)
			{
				flag=2;
			}
		}
		if(flag==0)
		{
			int T=0,X=0,O=0;
			for(i=0;i<4;i++)
			{
				if(s[i][3-i]=='T')
				{
					T++;
				}
				if(s[i][3-i]=='X')
				{
					X++;
				}
				if(s[i][3-i]=='O')
				{
					O++;
				}
			}
			if(T+X==4)
			{
				flag=1;
			}
			if(T+O==4)
			{
				flag=2;
			}
		}
		if(flag==1)
		{
			printf("X won\n");
		}
		else if(flag==2)
		{
			printf("O won\n");
		}
		else
		{
			if(pp)
			{
				printf("Game has not completed\n");
			}
			else
			{
				printf("Draw\n");
			}
		}
	}





	fclose(stdin);
	fclose(stdout);
	return 0;
}
