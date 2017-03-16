#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<math.h>
#include<sstream>

using namespace std;

int main()
{
	int T;
	cin>>T;
	long long r,t,F;
	double D,A,X,fn,d,b;
	int f,a;
	for(int c=1;c<=T;c++)
	{
		cin>>r>>t;
		if(r<1e8)
		{
			D=sqrt((2*r-1)*(2*r-1)+8*t);
			F=D-(2*r-1);
			F/=4;
		}
		else if(sqrt(8*t)<(2*r-1))
		{
			D=0;
			b=1/2.0;
			d=1/2.0;
			f=1;
			a=1;
			X=8.0*t/(2*r-1);
			X/=(2*r-1);
			A=X;
			fn=(A*d)/f;
			fn*=(2*r-1);
			//while((fn>0.1||(fn)<(-0.1))&&a<15)
			while(a<10)
			{
				D+=fn;
				a++;
				f*=a;
				b--;
				d*=b;
				A*=X;
				fn=(A*d)/f;
				fn*=(2*r-1);
			}
			F=D/4;
		}
		else
		{
			D=sqrt(8.0*t)-(2*r-1);
			b=1/2.0;
			d=1/2.0;
			f=1;
			a=1;
			X=(2*r-1)/(8.0*t);
			X*=(2*r-1);
			A=X;
			fn=(A*d)/f;
			fn*=(2*r-1);
			//while((fn>0.1||(fn)<(-0.1))&&a<15)
			while(a<10)
			{
				D+=fn;
				a++;
				f*=a;
				b--;
				d*=b;
				A*=X;
				fn=(A*d)/f;
				fn*=sqrt(8.0*t);
			}
			F=D/4;

		}
//		cout<<D<<endl;
		cout<<"Case #"<<c<<": "<<F<<endl;
	}
	return 0;
}
