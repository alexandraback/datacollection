#include <iostream>
using namespace std;
int process(double r,double t)
{
	int count=0;
	while(1)
	{
		double req=((r+1)*(r+1))-(r*r);
		if(t<req)
		break;
		else
		{
			t-=req;
			count++;
			r+=2;
		}
	}
	return count;
}
int main()
{
	int n;
	cin>>n;
	for (int i=0;i<n;i++)
	{
		double r;
		double t;
		cin>>r>>t;
		cout<<"Case #"<<i+1<<": "<<process(r,t)<<endl;
	}
}
