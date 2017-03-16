#include <stdio.h>
#include <string.h>

const int maxn=1010;
int a[maxn],b[maxn];
bool flag[maxn][2];

int main()
{
    int cas;
    int n;

    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    scanf("%d",&cas);
    for(int ii=1;ii<=cas;ii++)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d %d",&a[i],&b[i]);
        memset(flag,0,sizeof(flag));
        int now=0;
        bool nowflag=1;
        int ans=0;
        while(nowflag)
        {
            nowflag=0;
            for(int i=0;i<n;i++)
             if (now>=b[i]&&flag[i][1]==0)
             {
                 now+=(2-flag[i][0]);
                 ans++;
                 flag[i][1]=1;
                 flag[i][0]=1;
                 nowflag=1;
             }
            if (nowflag) continue;
            int maxs=-1;
            int mj=0;
            for(int i=0;i<n;i++)
             if (now>=a[i]&&flag[i][0]==0)
             {
                 if (b[i]>=maxs)
                 {
                     maxs=b[i];
                     mj=i;
                 }
             }
            if (maxs>=0)
            {
                ans++;
                now++;
                nowflag=1;
                flag[mj][0]=1;
            }
        }
        nowflag=1;
        for(int i=0;i<n;i++)
         if (flag[i][1]==0) nowflag=0;
        printf("Case #%d: ",ii);
        if (nowflag) printf("%d\n",ans);
        else puts("Too Bad");
    }
    return 0;
}

