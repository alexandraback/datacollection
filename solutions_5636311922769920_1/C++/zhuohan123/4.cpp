#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
typedef long long LL;
/*
string str;
string expand(string s)
{
	string ans,allG(str.length(),'G');
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='L')ans+=str;
		else ans+=allG;
	}
	return ans;
}
string chgchar(string s)
{
	for(int i=0;i<s.length();i++)
		if(s[i]=='G')s[i]='G';
		else s[i]='L';
	return s;
}*/
int main()
{
	freopen("4.in","r",stdin);
	freopen("4.out","w",stdout);
	/*
	int k,c;cin>>k>>c;
	for(int opt=(1<<k)-1;opt>=0;opt--)
	{
		int gnum=0;
		str="";
		for(int i=0;i<k;i++)
		{
			if(opt&(1<<i))str+="L";
			else str+="G",gnum++;
		}
		string tstr=str;
		for(int i=1;i<c;i++)tstr=expand(tstr);
		if(gnum==1)cout<<chgchar(str)<<" "<<chgchar(tstr)<<endl;
	}
	*/
	int T;cin>>T;
	for(int ti=1;ti<=T;ti++)
	{
		cout<<"Case #"<<ti<<": ";
		int k,c,s;cin>>k>>c>>s;
		if((k-1)/c+1>s)cout<<"IMPOSSIBLE"<<endl;
		else
		{
			LL ans=0;int tc=0;
			for(int i=0;i<k;i++)
			{
				if(tc==c)
				{
					cout<<ans+1<<" ";
					ans=0;tc=0;
				}
				ans=ans*k+i;tc++;
			}
			cout<<ans+1<<endl;
		}
	}
	return 0;
}
