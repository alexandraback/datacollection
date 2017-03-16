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
#include <memory.h>
#include <cstring>
using namespace std;
int main()
{
	int te;
	cin>>te;
	for(int t=0;t<te;t++)
	{
		string s;
		cin>>s;
		string num;
		string den;
		for(int i=0;i<s.length();i++)
		{
			if(s[i]=='/')
			{
				num=s.substr(0,i);
				den=s.substr(i+1,s.length());
				break;
			}
		}
		long long n=0;
		long long d=0;
		for(int i=0;i<num.length();i++)
		n=n*10+(num[i]-'0');
		for(int i=0;i<den.length();i++)
		d=d*10+(den[i]-'0');

		long long g=__gcd(n,d);
		n=n/g;
		d=d/g;
		long long x=d;
		while(x%2==0)
		{
			x=x/2;
		}
		if(x!=1)
		{
			cout<<"Case #"<<t+1<<": impossible"<<endl;
			continue;
		}
		long long ans=0;
		while(d>n)
		{
			d=d/2;
			ans++;
		}
		cout<<"Case #"<<t+1<<": "<<ans<<endl;
	}
	return 0;	
}	