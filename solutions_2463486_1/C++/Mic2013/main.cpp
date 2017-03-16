#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#define MAXN 1000
using namespace std;

long long pos[MAXN];
bool judge(long long a,int cnt)
{
    char str[30];
    long long t=sqrt(a);
    if(t*t==a)
    {
        if(t>=1&&t<=9)return true;
        itoa(t,str,10);
        int len=strlen(str);
        for(int i=0;i<len/2;i++)
        {
            if(str[i]!=str[len-1-i])return false;
        }
        return true;
    }
    return false;
}
void pre(int &cnt)
{
    long long i,k,l,m;
    for (i=10; i<=10000005; i++)
    {
        l=i;
        k=i;
        k=k/10;
        while(k>0)
        {
            m=k%10;
            l=l*10+m;
            k=k/10;
        }
        if (judge(l,cnt))pos[cnt++]=l;
    }
}
int main()
{
   //freopen("2.in","r",stdin);
    //freopen("2.out","w",stdout);
    memset(pos,0,sizeof(pos));
    int cas;
    scanf("%d",&cas);
    int cnt=0;
    pre(cnt);
    for(int z=1; z<=cas; z++)
    {
        int res=0;
        long long a,b;
        int st,en;
        scanf("%I64d %I64d",&a,&b);
        printf("Case #%d: ",z);
        if (a<=1&&1<=b)res++;
        if(a<=4&&4<=b)res++;
        if(a<=9&&9<=b)res++;
        for(int i=0;i<cnt;i++)
        {
            if(a<pos[i])
            {
                st=i;
                break;
            }
        }
        for(int i=st;i<cnt;i++)
        {
            if(b<pos[i])
            {
                en=i;
                break;
            }
        }
        if(a==pos[st-1])
        {
            res=res+en-st+1;
        }
        else res=res+en-st;
        printf("%d\n",res);
    }
    return 0;
}
