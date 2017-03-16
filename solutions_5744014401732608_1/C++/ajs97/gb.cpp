#include <bits/stdc++.h>
using namespace std;
#define ll long long
int e[55][55];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string pos="POSSIBLE";
	string ipos="IMPOSSIBLE";
	int t;
	cin>>t;
	for(int i1=1;i1<=t;i1++)
	{
		ll n,m;
		cin>>n>>m;
		memset(e,0,sizeof(e));
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		{
			if(i==n)continue;
			if(i==1)continue;
			e[i][j]=1;
		}	
		int mx=(1LL<<(n-2LL));
		if(m>mx)
		{
			cout<<"Case #"<<i1<<": "<<ipos<<endl;
			continue;
		}
		cout<<"Case #"<<i1<<": "<<pos<<endl;
		e[1][n]=1;
		m--;
		for(ll i=0;(1LL<<i)<=m;i++)
		{
			if(m&(1LL<<i))
			{
				e[1][n-1-i]=1;
				continue;
			}
		}
		for(int i=1;i<=n;i++)
		{
		for(int j=1;j<=n;j++)	
			cout<<e[i][j];
		cout<<endl;
		}
	}

	return 0;
}