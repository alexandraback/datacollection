#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstring>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

#define SIZE(x) (int((x).size()))
#define rep(i,l,r) for (int i=(l); i<=(r); i++)
#define repd(i,r,l) for (int i=(r); i>=(l); i--)
#define rept(i,c) for (typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)

#ifndef ONLINE_JUDGE
#define debug(x) { cerr<<#x<<" = "<<(x)<<endl; }
#else
#define debug(x) {}
#endif

char s[1010];

void lemon()
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	string ans="";
	rep(i,1,n)
	{
		string a1=ans+s[i];
		string t=" "; t[0]=s[i];
		string a2=t+ans;
		if (a1>a2) ans=a1; else ans=a2;
	}
	cout<<ans<<endl;
}

int main()
{
	ios::sync_with_stdio(true);
	#ifndef ONLINE_JUDGE
		freopen("A.in","r",stdin);
	#endif
	int tcase; scanf("%d",&tcase);
	rep(nowcase,1,tcase)
	{
		printf("Case #%d: ",nowcase);
		lemon();
	}
	return 0;
}

