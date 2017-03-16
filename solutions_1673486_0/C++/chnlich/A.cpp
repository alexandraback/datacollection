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

int T,n,m;
double a[100010],ps[100010],ans;

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	
	scanf("%d",&T);
	for(int tt=1;tt<=T;tt++)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) scanf("%lf",&a[i]);
		ps[0]=1;
		for(int i=1;i<=n;i++) ps[i]=ps[i-1]*a[i];
		ans=m+2;
		for(int i=0;i<=n;i++)
			ans=min(ans,i+ps[n-i]*(m-(n-i)+1)+(1-ps[n-i])*(m-(n-i)+1+m+1));
		printf("Case #%d: %.8lf\n",tt,ans);
	}
	
	return 0;
}

