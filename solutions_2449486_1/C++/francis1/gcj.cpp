

#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;
int a[105][105];
int n,m;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int T,cas=0;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				scanf("%d",&a[i][j]);
		bool ok=1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				bool o=1;
				for(int k=1;k<=m;k++)
					if(a[i][k]>a[i][j])o=0;
				if(o)continue;
				o=1;
				for(int k=1;k<=n;k++)
					if(a[k][j]>a[i][j])o=0;
				if(o)continue;
				ok=0;
			}

		printf("Case #%d: %s\n",++cas,ok?"YES":"NO");
	}
}
