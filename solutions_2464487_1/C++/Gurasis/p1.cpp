#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
int main()
{unsigned long long int a,r,t,cal,m,i,te;
double r1,d,d1;
cin>>te;
for(m=0;m<te;m++)
	{cin>>r;
	cin>>t;
	r1=2*r-1;
		
	d1=pow(r1,2);
	
	d=1+(8*t)/d1;
	
	d=pow(d,0.5);
	
	d=((d*r1)-r1)/4;
	cal = int(d);
	
	cout<<"Case #"<<m+1<<": "<<cal<<endl; 
	}
}
