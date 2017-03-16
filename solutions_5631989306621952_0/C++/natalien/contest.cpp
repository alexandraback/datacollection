#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<stdio.h>

bool digits[10];

using namespace std;

int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A.out", "w", stdout);
	int T;
	bool ch;
	cin>>T;
	string a;
	string b;
	int bs;
	for(int t=1; t<=T; t++)
	{
		cin>>a;
		b=a[0];
		for (int i=1; i<a.size(); i++)
		{
			if(a[i]>=b[0]) b=a[i]+b;
			else b+=a[i];
		}
		cout<<"Case #"<<t<<": "<<b<<endl;
	}
	return 0;
}
