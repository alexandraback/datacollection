#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
int main()
{unsigned long long int a,r,t,cal,m,i,te;
double r1,d;
cin>>te;
for(m=0;m<te;m++)
	{cin>>r;
	cin>>t;
	r1=2*r-1;
		
	d=pow(r1,2);
	
	d=d+(8*t);
	//cout<<d<<endl;	
	d=pow(d,0.5);
	//cout<<d<<endl;
	d=(d-r1)/4;
	cal = int(d);
	//cout<<d<<endl;	
	cout<<"Case #"<<m+1<<": "<<cal<<endl; 
	}
}
