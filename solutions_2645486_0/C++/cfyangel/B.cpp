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

using namespace std;

int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
int e,r,n;
__int64 v[10010];
int t,id;
int i,j,k;
__int64 f[100][100],ans;

void init()
{
	scanf("%d%d%d",&e,&r,&n);
	for (i=0;i<n;i++)scanf("%I64d",&v[i]);
}

int main()
{
	freopen("B-small-attempt1.in","r",stdin);freopen("b.out","w",stdout);
    scanf("%d",&t);
    for (id=1;id<=t;id++)
    {
		printf("Case #%d: ",id);
		init();
		memset(f,0,sizeof(f));
		for (i=0;i<=e;i++)f[0][i]=(e-i)*v[0];
		for (i=1;i<n;i++)
		{
			for (j=0;j<=e;j++)
			{
				for (k= j-r>0 ?j-r : 0;k<e;k++)
				{
					if (f[i-1][k]+v[i]*(k+r>e ? e-j : k+r-j)>f[i][j])
						f[i][j]=f[i-1][k]+v[i]*(k+r-j);
				}
			}
		}
		ans=f[n-1][0];
		printf("%I64d\n",ans);
    }
	return 0; 
}