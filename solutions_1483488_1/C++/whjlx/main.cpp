#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define MaxN 2000000

int father[MaxN+55];

bool visit[MaxN+55];

int find(int x)
{
    if(x==father[x]) return x;
    return father[x]=find(father[x]);
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
void initialize()
{
    int num1,num2;
    for(int i=0;i<=MaxN;i++) father[i]=i;
    memset(visit,0,sizeof(visit));
    for(int i=1;i<=MaxN;i++)
    {
        if(!visit[i])
        {
            num1=i;
            while(!visit[num1])
            {
                visit[num1]=1;
                num2=getnext(num1);
                while(num2>MaxN)
                {
                    num2=getnext(num2);
                }
                father[find(num1)]=find(num2);
                num1=num2;
            }
        }
    }
}

int S[MaxN+10];
long long getsum(int i)
{
    return ((long long)S[i]*(S[i]-1))>>1;
}
int main()
{
   // freopen("C-large.in","r",stdin);
   // freopen("out","w",stdout);
    int T,A,B;
    long long ans;
    initialize();
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        scanf("%d%d",&A,&B);
        memset(S,0,sizeof(S));
        for(int i=A;i<=B;i++)
        {
            S[find(i)]++;
        }
        ans=0;
        for(int i=1;i<=MaxN;i++)
        {
            ans+=getsum(i);
        }
        printf("Case #%d: %lld\n",cas,ans);
    }
    return 0;
}


