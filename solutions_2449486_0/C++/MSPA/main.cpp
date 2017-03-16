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

#define file_name ""

typedef long long ll;

const int N = 1e5+5;

using namespace std;

int main()
{
    // freopen(file_name".in","r",stdin);
    // freopen(file_name".out","w",stdout);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int x,d,t,n,m;
    int a[111][111];
    int b[111][111];
    int gm[111],vm[111];

    int fl=0;

    scanf("%d",&t);
    for(int test=1;test<=t;++test)
    {
        scanf("%d%d",&n,&m);
        memset(gm,0,sizeof(gm));
        memset(vm,0,sizeof(vm));
        for(int i=0;i<n;++i)
            for(int j=0;j<m;++j)
            {
                scanf("%d",&a[i][j]);
                gm[i] = max(gm[i],a[i][j]);
                vm[j] = max(vm[j],a[i][j]);
            }

        fl=0;
        for(int i=0;i<n;++i)
            for(int j=0;j<m;++j)
                if (gm[i]>a[i][j] && vm[j]>a[i][j]) {fl=1;  break;}


        printf("Case #%d: ",test);
        if (fl) printf("NO\n");
        else printf("YES\n");

    }
    return 0;
}
