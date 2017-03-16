// Author : dstorm
// Problem B : Cookie Clicker Alpha
// Compiler : Mingw (G++)
#include<iostream>
#include<cmath>
#include<algorithm>
#include<iomanip>
#define eps 0.000001
using namespace std;
/*double round7(long double x)
{	return (roundl(x*10000000.0)/10000000.0);
}*/
int main()
{	int t,i;
	long double c,f,x,cps,t1,t2,time;
	cin>>t;
	for(i=1;i<=t;i++)
	{	cin>>c>>f>>x;
		time=0.0;
		cps=2.0;
		while(1)
		{	t1 = x/cps;
			t2 = c/cps + x/(cps+f);	
			if( t2 > t1 )
			{	//cout<<fixed<<setprecision(9)<<round7(t1)<<" ";
				//time+=round7(t1);
				time+=t1;
				break;
			}
			else
			{	//cout<<fixed<<setprecision(9)<<round7(c/cps)<<endl;
				//time+=round7(c/cps);
				time+=c/cps;
				cps+=f;
			}
		}
		cout<<"Case #"<<i<<": ";
		cout<<fixed;
		cout<<setprecision(7)<<time<<endl;
	}
	return 0;
}