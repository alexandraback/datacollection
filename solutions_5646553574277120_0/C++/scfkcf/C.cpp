#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#define PB push_back
#define MP make_pair
#define X first
#define Y second
#define lc (k<<1)
#define rc ((k<<1)|1)
#define mi ((l+r)>>1)
#define fk puts("fuck!")
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int a[9];
bool f[333];
vector<int> vec;

int main()
{
	//freopen("in","r",stdin);///
	int cas;scanf("%d",&cas);
	for(int t=1;t<=cas;t++)
	{
		memset(f,0,sizeof(f));
		vec.clear();
		int c,d,v;
		scanf("%d%d%d",&c,&d,&v);
		for(int i=0;i<d;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<(1<<d);i++)
		{
			int now=0;
			for(int j=0;j<d;j++)
				if(i&(1<<j)) now+=a[j];
			if(now<=v)
			{
				if(!f[now]) vec.PB(now);
				f[now]=true;
			}
		}
		int ans=0;
		for(int i=1;i<=v;i++)
			if(!f[i])
			{
				int sz=vec.size();
				int add=i;
				if(!f[i]) vec.PB(i);
				f[i]=true;
				ans++;
				for(int i=0;i<sz;i++)
				{
					int nex=vec[i]+add;
					if(nex<=v)
					{
						if(!f[nex]) vec.PB(nex);
						f[nex]=true;
					}
				}
			}
		printf("Case #%d: %d\n",t,ans);
	}
	return 0;
}