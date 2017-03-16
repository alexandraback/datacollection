#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<stdio.h>
#define N 100000
using namespace std;

int n,i,j,k,m,sum,time,tt,A,B;
double p[N],pre[N],ans,tmp;

FILE *in,*out;

int main()
{
    in=freopen("A-large.in","r",stdin);
    out=freopen("output-large.txt","w",stdout);
    cin>>tt;
    time=1;
    while (time<=tt)
    {
        memset(p,0,sizeof(p));
        memset(pre,0,sizeof(pre));
        cin>>A>>B;
        for (i=0;i<A;i++)
        {
            cin>>p[i];
        }
        pre[0]=1;
        for (i=1;i<=A;i++)
            pre[i]=pre[i-1]*p[i-1];
        ans=B+2;
        for (n=0;n<=A;n++)
        {
            tmp=pre[A-n]*(B-A+2*n+1)+(1-pre[A-n])*(2*B+2-A+2*n);
            if (tmp<ans)
                ans=tmp;
            //cout<<tmp<<endl;
        }
        printf("Case #%d: %.6f\n",time,ans);
        time++;
    }
    return 0;
}
