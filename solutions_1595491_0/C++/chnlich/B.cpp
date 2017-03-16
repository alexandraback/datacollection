/*
	Author: chnlich
*/

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cmath>
#include<cctype>
#include<climits>
#include<iostream>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<algorithm>
#include<numeric>
#include<functional>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<stack>
#include<bitset>
#include<string>
#include<list>
#include<deque>
#include<utility>

using namespace std;

typedef long long llint;
typedef unsigned long long ull;
typedef pair<int,int> ipair;
#define debug(x) cerr<<#x<<'='<<x<<endl;
#define fi first
#define se second
#define mp make_pair
#define pb push_back

void read(int &k)
{
	char x=getchar(); k=0;
	while(x<'0'||x>'9') x=getchar();
	while(x>='0'&&x<='9') { k=k*10-48+x; x=getchar(); }
}

int T,n,p,q,k,ans,a[35],b[35];

int main()
{
	//freopen("B.in","r",stdin);
	//freopen("B.out","w",stdout);
	
	for(int i=0;i<=30;i++)
		for(int j=0;j<=10;j++)
		for(int k=0;k<=10;k++) if (abs(j-k)<2)
		{
			int t=i-j-k;
			if (t>=0&&t>=j&&t>=k&&abs(t-j)<2&&abs(t-k)<2) a[i]=max(a[i],t);
		}
	for(int i=0;i<=30;i++)
		for(int j=0;j<=10;j++)
		for(int k=0;k<=10;k++) if (abs(j-k)<3)
		{
			int t=i-j-k;
			if (t>=0&&t>=j&&t>=k&&abs(t-j)<3&&abs(t-k)<3) b[i]=max(b[i],t);
		}
	
	scanf("%d",&T);
	for(int tt=1;tt<=T;tt++)
	{
		scanf("%d%d%d",&n,&p,&q);
		ans=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&k);
			if (a[k]>=q) ans++;
			else if (p&&b[k]>=q) ans++,p--;
		}
		printf("Case #%d: %d\n",tt,ans);
	}
	
	return 0;
}

