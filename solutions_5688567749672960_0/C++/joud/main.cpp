# include <iostream>
# include<algorithm>
#include <stdio.h>
# include <cstdlib>
# include <ios>
# include <vector>
using namespace std;
int ans[1000001];
int revers(int n)
{
    int m=0;
    int digits[30]={0};
    int x=0;
    while(n>0)
    {
        digits[x++]=n%10;
        n/=10;
    }
    if (digits[0]==0)
        return 100000000;
    int i=0;
    for (;i<x;i++)
        m*=10,m+=digits[i];
    return m;
}
int main()
{
   freopen("out.txt","w",stdout);
   int t;
   cin>>t;
   ans[1]=1;
   for (int i=2;i<=1000000;i++)
   {
       int x=revers(i);
       if (x>=i)
        ans[i]=ans[i-1]+1;
       else
        ans[i]=min(ans[i-1]+1,ans[x]+1);
   }
   for (int gogo=1;gogo<=t;gogo++)
   {
       int n;
       cin>>n;
       cout<<"Case #"<<gogo<<": "<<ans[n]<<endl;
   }
}
