#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
	int c,t,i,j;
	cin>>t;
	int a,b;
	double p[100000],q[100000];
	double min,f;
	for(c=0;c<t;c++)
	{
		cin>>a>>b;
		cin>>p[0];
		q[0]=p[0];
		for(i=1;i<a;i++)
		{
			cin>>p[i];
			q[i]=q[i-1]*p[i];
		}
		min = b+2;
		for(i=0;i<a;i++)
		{
			f=i+b-a+i+1+(1-q[a-i-1])*(b+1);
			if(f<min)
				min=f;
		}
		cout<<"Case #"<<c+1<<": ";
		printf("%.6lf\n",min);
	}
}
