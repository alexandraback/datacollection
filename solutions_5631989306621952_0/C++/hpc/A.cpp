//GCJ 2016 round1A A
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#define MAXN 1005
using namespace std;
char s[MAXN];
bool v[MAXN];
void solve(int x,int y)
{
    char m=s[x];
    for(int i=x;i<=y;++i)
    {
        if(s[i]>m)
        {
            m=s[i];
        }
    }
    for(int i=y;i>=x;--i)
    {
        if(s[i]==m)
        {
            printf("%c",s[i]);
            v[i]=1;
            y=i;
        }
    }
    if(y!=x)
    {
        solve(x,y-1);
    }
}
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    int Case;
    scanf("%d",&Case);
    for(int t=1;t<=Case;++t)
    {
        scanf("%s",s);
        printf("Case #%d: ",t);
        int len=strlen(s);
        char m=s[0];
        memset(v,0,sizeof(v));
        solve(0,len-1);
        for(int i=0;i<len;++i)
        {
            if(v[i]==0)
                printf("%c",s[i]);
        }
        printf("\n");
    }
    return 0;
}
