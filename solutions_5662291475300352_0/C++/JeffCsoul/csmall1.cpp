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

int p[10],nm[10],sp[10];
int n;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("ccout.txt","w",stdout);
	int T;
	cin>>T;
	for (int nT=1;nT<=T;nT++)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&p[i],&nm[i],&sp[i]);
		}
		printf("Case #%d: ",nT);
		if (n==1)
		{
			puts("0");
			continue;
		}
		else
		{
			bool flg=true;
			if ((360.0-p[1])/360.0*sp[1]>=(720.0-p[2])/360.0*sp[2])
				flg=false;
			if ((360.0-p[2])/360.0*sp[2]>=(720.0-p[1])/360.0*sp[1])
				flg=false;
			
			if (flg)
				puts("0");
			else
				puts("1");
		}
	}
}


