#include<bits/stdc++.h>
using namespace std;



int two[3][11][11];
int dp[11][11][11];
vector<pair<int,pair<int,int> > >vec;
int main()
{
	
	ifstream cin("1C3S.in");
	ofstream cout("1C3SA.txt");
	int i,j,k,l,m,n,ind=1,t,J,S,P,K,prev,prev1,m1;
	long long int ans;
	cin>>t;
	while(t--)
	{
		cin>>J>>P>>S>>K;
		ans=0LL;
		prev=prev1=0;
		vec.clear();
		memset(two,0,sizeof(two));
		memset(dp,0,sizeof(dp));
		for(i=1;i<=J;i++)
		{
			
			for(j=1;j<=P;j++)
			{
				
				k=prev%S;	
				for(m=1;m<=S;m++)
				{
					n=(k+m);
					if(n>S)
					n%=S;
					if(two[0][i][j]>=K)
					break;
					if(two[1][i][n]>=K)	
						continue;
					if(two[2][j][n]>=K)
						continue;
					ans++;
					two[0][i][j]++;
					two[1][i][n]++;
					two[2][j][n]++;	
					vec.push_back(make_pair(i,make_pair(j,n)));
					prev=n;
					
				}
			}
		}
		
			cout<<"Case #"<<ind++<<": "<<ans<<endl;
			for(i=0;i<ans;i++)
			cout<<vec[i].first<<" "<<vec[i].second.first<<" "<<vec[i].second.second<<endl;
	}
}
