#include <iostream>
using namespace std;

int main() {
	int te;
	cin>>te;
	for(int t=0;t<te;t++)
	{
		int n,m,k;
		cin>>n>>m>>k;
		if(k<=4)
		{
			cout<<"Case #"<<t+1<<": "<<k<<endl;
			continue;
		}
		if(n<3||m<3)
		{
			cout<<"Case #"<<t+1<<": "<<k<<endl;
			continue;
		}
		if(k>n*m-4)
		{
			k=k-(n*m-4);
			cout<<"Case #"<<t+1<<": "<<2*(n+m)-8+k<<endl;
			continue;
		}
		
		int ans=n*m;
		for(int i=3;i<=n;i++)
		for(int j=3;j<=m;j++)
		{
			if(k<=(i*j-4))
			ans=min(ans,2*(i+j)-8);
			if(k==(i*j-4)+1)
			ans=min(ans,2*(i+j)-8+1);
		}
		cout<<"Case #"<<t+1<<": "<<ans<<endl;
	}
	return 0;
}