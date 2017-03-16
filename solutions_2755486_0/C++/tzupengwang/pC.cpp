#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

struct A
{
    int a,b,c,d;
    bool operator< (const A &x)const
    {
        return a<x.a;
    }
}s[100000];

int num;

int main()
{
    freopen("C-small-attempt0 (1).in","r",stdin);
    freopen("out.txt","w",stdout);
    int amm,cnt=0;
    scanf("%d",&amm);
    while (amm--)
    {
        cnt++;
        scanf("%d",&num);
        int ptr=0;
        int a,b,c,d,e,f,g,h;
        for (int i=0;i<num;i++)
        {
            scanf("%d%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g,&h);
            for (int j=0;j<b;j++)
            {
                s[ptr++]=(A){a,(c+500)*2,(d+500)*2,e};
                a+=f;c+=g;d+=g;e+=h;
            }
        }
        sort(s,s+ptr);

        int suc=0;
        int wall[2000];
        int next[2000];
        memset(wall,0,sizeof wall);
        memset(next,0,sizeof next);
        int lastday=-1;
        for (int i=0;i<ptr;i++)
        {
            if (lastday!=s[i].a)
            {
                lastday=s[i].a;
                for (int i=0;i<2000;i++)
                {
                    wall[i]=next[i];
                }
            }
            bool OK=false;
            for (int j=s[i].b;j<=s[i].c;j++)
            {
                if (s[i].d>wall[j])
                {
                    OK=true;
                    next[j]=max(s[i].d,next[j]);
                }
            }
            if (OK)suc++;
        }
        printf("Case #%d: %d\n",cnt,suc);
    }
    return 0;
}
