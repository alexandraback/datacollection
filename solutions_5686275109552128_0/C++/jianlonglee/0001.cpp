#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdlib>

#define ll long long
#define maxn 1005
#define inf 0x3f3f3f3f
#define bug puts("here")

using namespace std;

int T,n,m,a[maxn];

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small.out","w",stdout);
   cin>>T;
   int kase=1;
   while(T--){
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",&a[i]);
    int ans=inf;
    for(int i=1;i<=1000;++i)
    {
        int t=0;
        for(int j=0;j<n;++j)
        {
            t+=(a[j]+i-1)/i-1;
        }
        ans=min(ans,t+i);
    }
    printf("Case #%d: %d\n",kase++,ans);
   }
}
