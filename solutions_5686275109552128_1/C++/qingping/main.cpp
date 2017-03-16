#include <iostream>
#include <cstdio>
#include <stack>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
//#include <unordered_map>
#define N 1010
using namespace std;
int num[N];
int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int T;
    scanf("%d",&T);
    int cas=0;
    while(T--)
    {
        int n;
        scanf("%d",&n);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&num[i]);
            ans=max(ans,num[i]);
        }
        for(int x=2;x<ans;x++)
        {
            int sum=0;
            for(int i=0;i<n;i++)
                sum+=(num[i]-1)/x;
            ans=min(ans,sum+x);
        }
        printf("Case #%d: %d\n",++cas,ans);
    }
    return 0;
}
