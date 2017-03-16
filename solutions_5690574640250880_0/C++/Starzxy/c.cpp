#include<cstdio>
#include<bitset>

using namespace std;

int t,n,m,num;
int mx[10],my[10];
int ma[10][10],mm[10][10];
bitset<30> map;

inline bool check(int x,int y)
{
	if(x>0&&x<=n&&y>0&&y<=m)
		return true;
	return false;
}

void dfs(int x,int y)
{
	bool flag=true;
	
	for(int i=1;i<=8;i++)
		if(check(x+mx[i],y+my[i])&&ma[x+mx[i]][y+my[i]])
		{
			flag=false;
			break;
		}
	
	if(!flag)
		mm[x][y]=3;
	else
	{
		mm[x][y]=2;
		for(int i=1;i<=8;i++)
			if(check(x+mx[i],y+my[i])&&!mm[x+mx[i]][y+my[i]])
				dfs(x+mx[i],y+my[i]);
	}
}

inline bool test(int x,int y)
{
	if(ma[x][y])return false;
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			mm[i][j]=ma[i][j];
	
	bool flag=true;
	
	dfs(x,y);
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			if(!mm[i][j])
			{
				flag=false;
				break;
			}
		if(!flag)break;
	}
	
	return flag;
}

inline char change(int x)
{
	if(x==0)return '.';
	if(x==1)return '*';
	return 'c';
}

int main()
{
	mx[1]=-1;
	my[1]=-1;
	mx[2]=-1;
	my[2]=0;
	mx[3]=-1;
	my[3]=1;
	mx[4]=0;
	my[4]=1;
	mx[5]=1;
	my[5]=1;
	mx[6]=1;
	my[6]=0;
	mx[7]=1;
	my[7]=-1;
	mx[8]=0;
	my[8]=-1;
	
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	
	scanf("%d",&t);
	
	for(int t1=1;t1<=t;t1++)
	{
		scanf("%d%d%d",&n,&m,&num);
		
		int temp=1<<(n*m);
		bool flag=false;
		
		for(int k=0;k<temp;k++)
		{
			map=k;
			
			if(map.count()==num)
			{
				for(int i=1;i<=n;i++)
					for(int j=1;j<=m;j++)
						ma[i][j]=map[(i-1)*m+j-1];
				
				for(int i=1;i<=n;i++)
				{
					for(int j=1;j<=m;j++)
						if(test(i,j))
						{
							ma[i][j]=2;
							flag=true;
							break;
						}
					if(flag)break;
				}
			}
			if(flag)break;
		}
		
		printf("Case #%d:\n",t1);
		
		if(flag)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=m;j++)
					printf("%c",change(ma[i][j]));
				printf("\n");
			}
		}
		else
			printf("Impossible\n");
	}
	
	return 0;
}
