#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<stdio.h>
#define N 1000010
#define lp(i,n) for(i=0;i<n;i++)
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;

int n,i,j,k,sum,tmp,ans,m,e,r,tt,time;
int v[100000]={0};
int a[N];
char s[N];
bool flag;

FILE *in,*out;

int dfs(int i,int values,int E)
{
    if (i==n+1)
        return(values);
    int ee,ans=0,k=0;
    k=min(max(E+r-e,0),e);
    for (ee=k;ee<=E;ee++)
    {
        ans=max(ans,dfs(i+1,values+ee*v[i],min(E-ee+r,e)));
    }
    return(ans);
}

int main()
{
    in=freopen("B-small-attempt1.in","r",stdin);
    //in=freopen("B-small.in","r",stdin);
    out=freopen("B-small-attempt1.out","w",stdout);
    cin>>tt;
    for (time=1;time<=tt;time++)
    {
        cin>>e>>r>>n;
        for (i=1;i<=n;i++)
            cin>>v[i];
        ans=dfs(1,0,e);
        cout<<"Case #"<<time<<": "<<ans<<endl;
    }
    return 0;
}

