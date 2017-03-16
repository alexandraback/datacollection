#include <iostream>
#include <cstdio>
using namespace std;

int main() 
{
	int t,cas=0;
	double r,c,f,x,ans;
	cin>>t;
	while(t--)
	{
		cout<<"Case #"<<++cas<<": ";
		r=2;ans=0;
		cin>>c>>f>>x;
		while(1)
		{
			if((c/r + x/(r+f))<x/r)
			{
				ans+=c/r;
				r+=f;
			}
			else
			{
				ans+=x/r;
				break;
			}
		}
		printf("%.7lf",ans);
		cout<<endl;
	}
	return 0;
}