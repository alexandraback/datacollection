#include <iostream>
using namespace std;
int main()
{
	int t,k1;
	cin>>t;
	k1=t;
	while(t--)
	{
		int a,b,k,count=0,i,j;
		cin>>a>>b>>k;
		for(i=0;i<a;i++)
		for(j=0;j<b;j++)
		if((i&j)<k)count++;
		cout<<"Case #"<<k1-t<<": "<<count<<endl;
	}
	return 0;
}

