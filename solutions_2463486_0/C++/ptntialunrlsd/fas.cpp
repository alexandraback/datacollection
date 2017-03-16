#include<iostream>
#include<map>
#include<fstream>
#include<vector>
#include<cmath>
#include<sstream>
#define L long long int

using namespace std;

bool persqr(L n)
{
    L sqr = sqrt(n);
    if(sqr*sqr==n)
        return true;
    else
        return false;
}

bool ispalin(L n)
{
    stringstream ss;
    string ns;

    ss<<n;
    ss>>ns;

    int size = ns.size();
    int i,j;

    for(i=0,j=size-1;i<size/2;i++,j--)
        if(ns[i]!=ns[j])
            break;

    if(i<size/2)
        return false;
    else
        return true;

}

L cuml[10000007],cumh[10000007];

int main()
{
        ifstream cin("input");
        ofstream cout("output");

        L i,a,b,ans;
        int t,k;

        for(i=1;i<=10000000;i++)
        {
            if(persqr(i))
            {
                if(ispalin(i)&&ispalin(sqrt(i)))
                    cuml[i]=1;
            }
        }
        for(i=sqrt(10000001);i<=10000000;i++)
        {
            if(i*i<=10000000)
                continue;

            if(ispalin(i)&&ispalin(i*i))
                cumh[i]=1;
        }

        for(i=2;i<=10000000;i++)
        {
            cuml[i]+=cuml[i-1];
            cumh[i]+=cumh[i-1];
        }

        cin>>t;

        for(k=1;k<=t;k++)
        {
            cin>>a>>b;

            ans=0;
            if(b>10000000)
            {
                ans+=cumh[(int)sqrt(b)];
                ans+=cuml[10000000];
            }
            else
            {
                ans+=cuml[b];
            }

            if(a>10000000)
            {
                ans-=cuml[10000000];
                ans-=cumh[(int)sqrt(a-1)];
            }
            else
            {
                ans-=cuml[a-1];
            }

            cout<<"Case #"<<k<<": "<<ans<<"\n";
        }

        return 0;
}


