#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define MTIME 50000
int main()
{
//	freopen("g-b.txt","r",stdin);
	freopen("B-small-attempt0.in","r",stdin);
	freopen("b-ans.txt","w",stdout);
	int tt;
	double cc,ff,xx,rate,ans;
	cin>>tt;
	for (int ci=1;ci<=tt;ci++)
	{
		double temptime=0,temptotal;
		cin>>cc>>ff>>xx;
		rate=2.0;
		ans=xx/rate;
		while (true)
		{
			temptime+=cc/rate;
			rate+=ff;
			if ((temptotal=xx/rate+temptime)<ans)
				ans=temptotal;
			else
				break;
		}
		cout<<"Case #"<<ci<<": ";
		printf("%.7lf\n",ans);
	}
	return 0;
}
