#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
	vector<long long int> ans;
	int t;
	cin>>t;
	while (t--)
	{
		string str;
		long long n;
		cin>>str>>n;
		vector<int> v(str.size(),0);
		for(int i = 0,j=0,l=0;i<str.size();i++)
		{
			if(str[i]!='a'&&str[i]!='e'&&str[i]!='i'&&str[i]!='o'&&str[i]!='u')
			{
				l++;
				if(l>=n)
				{
					v[i]=1;
				}
				//cout<<str[i]<<" "<<l<<endl;
			}
			else
			{
				l=0;
			}
		}
		long long int count = 0;
		long long start = 0;
		long long size = str.size();
		// for(int i = 0;i<str.size();i++)
		// {
		// 	if(v[i])
		// 	{
		// 		cout<<str[i]<<" ";
		// 	}
		// }
		// cout<<endl;
		for(int i = 0;i<str.size();i++)
		{
			if(v[i])
			{
				count += (long long)(i-n+2-start)*(size - i);
				start = i - n + 2;
			}
		}
		ans.push_back(count);
	}
	for(int i=0; i<ans.size();i++)
	{
		cout<<"Case #"<<i+1<<": "<<ans[i]<<endl;
	}
}