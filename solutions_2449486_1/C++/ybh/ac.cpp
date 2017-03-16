#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP make_pair

#define REP(i,n) for(i=0;i<(n);++i)
#define FOR(i,l,h) for(i=(l);i<=(h);++i)
#define FORD(i,h,l) for(i=(h);i>=(l);--i)

#define maxn 110
#define maxm 110
#define maxheight 100 

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

int a[maxn][maxm],f[maxn][maxm];

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("output.txt","w",stdout);
	
	int T;
	scanf("%d",&T);
	for (int TT=1;TT<=T;TT++)
	{
		printf("Case #%d: ",TT);
		
		int n,m;
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				scanf("%d",&(a[i][j]));
		
		for (int h=maxheight;h>=1;h--)
		{
			for (int i=1;i<=n;i++)
			{
				bool flag=true;
				for (int j=1;j<=m;j++)
					if (a[i][j]>h) flag=false;
				if (flag)
					for (int j=1;j<=m;j++)
						f[i][j]=h;
			}
			for (int i=1;i<=m;i++)
			{
				bool flag=true;
				for (int j=1;j<=n;j++)
					if (a[j][i]>h) flag=false;
				if (flag)
					for (int j=1;j<=n;j++)
						f[j][i]=h;
			}
		}
		
		bool ans=true;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				if (a[i][j]!=f[i][j]) ans=false;
		if (ans) printf("YES\n"); else printf("NO\n");
	}
	
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
