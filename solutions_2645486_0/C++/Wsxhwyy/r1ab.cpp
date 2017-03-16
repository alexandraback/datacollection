#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");
#define cin fin
#define cout fout

int T,E,R,N;
int dp[20][20];
int v[20];

int main()
{
	cin>>T;
	for(int xx=1;xx<=T;xx++){
		cin>>E>>R>>N;
		for(int i=1;i<=N;i++) cin>>v[i];
		memset(dp,0,sizeof dp);
		for(int i=1;i<=N;i++){
			for(int j=0;j<=E;j++){
				for(int k=0;k<=j;k++){
					int rec=j-k+R;
					if(rec>E) rec=E;
					dp[i][rec]=max(dp[i][rec],dp[i-1][j]+v[i]*k);
				}
			}
		}
		int ans=0;
		for(int i=0;i<=E;i++) ans=max(ans,dp[N][i]);
		cout<<"Case #"<<xx<<": "<<ans<<endl;
	}
}