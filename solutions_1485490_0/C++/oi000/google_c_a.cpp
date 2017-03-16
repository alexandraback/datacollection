#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include<fstream>
using namespace std;
__int64 n,m,tot;
__int64 b[20000][20],c[20000][20];
void dog(__int64 x,__int64 y,__int64 g,__int64 h,__int64 u)
{
	if (x>n)
	{
		if (u>tot) tot=u;
		return ;
	}
	if (g>m)
	{
		if (u>tot) tot=u;
		return ;
	}
	if (b[x][3]==c[g][3])
	{
		if (y>h)
		{
			
			dog(x,y-h,g+1,c[g+1][2],u+h);
		}
		else
		{
			dog(x+1,b[x+1][2],g,h-y,u+y);
		}
		return ;
	}
	dog(x,y,g+1,c[g+1][2],u);
	dog(x+1,b[x+1][2],g,h,u);
}


int main()
{
	__int64 ii,i,t;
	freopen("C-small-attempt1.in","r",stdin);freopen("A-small-attempt0.txt","w",stdout);
	scanf("%I64d",&t);
	for(ii=1;ii<=t;ii++)
	{
		if(ii==5)
		{
			__int64 ghy=0;
		}
		scanf("%I64d%I64d",&n,&m);
		for(i=1;i<=n;i++)
			scanf("%I64d%I64d",&b[i][2],&b[i][3]);
		for(i=1;i<=m;i++)
			scanf("%I64d%I64d",&c[i][2],&c[i][3]);
		tot=0;
		for(i=1;i<=n;i++)
		{
			dog(i,b[i][2],1,c[1][2],0);
		}
		printf("Case #%I64d: %I64d\n",ii,tot);
	}
	return 0;
}

