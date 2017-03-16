#include<iostream>
using namespace std;
void solve()
{
	long long a,b,k,o=0,i,j;
	cin>>a>>b>>k;
	for(i=0;i<a;i++)
		for(j=0;j<b;j++)
			if((i&j)<k)o++;
	cout<<o<<endl;
}
int main()
{
	int t,i;
	cin>>t;
	for(i=1;i<=t;i++)
	{
		cout<<"Case #"<<i<<": ";
		solve();
	}
}
