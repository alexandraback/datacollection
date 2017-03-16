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

const int N = 1e7+5;

using namespace std;

int ok(ll x)
{
    char s[111];
    int n=0;
    while(x)
    {
        s[n++] = 48+x%10;
        x/=10;
    }
    for(int i=0;i<n;++i)
        if(s[i]!=s[n-1-i]) return 0;
    return 1;
}

int main()
{
    // freopen(file_name".in","r",stdin);
    // freopen(file_name".out","w",stdout);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ll a[111];
    int k=0;
    a[0]=0;
    for(ll i=1;i<N;++i)
    {
        if (ok(i) && ok(i*i)) a[k++] = i*i;
    }
    int t;
    scanf("%d",&t);
    ll l,r;
    int ans=0;
    for(int test=1;test<=t;++test)
    {
        scanf("%lld%lld",&l,&r);
        ans=0;
        for(int i=0;i<k;++i)
            if (a[i]>=l && a[i]<=r) ans++;
        printf("Case #%d: %d\n",test,ans);

    }
    return 0;
}
