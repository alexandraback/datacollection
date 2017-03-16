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
__int64 r,t;
int T,id;
int i,j;
__int64 ans,ll,rr,mid,tmp;
int f[1000];

int main()
{
	freopen("A-small-attempt0.in","r",stdin);freopen("a.out","w",stdout);
    scanf("%d",&T);
    for (id=1;id<=T;id++)
    {
		scanf("%I64d%I64d",&r,&t);
		ll=1;rr=sqrt(t);
		while(ll<rr)
		{
			mid=(ll+rr)/2;
			tmp=(2*r+2*mid-1);
			if (tmp<=(1.0*t/mid))
			{
				ll=mid+1;
			}
			else
			{
				rr=mid;
			}
		}
		ans=ll-1;
		printf("Case #%d: %I64d\n",id,ans);
    }
	return 0;
}
/* (r+1)^2-r^2+(r+3)^2-(r+2)^2+...+(r+2n-1)^2-(r+2n-2)^2
  =(r+r+1+r+2+r+3+r+2n-2+r+2n-1)
  =(r+r+2n-1)*(2n)/2
   (2r+2n-1)*n<=t
   2n^2+(2*r-1)n-t=0
   n=(1-2*r+sqrt((2*r-1)^2+8t))/4
  
*/
