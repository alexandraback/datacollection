/*
User:JeffCsoul
Time:
No.:
Everything will be better.
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cstdlib>

#define LL long long
#define REP(i,n) for (int i=1;i<=n;i++)
#define FOR(i,n) for (__typeof(n.begin())i=n.begin();i!=n.end();i++)

using namespace std;

int p[100],nm,sp[100];
int n,cnt;
int ps,spt;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("ccout-s.txt","w",stdout);
	int T;
	cin>>T;
	for (int nT=1;nT<=T;nT++)
	{
		scanf("%d",&n);
		cnt=0;
		memset(p,0,sizeof p);
		memset(sp,0,sizeof sp);
		for (int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&ps,&nm,&spt);
			for (int j=0;j<nm;j++)
			{
				cnt++;
				p[cnt]=ps;
				sp[cnt]=spt+j;
			}
		}
		int ans=0;
		printf("Case #%d: ",nT);
		for (int i=1;i<=cnt;i++)
		{
			bool flg=true;
			for (int j=1;j<=cnt;j++)
			{
				if ((360.0-p[i])/360.0*sp[i]>=(720.0-p[j])/360.0*sp[j])
					flg=false;
				if ((360.0-p[j])/360.0*sp[j]>=(720.0-p[i])/360.0*sp[i])
					flg=false;
			}
			if (!flg)	ans++;
		}
		cout<<ans/2<<endl;
	}
}


