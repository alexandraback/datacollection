#include <iostream>
#include <cstdio>

int r,w,c,t;
using namespace std;

int main()
{
	freopen("inp.in","r",stdin);
	freopen("outpux.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int total=0;
		cin>>r>>c>>w;
		if(w==1)
			total=r*c;
		if(w==c)
			total=(r-1)+c;
		else
		{
			total=r*((c/w));
			if(c%w!=0)
				total=total+w;
			else
				total=total+w-1;
		}
		cout<<"Case #"<<i<<": "<<total<<endl;
	}
}