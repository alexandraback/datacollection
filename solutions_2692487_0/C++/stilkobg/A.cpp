#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int t,T;
long long A,n,a[128],bans=-1;
void print(int x,long long ans)
{
    printf("Case #%d: %I64d\n",x,ans);
}
void solve(int i,long long x,long long br)
{
    if(i==n)
    {
       // cout<<br<<' '<<bans<<endl;
        if(bans==-1||br<bans)bans=br;
        return ;
    }
    if(x>a[i])solve(i+1,x+a[i],br);
    else
    {
        solve(i+1,x,br+1);
        long long p=x,bt=br;
        while(p<=a[i])
        {
            p=p+p-1;
            bt++;
        }
        p+=a[i];
        solve(i+1,p,bt);
    }
}
int main()
{
    scanf("%d",&T);
    while(t++<T)
    {
        scanf("%I64d%d",&A,&n);
        int i;
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        i=0;
        long long br=0;
        while(a[i]<A&&i<n)
        {
            A+=a[i];
            i++;
        }
        if(i==n)
        {
                print(t,br);
                continue ;
        }
        if(A==1){print(t,n);continue ;}
        int ti=i;
        bans=-1;
        solve(ti,A,0);
       // cout<<endl<<bans<<endl;
        print(t,bans);
    }
    return 0;
}
