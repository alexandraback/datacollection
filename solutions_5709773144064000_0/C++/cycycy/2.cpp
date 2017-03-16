#include<iostream>
#include<iomanip>
#include<fstream>
#include<vector>
#include<map>
#include<string>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int t;
	cin>>t;
	for (int ii=0;ii<t;ii++)
	{
		cout<<"Case #"<<ii+1<<": ";
		double c,f,x;
		cin>>c>>f>>x;
		double ans=x/2;
		double now=2;
		while ((x-c)/now>x/(now+f))
		{
			ans-=(x-c)/now-x/(now+f);
			now+=f;
		}
		printf("%.7f\n",ans);
	}
}