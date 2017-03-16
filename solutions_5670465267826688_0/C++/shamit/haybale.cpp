#include<bits/stdc++.h>
using namespace std;
int ii,i,j,dp[100001][5],s,ans,t,flag,mat[10][10],l,x,arr[100001];
	char str[100001];
int main()
{
	
	freopen("input.in","r",stdin);
	freopen("ans.txt","w",stdout);
	scanf("%d",&t);
	for(ii=1;ii<=t;ii++)
	{
		scanf("%d%d",&l,&x);
		scanf("%s",str);
		for(i=0;i<x;i++)
		{
			for(j=0;j<l;j++)
			{
				if(str[j]=='i')
					arr[i*l+j]=2;
				else if(str[j]=='j')
					arr[i*l+j]=3;
				else if(str[j]=='k')
					arr[i*l+j]=4;
			}
		}
		mat[1][1]=1; mat[1][2]=2; mat[1][3]=3; mat[1][4]=4;
		mat[2][1]=2; mat[2][2]=-1; mat[2][3]=4; mat[2][4]=-3;
		mat[3][1]=3; mat[3][2]=-4; mat[3][3]=-1; mat[3][4]=2;
		mat[4][1]=4; mat[4][2]=3; mat[4][3]=-2; mat[4][4]=-1;
		l=l*x;
		//for(i=0;i<l;i++)
		//	cout<<arr[i]<<" ";
		//cout<<endl;
		memset(dp,0,sizeof(dp));
		ans=arr[0];
		if(ans==2)
			dp[0][2]=1;   // dp[0][i]=1
		for(i=1;i<l;i++)
		{
			if(ans>0)
				ans=mat[ans][arr[i]];
			else 
				ans=-1*mat[abs(ans)][arr[i]];
			if(ans==2)
				dp[i][2]=1;
		}
		ans=1;
		for(i=0;i<l;i++)
		{
			if(dp[i][2]==1)
			{
				ans=1;
				for(j=i+1;j<l;j++)
				{
					if(ans>0)
						ans=mat[ans][arr[j]];
					else 
						ans=-1*mat[-1*ans][arr[j]];
					if(ans==3)
						dp[j][3]=1;
						
				}
			}
		}
		ans=1;
		flag=0;
		for(i=0;i<l;i++)
		{
			if(dp[i][3]==1)
			{
				ans=1;
				for(j=i+1;j<l;j++)
				{
					if(ans>0)
						ans=mat[ans][arr[j]];
					else 
						ans=-1*mat[-1*ans][arr[j]];
				}
				if(ans==4)
				{
					flag=1;
					break;
				}
			}

		}
		if(flag==1)
			printf("Case #%d: YES\n",ii);
		else
			printf("Case #%d: NO\n",ii);
	}
}
