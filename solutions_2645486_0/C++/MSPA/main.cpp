#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <set>
#include <assert.h>

#define file_name ""

typedef long long ll;

const int N = 1e5+5;

using namespace std;
int test;
int a[15],v[15],ans;

int e,r,n,x;
inline void rec(int i, int n)
{
    if (i==n)
    {
        int x=e;
        int fl=0;
        for(int i=0;i<n;++i)
             if (a[i]<=x) {x=x-a[i]+r; if (x>e) x=e;}
             else {fl=1; break;}
        if (fl) return;
        x=0;
        for(int i=0;i<n;++i)
            x+=a[i]*v[i];
        ans = max(ans,x);
        return ;
    }
    for(a[i]=0;a[i]<=e;++a[i])
        rec(i+1,n);
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    scanf("%d",&test);
    for(int t=1;t<=test;++t)
    {
        memset(a,0,sizeof(a));
        scanf("%d%d%d",&e,&r,&n);
        for(int i=0;i<n;++i) scanf("%d",&v[i]);

        ans=0;
        rec(0,n);
        printf("Case #%d: %d\n",t,ans,n,e);
    }

    return 0;
}
