#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
#define N 1010
int main()
{
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        int a[N],b[N],st[N]={0};
        int n,sum=0,ans=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&a[i],&b[i]);
        }
        //int s;
        while(sum<2*n)
        {
            int flag=0;
            for(int i=0;i<n;i++)
                if(sum>=b[i]&&st[i]<2)
                {
                    sum+=2-st[i];
                    st[i]=2;
                    flag=1;
                    ans++;
                    break;
                }
            if(flag)
                continue;
            int mb=-1,lab=-1;
            for(int i=0;i<n;i++)
                if(sum<b[i]&&sum>=a[i]&&st[i]==0)
                    if(mb<b[i])
                    {

                        mb=b[i];
                        lab=i;
                    }
            if(mb==-1) goto FAIL;
            st[lab]=1;
            sum++;
            ans++;
        }
        printf("Case #%d: %d\n",cas,ans);
        continue;
        FAIL:;
        printf("Case #%d: Too Bad\n",cas);
    }

    return 0;
}
