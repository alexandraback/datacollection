#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<vector>
#include<iostream>
#include<string>
#include<string.h>
using namespace std;
char stra[100],strb[100];
int a[100],b[100];
void out(long long x,int n)
{
    int temp[100];
    for(int i=0;i<n;++i)
        temp[i]=x%10,x/=10;
    for(int i=n-1;i>=0;--i)
        putchar('0'+temp[i]);
}
int main()
{
    freopen("B-small-attempt0 (2).in","r",stdin);
    freopen("1.out","w",stdout);
    int ca=0;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s%s",stra,strb);
        int n=strlen(stra);
        a[0]=a[1]=a[2]=0;
        b[0]=b[1]=b[2]=0;
        int p=3-n;
        for(int i=0; i<n; ++i)
        {
            a[i+p]=(stra[i]=='?'?-1:stra[i]-'0');
            b[i+p]=(strb[i]=='?'?-1:strb[i]-'0');
        }
        int ansa=0,ansb=0,mi=999;
        for(int i=0; i<=999; ++i)
        {
            if(a[0]!=-1&&i/100!=a[0])
                continue;
            if(a[1]!=-1&&i%100/10!=a[1])
                continue;
            if(a[2]!=-1&&i%10!=a[2])
                continue;
            for(int j=0; j<=999; ++j)
            {
                if(b[0]!=-1&&j/100!=b[0])
                    continue;
                if(b[1]!=-1&&j%100/10!=b[1])
                    continue;
                if(b[2]!=-1&&j%10!=b[2])
                    continue;
                if(mi>abs(i-j))
                    mi=abs(i-j),ansa=i,ansb=j;
            }
        }
        printf("Case #%d: ",++ca);
        out(ansa,n);
        putchar(' ');
        out(ansb,n);
        puts("");
    }
}
