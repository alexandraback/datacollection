#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int n;
		cin>>n;
		string s1[n],s2[n];
		map<string,int> right,wrong;
		for(int j=0;j<n;j++)
		{
			cin>>s1[j]>>s2[j];
			if(right.find(s1[j])!=right.end())
			{
				map<string,int>::iterator it=right.find(s1[j]);
				it->second++;
			}
			else
				right.insert(pair<string,int>(s1[j],1));
			if(wrong.find(s2[j])!=wrong.end())
			{
				map<string,int>::iterator it=wrong.find(s2[j]);
				it->second++;
			}
			else
				wrong.insert(pair<string,int>(s2[j],1));
		}
		int ans=0;
		for(int j=0;j<n;j++)
		{
			map<string,int>::iterator it=right.find(s1[j]);
			map<string,int>::iterator it1=wrong.find(s2[j]);
			if(it->second>1 && it1->second>1)
				ans++;
		}
		cout<<"Case #"<<i<<": "<<ans<<endl;
	}
	return 0;
}
