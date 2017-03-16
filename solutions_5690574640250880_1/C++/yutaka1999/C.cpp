#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#define SIZE 55

using namespace std;

int mp[SIZE][SIZE];

int main()
{
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		printf("Case #%d:\n",t);
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		int emp=a*b-c;
		if(emp==1)
		{
			printf("c");
			for(int i=0;i<a;i++)
			{
				for(int j=0;j<b;j++)
				{
					if(i!=0||j!=0)
					{
						printf("*");
					}
				}puts("");
			}
		}
		else if(a==1)
		{
			printf("c");
			for(int i=1;i<emp;i++) printf(".");
			for(int i=emp;i<b;i++)
			{
				printf("*");
			}puts("");
		}
		else if(b==1)
		{
			printf("c\n");
			for(int i=1;i<emp;i++) printf(".\n");
			for(int i=emp;i<a;i++)
			{
				printf("*\n");
			}
		}
		else if(emp==2||emp==3||emp==5||emp==7||(emp%2==1&&(a==2||b==2)))
		{
			puts("Impossible");
		}
		else
		{
			memset(mp,0,sizeof(mp));
			if(emp%2==0)
			{
				int zan=emp;
				for(int i=0;i<a;i++)
				{
					if(zan>0)
					{
						mp[i][0]=mp[i][1]=1;
						zan-=2;
					}
				}
				int s=2;
				while(zan>=2*a)
				{
					for(int i=0;i<a;i++)
					{
						if(zan>0)
						{
							mp[i][s]=mp[i][s+1]=1;
							zan-=2;
						}
					}
					s+=2;
				}
				if(s+1<b&&zan>2)
				{
					for(int i=0;i<a;i++)
					{
						if(zan>0)
						{
							mp[i][s]=mp[i][s+1]=1;
							zan-=2;
						}
					}
				}
				else
				{
					for(int i=0;i<zan;i++)
					{
						mp[i][s]=1;
					}
				}
			}
			else
			{
				int zan=emp;
				if(2*(a+b-2)<=zan)
				{
					zan-=2*(a+b-2);
					for(int i=0;i<a;i++)
					{
						mp[i][0]=mp[i][1]=1;
					}
					for(int i=0;i<b;i++)
					{
						mp[0][i]=mp[1][i]=1;
					}
					for(int i=2;i<a;i++)
					{
						for(int j=2;j<b;j++)
						{
							if(zan>0)
							{
								mp[i][j]=1;
								zan--;
							}
						}
					}
				}
				else
				{
					for(int i=0;i<3;i++)
					{
						for(int j=0;j<3;j++)
						{
							mp[i][j]=1;
							zan--;
						}
					}
					for(int i=3;i<a;i++)
					{
						if(zan>0)
						{
							mp[i][0]=mp[i][1]=1;
							zan-=2;
						}
					}
					for(int i=3;i<b;i++)
					{
						if(zan>0)
						{
							mp[0][i]=mp[1][i]=1;
							zan-=2;
						}
					}
				}
			}
			printf("c");
			for(int i=0;i<a;i++)
			{
				for(int j=0;j<b;j++)
				{
					if(i!=0||j!=0)
					{
						if(mp[i][j]==1) printf(".");
						else printf("*");
					}
				}puts("");
			}
		}
	}
	return 0;
}
