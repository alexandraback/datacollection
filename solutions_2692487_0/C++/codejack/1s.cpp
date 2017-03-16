#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<cstring>
#include<string>
#include<cmath>

using namespace std;
std::vector<long long int> A;//,mote;

long long int MIN(long long int x,long long int y)
{
    if(x<y)
    return x;
    else
    return y;
}
long long int func(long long int x,long long int n,long long int mote)
{
    long long int i,j,k,l;
    if(x>=n)
    return 0;

    if(mote>A[x])
    {
        mote+=A[x];
        return func(x+1,n,mote);
    }
    else
    {
        i=0;
        k=mote;
        while(k<=A[x] && k!=1)
        {
            k=2*k-1;
            i++;
        }
        j=1+func(x+1,n,mote);
        if(k>A[x])
        l=i+func(x+1,n,k+A[x]);
        else
        l=1000000;
        j=MIN(j,l);
        j=MIN(j,n-x);
        return j;
    }
}
int main()
{
    long long int i,j,k,l,t,m,n,T,count;
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    fin>>t;
    T=t;
    while(t--)
    {
        fin>>m>>n;
        //mote=m;
        for(i=1;i<=n;i++)
        {
            fin>>k;
            A.push_back(k);
        }
        sort(A.begin(),A.end());
        count=func(0,n,m);
        fout<<"Case #"<<T-t<<": "<<count<<"\n";
        A.clear();
    }
    return 0;
}
