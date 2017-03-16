#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
int main()
{
	int t;
	string s;
	cin>>t;
	for(int k = 1;k<=t;k++)
	{
		vector<char> v;
		cin>>s;
		v.push_back(s[0]);
		for(int i=1;i<s.length();i++)
		{
			if(s[i]>=v[0])
				v.insert(v.begin(),s[i]);
			else v.insert(v.end(),s[i]);
		}
		cout<<"Case #"<<k<<": ";
		for(int i=0;i<v.size();i++)
		{
			cout<<v[i];
		}
		cout<<endl;
	}
  return 0;
}
