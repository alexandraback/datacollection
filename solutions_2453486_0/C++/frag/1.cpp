#include<iostream>
#include<cstdio>
#define maxn 6
using namespace std;
int dx[9]={-1,1,0,0,-1,-1,1,1};
int dy[9]={0,0,-1,1,-1,1,-1,1};
int tu[maxn][maxn];
int sum;
bool Check(int x,int y,int sym)
{
	if(x>=1&&x<=4&&y>=1&&y<=4&&(tu[x][y]==sym||tu[x][y]==3))
		return 1;
	return 0;
}
bool Check1()
{
	for(int i=1;i<=4;i++)
		for(int j=1;j<=4;j++)
		{
			for(int k=0;k<8;k++)
			{
				int x=i,y=j,cnt=0;
				while(Check(x,y,1))
				{
					cnt++;
					x+=dx[k];
					y+=dy[k];
				}
				if(cnt==4)
					return 1;
			}
		}
	return 0;
}
bool Check2()
{
	for(int i=1;i<=4;i++)
		for(int j=1;j<=4;j++)
		{
			for(int k=0;k<8;k++)
			{
				int x=i,y=j,cnt=0;
				while(Check(x,y,2))
				{
					cnt++;
					x+=dx[k];
					y+=dy[k];
				}
				if(cnt==4)
					return 1;
			}
		}
	return 0;
}
void Init()
{
	char lt;
	for(int i=1;i<=4;i++)
		for(int j=1;j<=4;j++)
		{
			cin>>lt;
			if(lt=='T')
				tu[i][j]=3;
			if(lt=='X')
				tu[i][j]=2;
			if(lt=='O')
				tu[i][j]=1;
			if(lt=='.')
			{
				sum--;
				tu[i][j]=0;
			}
		}
	bool c1=Check1(),c2=Check2();
	if((c1&&c2)||(!c1&&!c2&&sum==0))
		printf("Draw\n");
	else if(c1&&!c2)
		printf("O won\n");
	else if(!c1&&c2)
		printf("X won\n");
	else if(!c1&&!c2)
		printf("Game has not completed\n");
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		sum=0;
		printf("Case #%d: ",i);
		Init();
	}
	return 0;
}
