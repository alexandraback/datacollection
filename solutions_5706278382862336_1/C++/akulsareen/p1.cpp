#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
using namespace std;
long long int gcd(long long int a,long long int b)
{
	if(a==0)
		return b;
	else
		return gcd(b%a,a);
}
int main()
{
	freopen("al.in","r",stdin);
	freopen("a_large.out","w",stdout);
	int t;
	cin>>t;
	for (int test_case = 1; test_case <= t; ++test_case)
	{
		long long int a=0,b=0,fact;
		string x;
		cin>>x;
		bool flag=false;
		for (int i = 0; i < x.length(); ++i)
		{
			if(flag)
			{
				b=(b*10)+(x[i]-'0');
			}
			else
			{
				if(x[i]=='/')
					flag=true;
				else
					a=(a*10)+(x[i]-'0');
			}
		}
		//cout<<a<<" "<<b<<"\n";
		fact=gcd(a,b);
		a/=fact;
		b/=fact;
		if(b&(b-1))
			fact=1000000;
		else
		{
			fact=1;
			while(a<(b/2))
			{
				a*=2;
				fact++;
			}
		}
		if(fact>40)
			cout<<"Case #"<<test_case<<": impossible\n";
		else
			cout<<"Case #"<<test_case<<": "<<fact<<"\n";
	}
	return 0;
}