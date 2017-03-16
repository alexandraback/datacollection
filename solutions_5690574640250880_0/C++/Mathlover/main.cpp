#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<iostream>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#include<list>
using namespace std;
int a[55];
int main()
{
    freopen("C-small-attempt1.in","r",stdin);
    freopen("out","w",stdout);
    int t,ca=0;
    scanf("%d",&t);
    while(t--)
    {
        printf("Case #%d:\n",++ca);
        int r,c,m;
        scanf("%d%d%d",&r,&c,&m);
        if(r==1)
        {
            int i=0;
            for(; i<m; ++i)
                putchar('*');
            for(; i<c-1; ++i)
                putchar('.');
            puts("c");
            continue;
        }
        if(c==1)
        {
            int i=0;
            for(; i<m; ++i)
                puts("*");
            for(; i<r-1; ++i)
                puts(".");
            puts("c");
            continue;
        }
        int q=r*c-m;
        if(r==3&&c==3&&m==1)
        {
            printf("c..\n...\n..*\n");
            continue;
        }
        if(m==1&&(r==2||c==2))
        {
            puts("Impossible");
            continue;
        }
        if(q==2)
        {
            puts("Impossible");
            continue;
        }
        if(q==1)
        {
            putchar('c');
            for(int i=1; i<c; ++i)
                putchar('*');
            puts("");
            for(int i=1; i<r; ++i)
            {
                for(int j=0; j<c; ++j)
                    putchar('*');
                puts("");
            }
            continue;
        }
        if(q<9&&q&1)
        {
            puts("Impossible");
            continue;
        }
        memset(a,0,sizeof(a));
        int te=min(q/2,c);
        a[0]=a[1]=te;
        q-=te*2;
        if(q==1)
        {
            a[0]--,a[1]--;
            a[2]+=3;
        }
        else
        {
            int j=2;
            while(q)
            {
                if(q==1)
                {
                    a[j]--,a[j+1]+=2;
                    q--;
                    //printf("%d\n",j);
                }
                if(a[j]<c)
                {
                    if(q<=c-a[j])
                        a[j]+=q,q=0;
                    else q-=c-a[j],a[j]=c;
                }
                else j++;
            }
        }
        putchar('c');
        int i=1;
        for(; i<a[0]; ++i)
            putchar('.');
        for(; i<c; ++i)
            putchar('*');
        puts("");
        for(i=1; i<r; ++i)
        {
            int j;
            for(j=0; j<a[i]; ++j)
                putchar('.');
            for(; j<c; ++j)
                putchar('*');
            puts("");
        }
    }
}
