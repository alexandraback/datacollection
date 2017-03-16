#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
#define MAXNUM 2000000

int rot[MAXNUM+10];

bool used[MAXNUM+10];

int findroot(int x)
{
    if(x==rot[x]) return x;
    return rot[x]=findroot(rot[x]);
}
void COM(int x,int y)
{
    rot[findroot(x)]=findroot(y);
    return ;
}
int getnext(int x)
{
    if(x==0) return 0;
    int a,b,n=1;
    a=x;
    while(a)
    {
        a/=10;
        n*=10;
    }
    n/=10;
    b=0;
    while(b==0)
    {
        b=x%10;
        x/=10;
    }
    return n*b+x;
}
void init()
{
    int num1,num2;
    for(int i=0;i<=MAXNUM;i++) rot[i]=i;
    memset(used,0,sizeof(used));
    for(int i=1;i<=MAXNUM;i++)
    {
        if(!used[i])
        {
            num1=i;
            while(!used[num1])
            {
                used[num1]=1;
                num2=getnext(num1);
                while(num2>MAXNUM) num2=getnext(num2);
                COM(num1,num2);
                num1=num2;
            }
        }
    }
}

int sum[MAXNUM+10];

int main()
{
    //freopen("C-small-attempt1.in","r",stdin);
    //freopen("out","w",stdout);
    int T,A,B;
    long long ANS;
    init();
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        scanf("%d%d",&A,&B);
        memset(sum,0,sizeof(sum));
        for(int i=A;i<=B;i++)
        {
            sum[findroot(i)]++;
        }
        ANS=0;
        for(int i=1;i<=MAXNUM;i++)
        {
            ANS+=((long long)sum[i]*(sum[i]-1))>>1;
        }
        printf("Case #%d: %lld\n",cas,ANS);
    }
    return 0;
}
