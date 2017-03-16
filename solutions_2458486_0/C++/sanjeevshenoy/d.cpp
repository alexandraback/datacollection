#include<cstdio>
#include<iostream>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<functional>
#include<limits>
#include<cassert>

using namespace std;

const int max_n=105;

int T,k,n;
int a[max_n],c[max_n],m[max_n],s[max_n];
int ck[max_n][max_n];

int dp[1<<25];
string S[1<<25];

int main()
{
	scanf("%d",&T);
	for(int z=1; z<=T; z++)
	{
		map<int,int> M;
		fill(dp,dp+(1<<21),0);
		
		scanf("%d%d",&k,&n);
		for(int i=0; i<k; i++)
			scanf("%d",&s[i]);
	
		for(int i=0; i<n; i++)
		{
			scanf("%d",&c[i]);
			scanf("%d",&m[i]);
			for(int j=0; j<m[i]; j++)
				scanf("%d",&ck[i][j]);
		}
		
		dp[0]=1;
		S[0]="";
		
		for(int i=1; i<(1<<n); i++)
		{	
			S[i]='0'+n;
			
			for(int j=0; j<k; j++)
				M[s[j]]++;
			
			for(int j=0; j<n; j++)
				if(i&(1<<j))
				{
					for(int x=0; x<m[j]; x++)
						M[ck[j][x]]++;
					M[c[j]]--;
				}
				
			for(int j=0; j<n; j++)
			{
				if(i&(1<<j) and dp[i-(1<<j)])
				{
					int keys=M[c[j]]+1;
					for(int x=0; x<m[j]; x++)
						if(ck[j][x]==c[j])
							keys--;
							
					//cout<<i<<" "<<j<<" "<<c[j]<<" "<<keys<<endl;
					if(keys>0)
					{				
						dp[i]=1;
						char ch='0'+j;
						S[i]=min(S[i],S[i-(1<<j)]+ch);
					}
				}
			}
			
			M.clear();
		}
		
		printf("Case #%d: ",z);
		
		if(!dp[(1<<n)-1])
			printf("IMPOSSIBLE\n");
			
		else
		{
			for(int i=0; i<n; i++)
			{
				int t=S[(1<<n)-1][i]-'0';
				printf("%d ",t+1);
			}
			printf("\n");
		}
	}
	
    return 0;
}
