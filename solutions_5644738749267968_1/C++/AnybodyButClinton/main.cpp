#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream in("D-large.in");
ofstream out("output.out");

int t,n;
double bn[1000],bk[1000];

void scan()
{
    in>>n;
    for(int i=0;i<n;i++)in>>bn[i];
    for(int i=0;i<n;i++)in>>bk[i];
}

int maximum()
{
    int maxi=n;
    sort(bn,bn+n);
    sort(bk,bk+n);
    bool fn[n];
    for(int i=0;i<n;i++)fn[i]=0;
    for(int j=0;j<n;j++)
    {
        double maxin=-1;
        int maxip;
        for(int i=0;i<n;i++)if(!fn[i]&&bn[i]>maxin){maxin=bn[i];maxip=i;}
        double minin=2;
        int minip;
        for(int i=0;i<n;i++)if(!fn[i]&&bn[i]<minin){minin=bn[i];minip=i;}
        if(bk[j]>maxin)
        {
            fn[minip]=1;
            maxi--;
        }
        else
        {
            int key;
            for(int i=0;i<n;i++)
            {
                key=i;
                if(bk[j]<bn[i]&&!fn[i])break;
            }
            fn[key]=1;
            //cout<<bk[key]<<endl;
        }
    }
    return maxi;
}

int minimum()
{
    int mini=0;
    sort(bn,bn+n);
    sort(bk,bk+n);
    bool fk[n];
    for(int i=0;i<n;i++)fk[i]=0;
    for(int j=0;j<n;j++)
    {
        double maxik=-1;
        int maxip;
        for(int i=0;i<n;i++)if(!fk[i]&&bk[i]>maxik){maxik=bk[i];maxip=i;}
        double minik=2;
        int minip;
        for(int i=0;i<n;i++)if(!fk[i]&&bk[i]<minik){minik=bk[i];minip=i;}
        if(bn[j]>maxik)
        {
            fk[minip]=1;
            mini++;
        }
        else
        {
            int key;
            for(int i=0;i<n;i++)
            {
                key=i;
                if(bn[j]<bk[i]&&!fk[i])break;
            }
            fk[key]=1;
            //cout<<bk[key]<<endl;
        }
    }
    return mini;
}

void print(int t)
{
    out<<"Case #"<<t<<": "<<maximum()<<" "<<minimum()<<endl;
}

int main()
{
    in>>t;
    for(int i=0;i<t;i++)
    {
        scan();
        print(i+1);
    }
    return 0;
}
