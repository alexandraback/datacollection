#include <iostream>
using namespace std;

int main()
{
	int t,i,j,k;
	cin>>t;
	for(k=1;k<=t;k++)
	{
		int r,c,w;
		cin>>r>>c>>w;
		int ans = w + (c/w)*r;
		if(c%w==0) ans--;
		cout<<"Case #"<<k<<": "<<ans<<endl;
	}
	return 0;
}
