#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t,u;
	cin>>t;
	u=t;
	while(t--)
	{
		double c,f,x,ans=0.0,r=2.0;
		cin>>c>>f>>x;
		while(1)
		{
			if((x/r)<(c/r)+(x/(r+f)))
			{
				ans=ans+(x/r);
				break;
			}
			ans=ans+(c/r);
			r=r+f;
		}
		cout<<"Case #"<<u-t<<": ";
		printf("%.7lf\n",ans);
	}
	return 0;
}