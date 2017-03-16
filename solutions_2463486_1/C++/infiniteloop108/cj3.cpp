#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<long long> fns;
bool ispalin(long long n)
{
	long long rev=0;
	long long t=n;
	while(t)
	{
		rev*=10;
		rev+=t%10;
		t/=10;
	}
	return rev==n;
}
void calc(long long n)
{
	for(long long i=1;i<n;++i)
	{
		if(ispalin(i)&&ispalin(i*i))fns.push_back(i*i);		
	}
}
int main()
{
	calc(10000001);
	int t;
	cin>>t;
	for(int i=1;i<=t;++i)
	{
		long long a,b;
		cin>>a>>b;
		vector<long long>::iterator lb=lower_bound(fns.begin(),fns.end(),a);
		vector<long long>::iterator ub=upper_bound(fns.begin(),fns.end(),b);
		cout<<"Case #"<<i<<": "<<ub-lb<<endl;
	}
	return 0;
}