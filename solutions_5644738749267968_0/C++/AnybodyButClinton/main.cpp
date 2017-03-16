#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;
//D-small-attempt0
ifstream in("D-small-attempt1.in");
ofstream out("output.out");

int t,n;
double bn[10],bk[10];

void scan()
{
    in>>n;
    for(int i=0;i<n;i++)in>>bn[i];
    for(int i=0;i<n;i++)in>>bk[i];
}

int count(double *a,double *b)
{
    int ans=0;
    for(int i=0;i<n;i++)if(a[i]>b[i])ans++;
    return ans;
}

bool is_sorted(double *a)
{
    for(int i=1;i<n;i++)
    {
        if(a[i-1]>a[i])return 0;
    }
    return 1;
}

int maximum()
{
    int maxi=0;
    sort(bn,bn+n);
    sort(bk,bk+n);
    if(count(bn,bk)>maxi)maxi=count(bn,bk);
    next_permutation(bk,bk+n);
    while(!is_sorted(bk))
    {
        if(count(bn,bk)>maxi)maxi=count(bn,bk);
        next_permutation(bk,bk+n);
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
