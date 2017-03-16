#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <sstream>
#include <cstring>
using namespace std;
int c,d,v;
int dp[100];
int ma[40];
int main()
{
	int t,x,count;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		vector<int> vec;
		count=0;
		scanf("%d",&c);
		scanf("%d",&d);
		scanf("%d",&v);
		memset(dp,0,sizeof(dp));
		memset(ma,0,sizeof(ma));
		dp[0]=1;
		for(int j=0;j<d;j++)
		{
			scanf("%d",&x);
			vec.push_back(x);
			for(int k=v-x;k>=0;k--)
			{
				if(dp[k]==1)
				dp[k+x]=dp[k];
			}
		}
		//sort(vec.begin(),vec.end());
		for(int j=0;j<vec.size();j++)
		{
			ma[vec[j]]=1;
		}
		int flag,max2,count2;
		for(int j=1;j<=v;j++)
		{
			if(dp[j]==0)
			{
				max2=0;
				flag=0;
				for(int k=1;k<=j;k++)
				{
					count2=0;
					if(ma[k]==0)
					{
						//vec.push_back(k);
						//ma[k]=1;
						for(int z=v-k;z>=0;z--)
						{
							if(dp[z]==1 && dp[z+k]==0)
							{
								//dp[z+k]=dp[z];
								count2++;
							}
						}
						//count++;
						//cout<<"k : "<<k<<"\n";
						//break;
						if(count2>max2)
						{
							max2 = count2;
							flag = k;
						}
					}
				}
				if(flag!=0)
				{
					vec.push_back(flag);
					ma[flag]=1;
					for(int z=v-flag;z>=0;z--)
					{
						if(dp[z]==1)
						{
							dp[z+flag]=dp[z];
						}
					}
					count++;
				}
			}
		}
		printf("Case #%d: %d\n",i,count);
	}
	return 0;
}