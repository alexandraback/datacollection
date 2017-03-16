
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(i=a;i<b;i++)
#define vi vector<int>

int main()
{
	ios_base::sync_with_stdio(0);
	int t;
	cin>>t;
	int i,j,k;
	FOR(i,1,t+1)
	{
		double ans=0;
		double c,f,x;
		cin>>c>>f>>x;
		double r = 2;
		while(true)
		{
			double t1 = x/r;
			double t2 = c/r + x/(r+f);
			//~ cout<<t1<<" "<<t2<<endl;
			//~ cout<<t1<<" "<<t2<<endl;
			if(t1<=t2)
			{
				ans+=t1;
				break;
			}
			else
			{
				ans+=c/r;
				r+=f;
			}
		}
		cout<<"Case #"<<i<<": "<<setprecision(20)<<ans<<endl;
		
	}
				
	return 0;
}
	
