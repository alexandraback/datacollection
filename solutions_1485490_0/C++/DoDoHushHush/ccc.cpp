#include<iostream>
#include<cstring>
using namespace std;
long long x[1010][1010];
long long n,m;

long long a[101];
long long at[101];
long long b[101];
long long bt[101];
long long ddd(long long ai,long long bi,long long ax,long long bx)
{
    if(ai>n||bi>m)return 0;
    if(at[ai]!=bt[bi])
    {
        return max(ddd(ai+1,bi,a[ai+1],bx),ddd(ai,bi+1,ax,b[bi+1]));
    }
    else
    {
        if(ax==bx)return ax+ddd(ai+1,bi+1,a[ai+1],b[bi+1]);
        else if(ax<bx)return ax+ddd(ai+1,bi,a[ai+1],bx-ax);
        else return bx+ddd(ai,bi+1,ax-bx,b[bi+1]);
    }
}
int main()
{
long long t;
cin>>t;
for(long long i=1;i<=t;i++)
{
    cin>>n>>m;
    for(long long i=1;i<=n;i++)cin>>a[i]>>at[i];
    for(long long i=1;i<=m;i++)cin>>b[i]>>bt[i];
    long long an=ddd(1,1,a[1],b[1]);
    cout<<"Case #"<<i<<": "<<an<<endl;
}
return 0;
}
