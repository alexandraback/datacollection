#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <sstream>
#include <fstream>

using namespace std;

map<string,int> g;
int f[5005][10];

void work(string s,int i,int j)
{
	if (i==(int)s.size())
	{
		g[s]=1;
		return;
	}
	work(s,i+1,j);
	if (i>=j)
	{
		char c=s[i];
		s[i]='?';
		work(s,i+1,i+5);
		s[i]=c;
	}
}

void dfs(int p,int q,int ii,int jj,string s,int i,int j,int k)
{
	if (i==(int)s.size())
	{
//		if (p==0 && q==0 && ii==4) cerr<<s<<endl;
		if (g[s]==1)
			f[ii][jj]=min(f[ii][jj],f[p][q]+k);
		return;
	}
	dfs(p,q,ii,jj,s,i+1,j,k);
	if (i>=j)
	{
		char c=s[i];
		s[i]='?';
		dfs(p,q,ii,max(jj,i+5-(int)s.size()),s,i+1,i+5,k+1);
		s[i]=c;
	}
}

int main()
{
	ifstream fin("dic.txt",ios::in);
	string s;
	int len=0;
	while (fin>>s)
	{
		work(s,0,0);
		if (s.size()>len) len=s.size();
	}
	cerr<<len<<endl;
	#ifdef LOCAL_TEST
		freopen("c.in","r",stdin);
		freopen("c.out","w",stdout);
	#endif
	int task;
	cin>>task;
	for (int tt=1;tt<=task;++tt)
	{
		cout<<"Case #"<<tt<<": ";
		cin>>s;
		int n=s.size();
		for (int i=0;i<=n;++i)
			for (int j=0;j<5;++j) f[i][j]=1000000000;
		f[0][0]=0;
		for (int i=0;i<n;++i)
			for (int j=0;j<5;++j)
				for (int k=1;k<=10;++k)
					if (i+k<=n)
					{
						string ss="";
						for (int p=i;p<i+k;++p) ss+=s[p];
			//			cerr<<ss<<endl;
						dfs(i,j,i+k,max(j-(int)ss.size(),0),ss,0,j,0);
					}
		int ans=1000000000;
		for (int j=0;j<5;++j) ans=min(ans,f[n][j]);
		cout<<ans<<endl;
	}
	return 0;
}
