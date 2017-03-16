#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

bool cmp(int x,int y)
{
    return x<y;
}

int a[105];

int main()
{
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    int i,j,n,T,x,p,ans,s,cnt=1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&p,&n);
        for (i=0;i<n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n,cmp);
        if (p==1)
        {
            printf("Case #%d: %d\n",cnt++,n);
            continue;
        }
        ans=100000000;
        for (i=n;i>=0;i--)
        {
            s=n-i;
            x=p;
            for (j=0;j<i;j++)
            {
                while(x<=a[j])
                {
                    x+=(x-1);
                    s++;
                }
                x+=a[j];
                if (x>a[n-1]) x=a[n-1]+1;
             //   printf("%d: %d\n",j,x);
            }
           // printf("\n");
            ans=min(ans,s);
        }
        printf("Case #%d: %d\n",cnt++,ans);
    }
    return 0;
}
