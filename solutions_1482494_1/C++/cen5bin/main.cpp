#include <cstdio>
#include <cstring>

int main()
{
    freopen("in","r",stdin);
    freopen("a.txt","w",stdout);
    int a[1010],b[1010];
    bool flag1[1010],flag2[1010];
    int t;
    int cas = 0;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        scanf("%d%d",&a[i],&b[i]);
        memset(flag1,0,sizeof(flag1));
        memset(flag2,0,sizeof(flag2));
        int now = 0,cnt=0;
        int x = 0;
        bool t0 = 0;
        bool t1 = 0;
        while(1)
        {
            t1 = 0;
            for(int i=0; i<n; i++)
            if(!flag2[i]&&now>=b[i])
            {
                if(!flag1[i])
                now+=2,flag1[i] = 1;
                else
                now++;
                cnt++;
                flag2[i] = 1;
                x++;
                t1 = 1;
            }
            if(t1)
            continue;
            if(x==n)
            {
                t0 = 1;
                break;
            }
            int index = -1;
            int max = -1;
            for(int i=0; i<n; i++)
            if(!flag1[i]&&!flag2[i]&&now>=a[i])
            {
                index = i;
                break;
            }
            if(index==-1)
            {
                break;
            }
            for(int i=0; i<n; i++)
            if(!flag1[i]&&!flag2[i]&&now>=a[i])
            {
                if(b[i]>b[index])
                index = i;
            }
            flag1[index] = 1;
            now++;
            cnt++;
        }
        printf("Case #%d: ",++cas);
        if(t0)
        printf("%d\n",cnt);
        else
        printf("Too Bad\n");
    }
    return 0;
}
