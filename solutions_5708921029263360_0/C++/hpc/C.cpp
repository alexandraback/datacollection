//GCJ 2016 round1C C
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#define MAXN 30
using namespace std;
int J,P,S,K;
map<string,int>m;
char c[5];
int num;
void solve2()
{
    for(int i=0;i<5;++i)
        c[i]='0';
    for(int i=1;i<=J;++i)
    {
        c[0]='0'+i;
        for(int j=1;j<=P;++j)
        {
            c[2]='0'+j;
            for(int k=1;k<=S;++k)
            {
                c[4]='0';
                if(m[c]>=K) continue;
                c[4]='0'+k;
                c[2]='0';
                if(m[c]>=K) continue;
                c[2]='0'+j;
                c[0]='0';
                if(m[c]>=K) continue;
                m[c]++;
                c[0]='0'+i;
                c[2]='0';
                m[c]++;
                c[2]='0'+j;
                c[4]='0';
                m[c]++;
                c[4]='0'+k;
                c[0]='0'+i;
                c[2]='0'+j;
                for(int x=0;x<5;++x)
                {
                    if(x==1||x==3) printf(" ");
                    else printf("%c",c[x]);
                }
                printf("\n");
            }
        }
    }
}
void solve1()
{
    num=0;
    for(int i=0;i<5;++i)
        c[i]='0';
    for(int i=1;i<=J;++i)
    {
        c[0]='0'+i;
        for(int j=1;j<=P;++j)
        {
            c[2]='0'+j;
            for(int k=1;k<=S;++k)
            {
                c[4]='0';
                if(m[c]>=K) continue;
                c[4]='0'+k;
                c[2]='0';
                if(m[c]>=K) continue;
                c[2]='0'+j;
                c[0]='0';
                if(m[c]>=K) continue;
                m[c]++;
                c[0]='0'+i;
                c[2]='0';
                m[c]++;
                c[2]='0'+j;
                c[4]='0';
                m[c]++;
                c[4]='0'+k;
                c[0]='0'+i;
                c[2]='0'+j;
                num++;
            }
        }
    }
    printf("%d\n",num);
}
int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-attempt0.out","w",stdout);
    int Case;
    scanf("%d",&Case);
    for(int t=1;t<=Case;++t)
    {
        scanf("%d%d%d%d",&J,&P,&S,&K);
        m.clear();
        printf("Case #%d: ",t);
        solve1();
        m.clear();
        solve2();

    }
    return 0;
}
