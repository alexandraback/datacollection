#include <iostream>
#include <cstdio>
using namespace std;

const int MAXV=31;
bool tab[MAXV];
int t, d, x, c, v;
int main()
{
    scanf("%d", &t);
    for(int h=1;h<=t;h++)
    {
        int wyn=0;
        tab[0]=1;
        scanf("%d%d%d", &c, &d, &v);
        for(int i=1;i<=d;i++)
        {
            scanf("%d", &x);
            for(int j=v;j>=0;j--)
                if(tab[j]==1&&j+x<=v)
                    tab[j+x]=1;
        }
        for(int i=1;i<=v;i++)
            if(tab[i]==0)
            {
                wyn++;
                for(int j=v;j>=0;j--)
                    if(tab[j]==1&&j+i<=v)
                        tab[j+i]=1;
            }
        for(int i=1;i<=v;i++)
            tab[i]=0;
        printf("Case #%d: %d\n", h, wyn);
    }
    return 0;
}

