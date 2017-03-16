#include <cstdio>
#include <cstring>

char a[30];
char b[30];
char reta[30],ansa[30];
char retb[30],ansb[30];
int l;
unsigned long long minans;
unsigned long long mina,minb;

unsigned long long sa,sb;

void dfs(int dep,unsigned long long x,unsigned long long y)
{
    if (dep>=l*2)
    {
        unsigned long long t;
        if (x>=y)
            t = x-y;
        else
            t = y-x;
        if (minans==-1 || t<=minans)
            if (minans==-1 || t<minans || x<=mina)
                if (minans==-1 || t<minans || x<mina || y<minb)
                {
                    minans = t;
                    mina = x;
                    minb = y;
                    strcpy(ansa,reta);
                    strcpy(ansb,retb);
                }
        return;
    }

    if (dep<l)
    {
        if (a[dep]!='?')
        {
            x *= 10;
            x += a[dep]-'0';
            reta[dep] = a[dep];
            dfs(dep+1,x,y);
            x /= 10;
        }
        else
        {
            for (int i=0;i<10;i++)
            {
                x *= 10;
                x += i;
                reta[dep] = '0'+i;
                dfs(dep+1,x,y);
                x /= 10;
            }
        }
    }
    else
    {
        if (b[dep-l]!='?')
        {
            y *= 10;
            y += b[dep-l]-'0';
            retb[dep-l] = b[dep-l];
            dfs(dep+1,x,y);
            y /= 10;
        }
        else
        {
            for (int i=0;i<10;i++)
            {
                y *= 10;
                y += i;
                retb[dep-l] = '0'+i;
                dfs(dep+1,x,y);
                y /= 10;
            }
        }
    }
}

int main()
{
    int o,T;
    scanf("%d",&T);
    for (int o=1;o<=T;o++)
    {
        scanf("%s %s",a,b);
        sa=0;
        sb=0;
        l = strlen(a);
        minans = -1;
        memset(reta,0,sizeof(reta));
        memset(retb,0,sizeof(retb));
        dfs(0,0,0);
        printf("Case #%d: %s %s\n",o,ansa,ansb);
    }
    return 0;
}
