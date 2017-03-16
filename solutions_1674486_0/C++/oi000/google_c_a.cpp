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
int b[2000][2000],f[2000];
void dog(int x,int y)
{
	int j;
	if (f[x]>=2&&x!=y) return ;
	if (f[x]>=3) return ;
	for(j=1;j<=b[x][0];j++)
	{
		f[b[x][j]]++;
		dog(b[x][j],y);
	}
}



int main()
{
	int i,n,flg,ii,j,t;
	freopen("A-small-attempt1.in","r",stdin);freopen("A-small-attempt0.txt","w",stdout);
   
	scanf("%d",&t);
	for(ii=1;ii<=t;ii++)
	{
		scanf("%d",&n);
		if(ii==2)
		{
			int gh=0;
		}
		for(i=1;i<=n;i++)
		{
			scanf("%d",&b[i][0]);
			for(j=1;j<=b[i][0];j++)
			{
				scanf("%d",&b[i][j]);
			}
		}
		flg=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
				f[j]=0;
			f[i]=1;
			
			dog(i,i);
			for(j=1;j<=n;j++)
				if (j!=i&&f[j]>=2) 
				{
					flg=2;
				}
			if (flg==2) break;
		}
		if (flg==2)
			printf("Case #%d: Yes\n",ii);
		else
			printf("Case #%d: No\n",ii);
	}

	return 0;
}
