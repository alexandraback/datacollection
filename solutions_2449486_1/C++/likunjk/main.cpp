#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

int data[107][107];

inline void Init()
{
	freopen("input.in","r",stdin);
	freopen("output.txt","w",stdout);
}


int main(void)
{
	Init();
	int i,j,n,m,T,cases;
	scanf("%d",&cases);
	for(T=1;T<=cases;T++)
	{
		scanf("%d %d",&n,&m);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				scanf("%d",&data[i][j]);
			}
		}
		printf("Case #%d: ",T);
		if(n==1 || m==1)
		{
			printf("YES\n");
			continue;
		}
		int state = 0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				int k;
				int temp = 0;
				for(k=1;k<=m;k++)
				{
					if(data[i][k] > data[i][j])
					{
						temp = 1;
						break;
					}
				}
				if(temp==0)
					continue;
				temp = 0;
				for(k=1;k<=n;k++)
				{
					if(data[k][j] > data[i][j])
					{
						temp = 1;
						break;
					}
				}
				if(temp==1)
				{
					state = 1;
					break;
				}
			}
			if(state == 1)
				break;
		}

		if(state==0)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}