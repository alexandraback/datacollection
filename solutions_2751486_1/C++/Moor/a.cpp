#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 1000010
using namespace std;
int ty[300];
char str[MAXN];
int main()
{
    freopen("/home/moor/下载/A-large.in","r",stdin);
    freopen("/home/moor/Code/output.txt","w",stdout);
    int ncase,prev,n,pp;
    long long sum;
    scanf("%d",&ncase);
    memset(ty,0,sizeof(ty));
    ty['a']=ty['e']=ty['i']=ty['o']=ty['u']=1;
    for(int h=1;h<=ncase;++h)
    {
        scanf("%s%d",str,&n);
        prev=-1;
        pp=-1;
        sum=0;
        for(int i=0;str[i];++i)
            if(!ty[str[i]])
            {
                if(prev==-1)    prev=i;
                if(i-prev+1>=n)
                    sum+=i-n+2,pp=i-n+2;
                else    if(pp!=-1)
                    sum+=pp;
            }
            else
            {
                if(pp!=-1)  sum+=pp;
                prev=-1;
            }

        printf("Case #%d: ",h);
        cout<<sum<<'\n';
    }
}
