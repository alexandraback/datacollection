#include<iostream>
#include<string>
#include<fstream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
ifstream in("a.in");
ofstream out("a.out");
#define fo(i,j,k) for (i=j; i<=k; i++)

int main()
{
	int T;
	long long t , i, j, n ,r, x ,y;
	in>>T;
	fo(i, 1, T)
	{
		in>>r>>t;
		y=t/r;
		x=1;
		while (x<y)
		{
			long long mid=(x+y+1)/2;
			if (t-2*r*mid>0)
				if ((t-2*r*mid)/(mid)>=2*mid-1)
					x=mid;
				else
					y=mid-1;
			else
				y=mid-1;
		}
		out<<"Case #"<<i<<": "<<x<<endl; 
	}

}