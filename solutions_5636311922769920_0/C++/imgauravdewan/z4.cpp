#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main()
{
	int t;
	cin>>t;
	
	for(int kase=1;kase<=t;kase++)
	{
		int k,c,s;
		cin>>k>>c>>s;
		int req = k/c;
		if(k%c) req++;
		cout<<"Case #"<<kase<<":";
		if(s<req)
			cout<<" IMPOSSIBLE";
		else
		{
			int r =0;
			for(int i=0;i<req;i++)
			{
				ll num = 0;
				for(int j=0;j<c;j++)
				{
					r++;
					if(r>=k) r = 0;
					num = num*k + r;
				}
				cout<<" "<<num+1;
			}
		}
		
		
		cout<<"\n";
	}
	return 0;
}
