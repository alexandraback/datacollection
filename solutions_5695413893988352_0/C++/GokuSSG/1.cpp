#include<bits/stdc++.h>
using namespace std;
 
int main() {
	int t;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>t;
	for(int  i= 1; i <= t; i++)
	{
 
		string s1,s2;
		string a1 = "";
		string a2 = "";
		cin>>s1>>s2;
		for(int j = 0; j < s1.length(); j++)
		{
			if(s1[j] == '?' && s2[j] == '?')
			{
				a1 += "0";
				a2 += "0";
			}
			else if(s1[j] == '?')
			{
				a1 += s2[j];
				a2 += s2[j];
			}
			else if(s2[j] == '?')
			{
				a1 += s1[j];
				a2 += s1[j];
			}
			else if(s1[j] == s2[j])
			{
				a1 += s1[j];
				a2 += s1[j];
			}
			else if(s1[j] < s2[j])
			{
				a1 += s1[j];
				a2 += s2[j];
				j++;
				for(;j < s1.length(); j++)
				{
					if(s1[j] == '?')
						a1 += '9';
					else 
						a1 += s1[j];
 
					if(s2[j] == '?')
						a2 += '0';
					else 
						a2 += s2[j];
				}
			}
			else if(s2[j] < s1[j])
			{
				a1 += s1[j];
				a2 += s2[j];
				j++;
				for(;j < s1.length(); j++)
				{
					if(s1[j] == '?')
						a1 += '0';
					else 
						a1 += s1[j];
 
					if(s2[j] == '?')
						a2 += '9';
					else 
						a2 += s2[j];
				}
			}
 
		}
		cout<<"Case #"<<i<<": "<<a1<<" "<<a2<<endl;
	}
 
	return 0;
}