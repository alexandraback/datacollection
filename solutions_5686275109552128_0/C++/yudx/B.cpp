#include<stdio.h>
#include<algorithm>
#include<vector>
#include<math.h>
#include<string.h>
#include<vector>
#include<map>
#include<set>
#include<iostream>

using namespace std;

typedef long long ll;

int n,a[1005];

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    int T,I=1,i,j;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++) scanf("%d",a+i);
        sort(a,a+n);
        int r=a[n-1];
        for(i=1;i<a[n-1];i++)
        {
            int rt=i;
            for(j=0;j<n;j++)
            {
                if(a[j]>i)
                {
                    rt=rt+(a[j]-1)/i;
                }
            }
            r=min(r,rt);
        }
        printf("Case #%d: %d\n",I++,r);
    }
    return 0;
}
