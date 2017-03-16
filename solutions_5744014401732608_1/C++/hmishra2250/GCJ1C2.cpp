#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	for(int tt=1;tt<=t;tt++)
	{
		cout<<"Case #"<<tt<<": ";
		long long b,ans;
		long long m;
		cin>>b>>m;
		if(m>(1ll<<(b-2)))cout<<"IMPOSSIBLE\n";
		else
		{
			cout<<"POSSIBLE\n";
			int v[b+1][b+1];
			for(int i=1;i<=b;i++)
				for(int j=1;j<=b;j++)v[i][j]=0;
			for(int i=1;i<b;i++)
				for(int j=i+1;j<=b;j++)v[i][j]=1;
			ans = (1ll<<b)-m;
			int c = b-1;
			while(ans)
			{
				if(ans&1)
				{
					v[1][c]=0;
				}
				c--;
				ans>>=1;
			}
			for(int i=1;i<=b;i++)
				
				{
					for(int j=1;j<=b;j++)cout<<v[i][j];
					cout<<'\n';
				}
			
		}
		
	}
}
