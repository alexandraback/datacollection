#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;

int t,a,b,i,sum,orinum,nextnum,diff;
bool used[10000010];
FILE *in,*out;

int getdigit(int n)
{
    if (n<10)
        return 1;
    if (n<100)
        return 2;
    if (n<1000)
        return 3;
    if (n<10000)
        return 4;
    if (n<100000)
        return 5;
    if (n<1000000)
        return 6;
    return 7;
}

int getzero(int n)
{
    int m=n;
    int countzero=0;
    while (m>9)
    {
        if (m%10==0)
            countzero++;
        m=m/10;
    }
    return countzero;
}

int po(int m,int p)
{
    int s=1;
    while (p>0)
    {
        s=s*m;
        p--;
    }
    return s;
}

int next(int n,int k)
{
    int m=n%10;
    n/=10;
    n=n+po(10,k-1)*m;
    return n;
}


int main()
{
    in=freopen("C-small.in","r",stdin);
    out=freopen("output.txt","w",stdout);
    cin>>t;
    int tt=0;
    while (tt<t)
    {
        cin>>a>>b;
        memset(used,0,sizeof(used));
        sum=0;
        for (i=a;i<=b;i++)
        {
            if (!used[i])
            {
                used[i]=true;
                orinum=getdigit(i);
                nextnum=next(i,orinum);
                diff=1;
                while (!used[nextnum])
                {
                    if (getdigit(nextnum)==orinum)
                        used[nextnum]=true;
                    if (!(nextnum>b || nextnum<a))
                        diff++;
                    nextnum=next(nextnum,orinum);
                }
                sum+=diff*(diff-1)/2;
            }
        }
        cout<<"Case #"<<tt+1<<": "<<sum<<endl;
        tt++;
    }
    return 0;
}
