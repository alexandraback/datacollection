#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>v;
int main()
{
	string a;
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int m[100]={0};
		v.clear();
		cin>>a;
		for(int j=0;j<a.length();j++)
		{
			m[a[j]-'A']++;
		}
		while(m['X'-'A'])
		{
			v.push_back(6);
			m['X'-'A']--;
			m['I'-'A']--;
			m['S'-'A']--;
		}
		while(m['G'-'A'])
		{
			v.push_back(8);
			m['E'-'A']--;
			m['I'-'A']--;
			m['G'-'A']--;
			m['H'-'A']--;
			m['T'-'A']--;
		}
		while(m['Z'-'A'])
		{
			v.push_back(0);
			m['Z'-'A']--;
			m['E'-'A']--;
			m['R'-'A']--;
			m['O'-'A']--;
		}
		while(m['W'-'A'])
		{
			v.push_back(2);
			m['T'-'A']--;
			m['W'-'A']--;
			m['O'-'A']--;
		}
		while(m['U'-'A'])
		{
			v.push_back(4);
			m['F'-'A']--;
			m['O'-'A']--;
			m['U'-'A']--;
			m['R'-'A']--;
		}
		while(m['F'-'A'])
		{
			v.push_back(5);
			m['F'-'A']--;
			m['I'-'A']--;
			m['V'-'A']--;
			m['E'-'A']--;
		}
		while(m['V'-'A'])
		{
			v.push_back(7);
			m['S'-'A']--;
			m['E'-'A']--;
			m['V'-'A']--;
			m['E'-'A']--;
			m['N'-'A']--;
		}
		while(m['O'-'A'])
		{
			v.push_back(1);
			m['O'-'A']--;
			m['N'-'A']--;
			m['E'-'A']--;
		}
		while(m['I'-'A'])
		{
			v.push_back(9);
			m['N'-'A']--;
			m['I'-'A']--;
			m['N'-'A']--;
			m['E'-'A']--;
		}
		while(m['R'-'A'])
		{
			v.push_back(3);
			m['T'-'A']--;
			m['H'-'A']--;
			m['R'-'A']--;
			m['E'-'A']--;
			m['E'-'A']--;
		}
		sort(v.begin(),v.end());
		cout<<"Case #"<<i<<":"<<" ";
		for(int j=0;j<v.size();j++)
			cout<<v[j];
		cout<<endl;

	}
}