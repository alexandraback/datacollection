# include <stdio.h>
# include <string.h>
# include <string>
# include <iostream>
# include <cmath>
using namespace std;
typedef long long ll;
string s;
int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("out.txt","w",stdout);
	int t,p,i,dx,dy;
	scanf("%d",&t);
	for (p=1;p<=t;++p)
	{
		s.clear();
		scanf("%d%d",&dx,&dy);
		for (i=0;i<abs(dx);++i)
		{
			if (dx>0)
				s += "WE";
			else
				s += "EW";
		}
		for (i=0;i<abs(dy);++i)
		{
			if (dy>0)
				s += "SN";
			else
				s += "NS";	
		}
		cout<<"Case #"<<p<<": "<<s<<endl;
	}
	return 0;
}