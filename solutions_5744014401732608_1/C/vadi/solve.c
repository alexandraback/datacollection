#include <bits/stdc++.h>
using namespace std;
int adj[60][60]={};
		long long n,k;

int solve(int a){
	if(a==n)
		return 1;
	int ans=0;
	for(int i=a+1;i<=n;i++)
		if(adj[a][i]==1)
			ans+=solve(i);
	return ans;
}
int main() {
	int t;
	cin>>t;
	for(int tt=1;tt<=t;tt++)
	{
		cout<<"Case #"<<tt<<": ";
		cin>>n>>k;
		int f=0;
		if(k<=pow(2,n-2))
			cout<<"POSSIBLE\n";
		else
		{
			cout<<"IMPOSSIBLE\n";
			continue;
		}
		int cp=log2(k);
		if(pow(2,cp)<k)
			cp++;
		cp+=2;
	//	cout<<cp<<" "; 
		memset(adj,0,sizeof adj);
		for(int i=1;i<=cp;i++)
			for(int j=i+1;j<=cp;j++)
			{
				if(i==cp)	
					adj[n][j]=1;
				else if(j==cp)
					adj[i][n]=1;
				else	
					adj[i][j]=1;
			}
		int diff=pow(2,cp-2)-k;
	//	cout<<diff<<" ";
		
		int h=cp-1;
		while(diff)
		{
			if(diff%2)
				adj[1][h]=0;
			h--;
			diff/=2;
		}
		
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
				cout<<adj[i][j];
			cout<<endl;
		}
				
		
		
	}
	
	return 0;
}
