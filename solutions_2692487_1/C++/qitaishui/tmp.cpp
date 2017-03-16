#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;
const int maxn = 1000005;
const int inf = 1111111111;
int num[maxn],n;
long long a,b;
int find(int x,int y)
{
    int ret=0;
    while(x<=y)
    {
        x+=x-1;
        ret++;
    }
    b=x;
    return ret;
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int cas,ans,op;
    scanf("%d",&cas);
    for(int ca=1; ca<=cas;ca++)
    {
        scanf("%lld%d",&a,&n);
        for(int i = 0; i < n; i++)
            scanf("%d",&num[i]);
        sort(num,num+n);

        ans = n;
        op=0;
        bool flag = 0;
        for(int i = 0; i < n&&a>1; i++)
        {
            if(a>num[i]) a+=num[i];
            else
            {
                flag = 1;
                int tmp = find(a,num[i]);
                ans = min(ans,op+n-i);
                op+=tmp;
                a=b+num[i];
            }
        }
        if(a>1)
            ans = min(ans,op);
        if(!flag&&a>1) ans = 0;
        printf("Case #%d: %d\n",ca,ans);
    }
    return 0;
}


