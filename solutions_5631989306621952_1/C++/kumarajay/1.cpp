#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

int main()
{
	int t;
	cin >>t;
	
	string s;
	
	for(int i=1;i<=t;i++)
	{
		cin >>s;
		string ss="";
		ss+=s[0];
		for(int j=1;j<s.length();j++)
		{
			//cout << s[j]<<"--"<<ss[0]<<endl;
			if(s[j]>=ss[0])
				ss=s[j]+ss;
			else
				ss=ss+s[j];
		}	
		cout<<"Case #"<<i<<": "<<ss<<endl;
		
		
	}
}
