#include <cstdio>
#include <algorithm>

using namespace std;

void solvetp()
{
    int k,c,s;
    scanf("%d%d%d",&k,&c,&s);
    if (s*c<k)
        printf("IMPOSSIBLE\n");
    else
    {
        int cur=1;
        for (int i=1; i<=s; i++)
        {
            long long pos,ex;
            ex=1;
            pos=1;
            for (int lv=1; lv<=c; lv++)
            {
                if (cur<=k)
                {
                    pos=pos+cur-1;
                    cur++;
                }
                if (lv<c)
                {
                    pos=(pos-1)*k+1;
                }
            }
            if (pos!=1 || i==1)
                printf("%lld ",pos);
        }
        printf("\n");
    }
}

int main()
{
    freopen("D:/in.txt","r",stdin);
    freopen("D:/out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for (int it=1; it<=t; it++)
    {
        printf("Case #%d: ",it);
        solvetp();
    }
}
