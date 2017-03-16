#include<bits/stdc++.h>

using namespace std;

bool check(int val,string s)
{
	for(int i=s.length()-1;i>=0;i--)
	{
		if(s[i]!='?' && s[i]!=('0'+(val%10))) 
			return false;
		val/=10;
	}
	return true;
}

string valtostring(int val,int range)
{
	string ans="";
	while(val>0)
	{
		ans+='0'+(val%10);
		val/=10;
		range/=10;
	}
	while(range>1)
	{
		ans+='0';
		range/=10;
	}
	for(int i=0;i<(ans.length()/2);i++)
	{
		char c=ans[i];
		ans[i]=ans[ans.length()-1-i];
		ans[ans.length()-1-i]=c;
	}
	return ans;
}

int main()
{
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		string s1,s2;
		cin>>s1>>s2;
		int diff=10000000,p,q;
		int range=(int)pow(10,s1.length());
		for(int j=0;j<range;j++)
		{
			for(int k=0;k<range;k++)
			{
				if(check(j,s1) && check(k,s2))
				{
					if(diff>(int)abs(j-k))
					{
						diff=(int)abs(j-k);
						p=j;
						q=k;
					}
				}
			}
		}
		s1=valtostring(p,range);
		s2=valtostring(q,range);
		cout<<"Case #"<<i<<": "<<s1<<" "<<s2<<endl;
	}
	return 0;
}
