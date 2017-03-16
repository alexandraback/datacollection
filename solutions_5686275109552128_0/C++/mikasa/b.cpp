#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int maxn = 1005;

int n,da[maxn];

int f(int x,int y)
{
    if(x<=y)
        return 0;
    return f(x-y,y) + 1;
}
int main()
{
    int t,cs=0;scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",da+i);
        sort(da,da+n);
        reverse(da,da+n);int r = (1<<29);
        for(int i=1;i<=da[0];i++)
        {
            int c = 0;
            for(int j=0;j<n;j++)
            {
                if(da[j]<=i)
                    break;
                c+= f(da[j],i);
            }
            r = min(r,i+c);
        }
        printf("Case #%d: %d\n",++cs,r);
    }
}
