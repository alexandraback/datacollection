#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

int use[1010],N,T,t;
int a[1010],b[1010];

int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;
		memset(use,0,sizeof(use));
		for(int i=1;i<=N;i++) scanf("%d%d",a+i,b+i);
		int num=0,ans=0;
		int next_v,next_j;
		for(int i=1;i<=2*N;i++)
		{
			next_v=0;
			for(int j=1;j<=N;j++)
			{
				if(use[j]==0&&num>=b[j])
				{
					next_v=3;
					next_j=j;
				}
				else if(use[j]==1&&num>=b[j]&&next_v<3)
				{
					next_v=2;
					next_j=j;
				}
				else if(use[j]==0&&num>=a[j]&&next_v<2)
				{
					if(next_v==0)
					{
						next_v=1;
						next_j=j;
					}
					else if(next_v==1)
					{
						if(b[next_j]<b[j]) next_j=j;
					}
				}
			}
			if(next_v==0) break;
			else if(next_v==1)
			{
				use[next_j]=1;
				num++;
				ans++;
			}
			else if(next_v==2)
			{
				use[next_j]=2;
				num++;
				ans++;
			}
			else
			{
				num+=2;
				ans++;
				use[next_j]=2;
			}
		}
		cout<<"Case #"<<++t<<": ";
		if(num!=2*N) cout<<"Too Bad"<<endl;
		else cout<<ans<<endl;
	}
	return 0;
}
