#include<iostream>
#include<sstream>
#include<string>
#include<queue>
#include<vector>
#include<map>
#include<stack>
#include<set>
#include<numeric>
#include<algorithm>
#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<limits>
using namespace std;

typedef long long LL;

char mp[32];
bool vis[32];
string org="ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv y qee";
string tar="our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up a zoo";

int main(int argc, char *argv[])
{
#ifdef CHAOS
	freopen("data.in","r",stdin);
#endif
	int i;
	int orglen=org.size();
	for(i=0;i<orglen;++i)
	{
		if(isalpha(org[i]))
		{
			mp[org[i]-'a']=tar[i];
			vis[org[i]-'a']=true;
		}
	}
	int T;
	cin>>T;
	string g;
	getline(cin,g);
	//for(i=0;i<32;++i)
	//{
	//	cout<<char(i+'a')<<"->"<<mp[i]<<" ";
	//	cout<<vis[i]<<endl;
	//}
	for(i=1;i<=T;++i)
	{
		cout<<"Case #"<<i<<": ";
		getline(cin,g);
		int j;
		for(j=0;j<(int)g.size();++j)
		{
			if(isalpha(g[j])) cout<<mp[g[j]-'a'];
			else cout<<g[j];
		}
		cout<<endl;
	}
	return 0;
}
