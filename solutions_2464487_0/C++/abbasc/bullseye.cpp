#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	freopen("bullseye.in","r",stdin);
	freopen("bullseye.txt","w",stdout);
	int T,x;
	cin>>T;
	for(x = 1; x <= T; x++)
	{
		int r, t,i,count = 0;
		cin>>r>>t;
		for(i = r; t > 0; i+=2)
		{
			t -= (2*i + 1);
			if(t >= 0)	count++;
		}
		cout<<"Case #"<<x<<": "<<count<<endl;
	}
	return 0;
}
