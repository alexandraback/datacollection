#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define N 120
using namespace std;
long long a2[N],a1[N],b2[N],b1[N],d[N][N];
long long m,n;
int main()
{
    freopen("C-small-attempt1.in","r",stdin);
    freopen("2.txt","w",stdout);
    long long T,id=1;
    cin>>T;
    while(T--)
    {
        cin>>m>>n;
        for(long long i=1; i<=m; i++)
            cin>>a1[i]>>a2[i];
        for(long long i=1; i<=n; i++)
                cin>>b1[i]>>b2[i];
        long long mm=0;
        if(m==3)
        {
            for(long long i=0; i<=n; i++)
            {
                long long s=0;
                for(long long a=1; a<=i; a++)
                    if(a2[1]==b2[a])s+=b1[a];
                long long m1=min(s,a1[1]),m2,m3;
                for(long long j=i; j<=n; j++)
                {
                    s=0;
                    for(long long a=i; a<=j; a++)
                        if(a2[2]==b2[a])s+=b1[a];
                    m2=min(s,a1[2]);
                    s=0;
                    for(long long a=j; a<=n; a++)
                        if(a2[3]==b2[a])s+=b1[a];
                    m3=min(s,a1[3]);
                    mm=max(mm,m1+m2+m3);
                }
            }
        }
        else if(m==2)
        {
            for(long long i=0; i<=n; i++)
            {
                long long s=0;
                for(long long a=1; a<=i; a++)
                    if(a2[1]==b2[a])s+=b1[a];
                long long m1=min(s,a1[1]),m2,m3;
                for(long long j=i; j<=n; j++)
                {
                    s=0;
                    for(long long a=i; a<=j; a++)
                        if(a2[2]==b2[a])s+=b1[a];
                    m2=min(s,a1[2]);
                    mm=max(m1+m2,mm);
                }
            }
        }
        else
        {
            for(long long i=0; i<=n; i++)
            {
                long long s=0;
                for(long long a=1; a<=i; a++)
                    if(a2[1]==b2[a])s+=b1[a];
                long long m1=min(s,a1[1]);
                mm=max(m1,mm);
            }
        }
        cout<<"Case #"<<id++<<": ";
        cout<<mm<<endl;
    }
    return 0;
}
