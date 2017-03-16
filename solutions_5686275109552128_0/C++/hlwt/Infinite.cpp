#include <bits/stdc++.h>

using namespace std;

int a[1010],n;

bool check(int ans,int limit)
{
    int num=0;
    for(int i=1;i<=n;i++) {
        int fuck=a[i]/limit;
        if(a[i]%limit)
            fuck++;
        num+=fuck-1;
    }
    if(num+limit<=ans)
        return true;
    return false;
}

int main()
{
    freopen("B-small-attempt1.in","r",stdin);
    freopen("B-small-attempt1.out","w",stdout);
    int T,cas=0;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        int low=0,high=1000,mid;
        while(low<high-1) {
            int flag=0;
            mid=(low+high)/2;
            for(int limit=1;limit<=mid;limit++) {
                if(check(mid,limit)) {
                    flag=1;
                    break;
                }
            }
            if(flag==1)
                high=mid;
            else
                low=mid;
        }
        printf("Case #%d: %d\n",++cas,high);
    }
    return 0;
}
