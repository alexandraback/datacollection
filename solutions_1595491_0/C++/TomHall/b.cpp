#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;

int t[100],i,j,k,n,s,p,tt,time,stat[100];
FILE *in,*out;

int mn(int a,int b)
{
    return a>b?b:a;
}

int getstatus(int n,int p)
{
    if (n==0 && p==0)
        return 1;
    if(n==0 && p>0)
        return 3;
    if (n%3==0)
    {
        if (n/3>=p)
            return 1;//solid
        if (n/3+1<p)
            return 3;//impossible
        return 2;//possible
    }
    if (n%3==1)
    {
        if (n/3+1>=p)
            return 1;
        return 3;
    }
    if (n/3+1>=p)
        return 1;//possible
    if (n/3+2==p)
        return 2;
    return 3;
}

int main()
{
    in=freopen("B-small.in","r",stdin);
    out=freopen("output.txt","w",stdout);
    cin>>tt;
    time=0;
    while (time<tt)
    {
        cin>>n>>s>>p;
        memset(stat,0,sizeof(stat));
        for (i=0;i<n;i++)
        {
            cin>>t[i];
            stat[getstatus(t[i],p)]++;
        }
        cout<<"Case #"<<time+1<<": "<<stat[1]+mn(stat[2],s)<<endl;


        time++;
    }
    return 0;
}
