#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char map[100][100];
int r,c,m;
int main()
{
	int T;
	scanf("%d",&T);
	for(int tcase=1;tcase<=T;tcase++)
	{
		bool flag=1;
		printf("Case #%d:\n",tcase);
		memset(map,0,sizeof(map));
		scanf("%d%d%d",&r,&c,&m);
		for(int i=0;i<r;i++)
				for(int j=0;j<c;j++)
					map[i][j]='*';
		int left=r*c-m;
		if(left==1)
		{
			map[0][0]='c';
		}
		else if(c==1)
		{
			for(int i=0;i<left;i++)map[i][0]='.';
			map[0][0]='c';
		}
		else if(r==1)
		{
			for(int i=0;i<left;i++)map[0][i]='.';
			map[0][0]='c';
		}
		else if(left<4)
		{
			flag=0;	
		}
		else if(left%2==0)
		{
			for(int j=0;j<c&&left;j++)
				for(int i=0;i<2&&left;i++)
				{
					map[i][j]='.';
					left--;
				}
			for(int i=2;i<r&&left;i++)
				for(int j=0;j<2&&left;j++)
				{
					map[i][j]='.';
					left--;
				}
			for(int i=2;i<r&&left;i++)
				for(int j=2;j<c&&left;j++)
				{
					map[i][j]='.';
					left--;
				}
			map[0][0]='c';
		}
		else {
			if(min(r,c)==2||left<9)
			{
				flag=0;
			}
			else {
				for(int i=0;i<3;i++)
					for(int j=0;j<3;j++)
						map[i][j]='.';
				map[0][0]='c';
				left-=9;
				for(int j=3;j<c&&left;j++)
					for(int i=0;i<2&&left;i++)
					{
						map[i][j]='.';
						left--;
					}
				for(int i=3;i<r&&left;i++)
					for(int j=0;j<2&&left;j++)
					{
						map[i][j]='.';
						left--;
					}
				for(int j=3;j<c&&left;j++)
				{
					map[2][j]='.';
					left--;
				}
				for(int i=3;i<r&&left;i++)
					for(int j=2;j<c&&left;j++)
					{
						map[i][j]='.';
						left--;
					}
			}
		}
		if(flag)for(int i=0;i<r;i++)printf("%s\n",map[i]);
		else printf("Impossible\n");
	}
}
