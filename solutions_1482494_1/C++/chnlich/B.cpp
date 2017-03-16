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

int T,n,cho[1010],nt,rem,now,ym,t,mi;
ipair a[1010];

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	
	scanf("%d",&T);
	for(int tt=1;tt<=T;tt++)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++) scanf("%d%d",&a[i].fi,&a[i].se);
		rem=n; now=0; ym=0;
		memset(cho,0,sizeof cho);
		while(1)
		{
			while(rem)
			{
				nt=rem;
				for(int j=0;j<n;j++) if (cho[j]<2&&a[j].se<=now)
					now+=2-cho[j],cho[j]=2,rem--,ym++;
				if (nt==rem) break;
			}
			t=-1; mi=-1;
			for(int j=0;j<n;j++) if (cho[j]==0&&a[j].fi<=now&&a[j].se>mi) mi=a[t=j].se;
			if (t<0) break;
			ym++;
			cho[t]++;
			now++;
		}
		printf("Case #%d: ",tt);
		if (rem) puts("Too Bad"); else printf("%d\n",ym);
	}
	
	return 0;
}

