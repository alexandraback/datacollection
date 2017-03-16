#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <cmath>

using namespace std;

const char in_name[]="B-small-attempt1(1).in";
const char out_name[]="out.txt";

ifstream c_in(in_name);
ofstream c_out(out_name);

int main()
{
	int n;
	double D;
	vector<double> x,t;
	int A;
	vector<double> a;

	int te;
	c_in>>te;
	c_out.setf(ios::fixed, ios::floatfield);
	c_out.precision(10);

	for(int test=1;test<=te;test++)
	{
	
		c_in>>D>>n>>A;
		x.assign(n,0);
		t.assign(n,0);
		a.assign(A,0);
		for(int i=0;i<n;i++)
		{
			c_in>>t[i]>>x[i];
		}
		for(int i=0;i<A;i++)
		{
			c_in>>a[i];
		}

		c_out<<"Case #"<<test<<": \n";
		for(int i=0;i<A;i++)
		{
			if(n==1)
			{
				c_out<<sqrt(2*D/a[i])<<endl;
			}
			else
			{
				if(x[0]>=D)
				{
					c_out<<sqrt(2*D/a[i])<<endl;
				}
				else
				{
					double time=(D-x[0])/(x[1]-x[0])*t[1];
					double res=max(sqrt(2*D/a[i]),time);
					c_out<<res<<endl;
				}
			}
		}
	}

	return 0;
}