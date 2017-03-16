#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int arr[26]={0};
		string ans="",in;
		cin>>in;
		for(int j=0;j<in.length();j++) arr[in[j]-'A']++;
		int count=arr['W'-'A'];
		for(int j=0;j<count;j++) ans+='2';
		arr['T'-'A']-=count;
		arr['W'-'A']-=count;
		arr['O'-'A']-=count;
		count=arr['Z'-'A'];
		for(int j=0;j<count;j++) ans+='0';
		arr['Z'-'A']-=count;
		arr['E'-'A']-=count;
		arr['R'-'A']-=count;
		arr['O'-'A']-=count;
		count=arr['U'-'A'];
		for(int j=0;j<count;j++) ans+='4';
		arr['F'-'A']-=count;
		arr['O'-'A']-=count;
		arr['U'-'A']-=count;
		arr['R'-'A']-=count;
		count=arr['X'-'A'];
		for(int j=0;j<count;j++) ans+='6';
		arr['S'-'A']-=count;
		arr['I'-'A']-=count;
		arr['X'-'A']-=count;
		count=arr['G'-'A'];
		for(int j=0;j<count;j++) ans+='8';
		arr['E'-'A']-=count;
		arr['I'-'A']-=count;
		arr['G'-'A']-=count;
		arr['H'-'A']-=count;
		arr['T'-'A']-=count;
		count=arr['R'-'A'];
		for(int j=0;j<count;j++) ans+='3';
		arr['T'-'A']-=count;
		arr['H'-'A']-=count;
		arr['R'-'A']-=count;
		arr['E'-'A']-=count;
		arr['E'-'A']-=count;
		count=arr['F'-'A'];
		for(int j=0;j<count;j++) ans+='5';
		arr['F'-'A']-=count;
		arr['I'-'A']-=count;
		arr['V'-'A']-=count;
		arr['E'-'A']-=count;
		count=arr['V'-'A'];
		for(int j=0;j<count;j++) ans+='7';
		arr['S'-'A']-=count;
		arr['E'-'A']-=count;
		arr['V'-'A']-=count;
		arr['E'-'A']-=count;
		arr['N'-'A']-=count;
		count=arr['I'-'A'];
		for(int j=0;j<count;j++) ans+='9';
		arr['N'-'A']-=count;
		arr['I'-'A']-=count;
		arr['N'-'A']-=count;
		arr['E'-'A']-=count;
		count=arr['O'-'A'];
		for(int j=0;j<count;j++) ans+='1';
		arr['O'-'A']-=count;
		arr['N'-'A']-=count;
		arr['E'-'A']-=count;
		sort(ans.begin(),ans.end());
		cout<<"Case #"<<i<<": "<<ans<<endl;
	}
	return 0;
}
