#include<fstream>
#include<iostream>
using namespace std;
#include<math.h>
int main()
{
	unsigned long long int t,k,e,r,n,max,i,gain,v;
	ifstream f("1.in");
	ofstream g("1.out");
	f>>t;
	for(k=1;k<=t;k++)
	{
		f>>e>>r>>n;
		f>>max;
		if(r>e)r=e;
		gain=max*r;
		for(i=1;i<n;i++)
		{
			f>>v;
			gain+=v*r;
			if(v>max)max=v;
		}
		gain+=max*(e-r);
		g<<"Case #"<<k<<": "<<gain<<endl;
	}
	return 0;
}
