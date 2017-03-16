//kopyh
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define N 1123456
using namespace std;
int n,m,sum,res,flag;
char s[N];
int a[200];
int b[10];
int main()
{
    int i,j,k,cas,T,t,x,y,z;
    scanf("%d",&T);
    cas=0;
    while(T--)
//    while(scanf("%d",&n)!=EOF)
    {
        scanf("%s",s);
        n=strlen(s);
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for(i=0;i<n;i++)
            a[s[i]]++;
        m=0;
        if(a['Z']>0)
        {
            t=a['Z'];
            b[0]+=t;
            a['Z']-=t;
            a['E']-=t;
            a['R']-=t;
            a['O']-=t;
        }
        if(a['W']>0)
        {
            t=a['W'];
            b[2]+=t;
            a['W']-=t;
            a['T']-=t;
            a['O']-=t;
        }
        if(a['X']>0)
        {
            t=a['X'];
            b[6]+=t;
            a['S']-=t;
            a['X']-=t;
            a['I']-=t;
        }
        if(a['U']>0)
        {
            t=a['U'];
            b[4]+=t;
            a['U']-=t;
            a['F']-=t;
            a['R']-=t;
            a['O']-=t;
        }
        if(a['G']>0)
        {
            t=a['G'];
            b[8]+=t;
            a['E']-=t;
            a['I']-=t;
            a['G']-=t;
            a['H']-=t;
            a['T']-=t;
        }
        if(a['H']>0)
        {
            t=a['H'];
            b[3]+=t;
            a['T']-=t;
            a['H']-=t;
            a['R']-=t;
            a['E']-=t;
            a['E']-=t;
        }
        if(a['F']>0)
        {
            t=a['F'];
            b[5]+=t;
            a['F']-=t;
            a['I']-=t;
            a['V']-=t;
            a['E']-=t;
        }
        if(a['V']>0)
        {
            t=a['V'];
            b[7]+=t;
            a['S']-=t;
            a['E']-=t;
            a['V']-=t;
            a['E']-=t;
            a['N']-=t;
        }
        if(a['O']>0)
        {
            t=a['O'];
            b[1]+=t;
            a['O']-=t;
            a['N']-=t;
            a['E']-=t;
        }
        if(a['I']>0)
        {
            t=a['I'];
            b[9]+=t;
            a['N']-=t;
            a['I']-=t;
            a['N']-=t;
            a['E']-=t;
        }
        printf("Case #%d: ",++cas);
        for(i=0;i<=9;i++)
            for(j=0;j<b[i];j++)printf("%d",i);
        printf("\n");
    }
    return 0;
}
