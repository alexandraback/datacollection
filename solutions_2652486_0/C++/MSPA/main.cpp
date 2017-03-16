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

int flag,n,r,k,m;
int a[55],b[55];
int us[55];
inline void rec(int i, int n)
{
    if (i==n)
    {
        memset(us,0,sizeof(us));
        for(int i=0;i<(1<<n);++i)
        {
            int x=1;
            for(int j=0;j<n;++j)
                if (i&(1<<j)) x*=b[j];
            for(int j=0;j<k;++j)
                if (!us[j] && a[j]==x) us[j]=1;
        }
        for(int i=0;i<k;++i)
            if (!us[i]) return ;
        flag=1;
        return;
    }
    for(b[i]=2;b[i]<=m;++b[i])
    {
        rec(i+1,n);
        if (flag) return;
    }
}
int main()
{
    // freopen(file_name".in","r",stdin);
    // freopen(file_name".out","w",stdout);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    scanf("%d",&t);

    printf("Case #%d:\n",t);
    scanf("%d%d%d%d",&r,&n,&m,&k);
    for(int j=0;j<r;++j)
    {

        for(int i=0;i<k;++i) scanf("%d",&a[i]);
        flag=0;
        rec(0,n);
        if (flag) for(int i=0;i<n;++i)printf("%d",b[i]);
        else for(int i=0;i<n;++i) printf("2");
        printf("\n");
    }
    return 0;
}
