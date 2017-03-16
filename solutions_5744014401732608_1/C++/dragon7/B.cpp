#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
int a[100][100];
int main()
{
	int test;
	cin>>test;
	for(int z=1;z<=test;z++)
	{
		int b;
		cin>>b;
		ll x;
		cin>>x;
		ll f = 1;
		for(int i=1;i<b-1;i++)
			f=f+f;
		if(x>f)
		{
			cout<<"Case #"<<z<<": IMPOSSIBLE"<<endl;
			continue;
		}	
		cout<<"Case #"<<z<<": POSSIBLE"<<endl;
		for(int i=1;i<b;i++)
		{
			for(int j=i+1;j<=b;j++)
				a[i][j]=1;
		}
		f = f-x;
		for(int i=2;i<b;i++)
		{
			ll x = 1;
			for(int j=1;j<i-1;j++)
				x = x+x;
			if(x&f)
				a[i][b]=0;
		}
		for(int i=1;i<=b;i++)
		{
			for(int j=1;j<=b;j++)
				cout<<a[i][j];
			cout<<endl;
		}
	}
}
