#include <iostream>
#include<stdio.h>
using namespace std;
int main() 
{
	int t,a,b,n,maxi;
	cin >> t;
	for (int p = 1;p <= t; p++)
	{
		cin>>a>>b>>n;
		if(b!=n)
			maxi=max(b-(n-1),n+1);
		else
			maxi=n;
		cout<<"Case #"<<p<<": "<<(a*(b-1))/n+n<<endl;
	}
}
