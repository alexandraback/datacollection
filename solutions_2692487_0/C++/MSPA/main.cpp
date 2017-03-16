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

int a[N];
int main()
{
    // freopen(file_name".in","r",stdin);
    // freopen(file_name".out","w",stdout);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int Test;
    int n,s;
    scanf("%d",&Test);
    int ans=0,k,d;
    for(int test=1;test<=Test;++test)
    {
        scanf("%d%d",&s,&n);
        for(int i=0;i<n;++i) scanf("%d",&a[i]);
        sort(a,a+n);
        k=0;
        for(int i=0;i<n;++i)
            if (s>a[i]) s+=a[i],k++;
            else break;

        ans=n-k;
        d=0;
        int fl=0,c=0;
        while (k<n)
        {
            s+=s-1;
            d++;
            fl=0;
            for(int i=k;i<n;++i)
                if (s>a[i]) s+=a[i],k++,fl=1;
                else break;
            ans = min(ans,n-k+d);
            if (!fl) c++;
            if (c==n) break;
        }
        printf("Case #%d: %d\n",test,ans);
    }
    return 0;
}
