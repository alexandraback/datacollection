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



int main()
{
	//freopen("in","r",stdin);///
	int cas;scanf("%d",&cas);
	for(int t=1;t<=cas;t++)
	{
		int r,c,w;scanf("%d%d%d",&r,&c,&w);
		int ans=0;
		int mxline=c/w;
		ans+=r*mxline-1+w;
		if(c%w) ans++;
		printf("Case #%d: %d\n",t,ans);
	}
	return 0;
}