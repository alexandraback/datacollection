#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("input.txt","r",stdin);
	freopen("op.txt","w",stdout);
	int t,c=1;
	cin>>t;
	while(c<=t)
	{
		int a[3001];
		for(int i=0;i<=3000;i++)
		{
			a[i]=0;
		}
		int n,m;
		cin>>n;
		int k=(n<<1)-1;
		for(int i=0;i<k;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>m;
				a[m]++;
			}
		}
		cout<<"Case #"<<c<<": ";
		for(int i=0;i<=3000;i++)
		{
			if(a[i]%2==1)
			{
				cout<<i<<" ";
			}
		
		}
		cout<<endl;
		c++;
	}
	
}
