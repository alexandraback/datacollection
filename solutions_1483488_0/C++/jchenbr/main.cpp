#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
int f[2000000+5];
int ans;

void push(int now)
{
    int a[10],t=0,tmp=now;
    while (tmp)
        a[t++]=tmp%10,tmp/=10;
    int ret=now;
    //for (int i=0;i<t;i++)printf("%d ",a[i]);printf("\n");
    for (int i=0;i<t;i++)
    {
        if (a[i]==0)continue;
        tmp=0;
        for (int j=i;j>=0;j--)tmp=tmp*10+a[j];
        for (int j=t-1;j>i;j--)tmp=tmp*10+a[j];
        ret=min(ret,tmp);
    }
    ans+=f[ret];
    //printf("{%d %d }\n",now,ret,f[ret]);
    f[ret]++;
}

int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-attempt0.out","w",stdout);
    int total,l,r,cc=0;
    cin>>total;
    while (total--)
    {
        ans=0;
        cin>>l>>r;
        memset(f+1,0,sizeof(int)*r);
        //printf("%d %d\n",l,r);
        for (int i=l;i<=r;i++)
            push(i);
        printf("Case #%d: %d\n",++cc,ans);
    }
}