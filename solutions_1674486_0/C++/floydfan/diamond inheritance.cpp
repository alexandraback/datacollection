// diamond inheritance.cpp : main project file.

//#include "stdafx.h"
#include<iostream>
#include<queue>
using namespace std;
int arr[1010];

int parents[1010][11];

int main()
{
	freopen("test.txt","r",stdin);
	freopen("op.txt","w",stdout);
	int tests;
	scanf("%d",&tests);
	for(int l=1;l<=tests;l++)
	{
		int num;
		scanf("%d",&num);
		int i,j,k;
		for(i=1;i<=num;i++)
		{
			scanf("%d",&arr[i]);
			for(j=0;j<arr[i];j++)
				scanf("%d",&parents[i][j]);

		}
		bool isdim=false;
		for(i=1;i<=num&&!isdim;i++)
		{
			for(j=1;j<=num&&!isdim;j++)
			{
				if(i==j)
					continue;
				queue <int> Q;
				int count=0;
				Q.push(i);
				bool flag[1010]={false};
				flag[i]=true;
				while(!Q.empty()&&!isdim)
				{
					int x=Q.front();
					Q.pop();
					for(k=0;k<arr[x];k++)
					{
						int y=parents[x][k];
						if(y==j)
						{
							count++;
							if(count>1)
							{
								isdim=true;
								break;
							}
							continue;
						}
						if(!flag[y])
						{
							Q.push(y);
							flag[y]=true;
						}
					}
					

				}
			}
		}
		if(isdim)
		printf("Case #%d: Yes\n",l);
		else
			printf("Case #%d: No\n",l);
	}
    return 0;
}
