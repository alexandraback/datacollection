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
int T,id;
int i,j;
int a,n,ans,b;
__int64 now;
int f[1000];

int main()
{
	freopen("A-large.in","r",stdin);freopen("A-large.out","w",stdout);
    scanf("%d",&T);
    for (id=1;id<=T;id++)
    {
        scanf("%d%d",&a,&n);
        for (i=0;i<n;i++)scanf("%d",&f[i]);
        qsort(f,n,sizeof(f[0]),cmp);
        ans=n;b=0;
        now=a;
        if (a>1)
        {
            for (i=0;i<n;i++)
            {
                if (now>f[i])
                {
                    now+=f[i];
                }
                else
                {
                    ans=min(ans,b+n-i);
                    while(now<=f[i])
                    {
                        b++;
                        now+=now-1;
                    }
                    now+=f[i];
                    ans=min(ans,b+n-i-1);
                }
      //          printf("now=%d,",now);
            }
    //        printf("f[0]=%d,b= %d ,now=%d\n",f[0],b,now);
            ans=min(ans,b);
        }
		printf("Case #%d: %d\n",id,ans);
    }
	return 0;
}

/*
10+9+18+20+25
*/

