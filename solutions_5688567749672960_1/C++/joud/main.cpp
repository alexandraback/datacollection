# include <iostream>
# include<algorithm>
#include <stdio.h>
# include <cstdlib>
# include <ios>
# include <vector>
using namespace std;
long long digits[100];
long long next;
long long get(long long m)
{
    long long j=0;
    while(m>0)
    {
        digits[j++]=m%10;
        m/=10;
    }
    long long ret=0;
    long long cur=1;
    for (long long i=0;i<j-1;i++)
    {
        ret+=digits[i]*cur;
        cur*=10;
    }
    ret+=(digits[j-1]-1)*cur;
    ret++;
    return ret;
}
long long flip(long long n)
{
    long long m=n;
    long long j=0;
    while(n>0)
    {
        digits[j++]=n%10;
        n/=10;
    }
    long long x=j/2;
    long long cur=1;
    long long ret=0;
    for (long long i=0;i<x;i++)
    {
        ret+=digits[i]*cur;
        cur*=10;
    }
    cur=1;
    for (long long i=j-1;i>=x;i--)
    {
        ret+=digits[i]*cur;
        cur*=10;
    }
    if (get(m)>ret)
        ret++;
    next=0;
    for (long long i=0;i<j-1;i++)
    {
        next*=10;
        next+=9;
    }
    return ret;
}
long long solve(long long n)
{
    if (n<=1)
        return n;

    long long k=0;
    if (n%10==0)
        k++,n--;
    long long h=flip(n);
    return min(n,solve(next)+h)+k;
}
int main()
{
   freopen("out1.txt","w",stdout);
   long long t;
   cin>>t;

   for (long long gogo=1;gogo<=t;gogo++)
   {
        long long n;
        cin>>n;
       cout<<"Case #"<<gogo<<": "<<solve(n)<<endl;
   }
}
