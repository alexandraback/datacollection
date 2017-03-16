#include <iostream>
#include <cstring>
using namespace std;
int dp[21][2000000];
int num[21];
int main()
{
	int t;
	cin>>t;
	for(int x=1;x<=t;x++){
		memset(dp,-1,sizeof dp);
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>num[i];
		}
		cout<<"Case #"<<x<<":\n";
		dp[0][0]=0;
		for(int i=1;i<n;i++){
			for(int j=0;j<=2000000;j++){
				if(dp[i-1][j]>=0) dp[i][j]=0;
				if(j>=num[i] && dp[i-1][j-num[i]]>=0){
					if(dp[i][j]>=0){
						dp[i][j]=num[i];
						int k=i-1,l=j;
						while(k){
							if(dp[k][l]) cout<<dp[k][l]<<' ',l-=dp[k][l];
							k--;
						}
						cout<<endl;
						k=i,l=j;
						while(k){
							if(dp[k][l]) cout<<dp[k][l]<<' ',l-=dp[k][l];
							k--;
						}
						cout<<endl;
						goto label;
					}else dp[i][j]=num[i];
				}
			}
		}
		cout<<"Impossible"<<endl;
		label:continue;
	}
	
}