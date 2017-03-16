#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int arr[100]={0};
		int c,d,v,ans=0;
		cin>>c>>d>>v;
		for(int j=0;j<d;j++)
		{
			int val;
			cin>>val;
			arr[val]=1;
		}
		for(int j=1;j<=v;j*=2)
		{
			if(arr[j]==0)
				ans++;
		}
		cout<<"Case #"<<i<<": "<<ans<<endl;
	}
	return 0;
}
