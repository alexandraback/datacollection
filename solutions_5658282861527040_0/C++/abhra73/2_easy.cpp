#include <iostream>
using namespace std;

int main() 
{
	int t,a,b,k,ans,cas=0;
	cin>>t;
	while(t--)
	{
		cout<<"Case #"<<++cas<<": ";
		ans=0;
		cin>>a>>b>>k;
		for(int i=0;i<a;i++)
		{
			for(int j=0;j<b;j++)
			{
//				cout<<(i&j)<<" ";
				if((i&j)<k)
					ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}