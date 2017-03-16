#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
	cout<<"Case #1:\n";
	int j=500;
	for(int i=(1<<15)+1;j;i+=2,--j)
	{
		string s;
		int t = i;
		while(t)
		{
			s+=t%2+'0';
			t>>=1;
		}
		reverse(s.begin(),s.end());
		cout<<s<<s;
		for(int b=2;b<=10;++b)
		{
			long long  u=0;
			for(int l = 0;s[l];++l)
			{
				u = u*b+(s[l]=='1');
			}
			cout<<" "<<u;
		}
		endl(cout);
	}
}
