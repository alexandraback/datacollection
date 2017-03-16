/*
 * main.cpp
 *
 *  Created on: 12.05.2013
 *      Author: grand
 */

#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

bool soglas(char x)
{
	if(
		 (x=='a') ||
		 (x=='e') ||
		 (x=='i') ||
		 (x=='o') ||
		 (x=='u')
	)
		return false;
	else
		return true;
}

void makeA(vector<int> & a, string & s, int n)
{
	vector<int> b(s.length());
	for(int i=0; i<s.length(); ++i)
	{
		b[i] = soglas(s[i]);
	}
	for(int i=s.length()-2; i>=0; --i)
	{
		if(b[i] && b[i+1])
			b[i]+=b[i+1];
	}
	for(int i=0; i<b.size(); ++i)
		if(b[i]>=n)a.push_back(i);
}

long long solve()
{
	string s; int n;
	cin>>s>>n;
	long long result = 0;

	vector<int> a;
	a.reserve(s.length());

	if(n==0)
		return (1LL*s.length()*(1LL*s.length()+1)/2 + 1LL);

	makeA(a, s, n);

	--n;

	if(!a.size())
		return 0;
	else
	{
		for(int i=0; i<a.size(); ++i)
		{
			int prev = i?(a[i-1]+1):0;
			int r = a[i] + n;
//			cout<<"--> i:"<<i<<" ai:"<<a[i]<<" prev:"<<prev<<" r:"<<r<<"  ";
			result += ((a[i]-prev+1LL)*(s.length()-r));
//			cout<<result<<endl;
		}
	}

	return result;
}

int main()
{
	int T; cin>>T;
	for(int t=1; t<=T; ++t)
	{
		cout<<"Case #"<<t<<": "<<solve()<<endl;
	}

	return 0;
}
