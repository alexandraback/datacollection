#include <cstdio>
#include <cstring>

int b;
long long m;
int a[60][60];
long long f[60];

void init()
{
    memset(f,0,sizeof(f));
    f[1]=(long long)1;
    for (int i=2;i<=50;i++)
    {
        for (int j=i-1;j>=1;j--)
            f[i]+=f[j];
    }
}

void connect(int x)
{
    if (x==1) return;
    bool flag=true;
    for (int i=x-1;i>=1;i--)
    {
        a[i][x]=1;
        if (flag)
        {
            connect(i);
            flag=false;
        }
    }
}

int main()
{
    int T;
    init();
    scanf("%d",&T);
    for (int o=1;o<=T;o++)
    {
        scanf("%d %lld",&b,&m);
        printf("Case #%d: ",o);
        if (m>f[b])
        {
            puts("IMPOSSIBLE");
            continue;
        }
        puts("POSSIBLE");
        memset(a,0,sizeof(a));

        int x;
        bool flag=true;
        x = b;
        while (m)
        {
            while (f[x]>m) x--;
            m-=f[x];
            if (x!=b) a[x][b]=1;
            if (flag)
            {
                connect(x);
                flag=false;
            }
            x--;
        }
        for (int i=1;i<=b;i++)
        {
            for (int j=1;j<=b;j++)
                printf("%d",a[i][j]);
            puts("");
        }
    }
    return 0;
}
