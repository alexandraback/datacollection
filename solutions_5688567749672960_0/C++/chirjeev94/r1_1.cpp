#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<string.h>
#include<queue>
#define M 1000000007
using namespace std;
long long dp[1000010];
long long rev(long long num)
{
    long long rev_num=0,k;
    while(num!=0)
    {
        k=num%10;
        rev_num=rev_num*10+k;
        num/=10;

    }
    return rev_num;
}
long long ans(long long curr,long long n)
{
    if(dp[curr]!=0)
    return dp[curr];
    long long i,j;
    if(curr==n)
    return 1;
    if(rev(curr)>curr+1&&rev(curr)<=n)
    i=ans(rev(curr),n)+1;
    else
    i=n;

    j=ans(curr+1,n)+1;
    dp[curr]=min(i,j);
    return min(i,j);


}
main()
{
    freopen("input.in","r",stdin);
    freopen("out.txt","w",stdout);
    long long int i,j,k,n,m,standing=0,ans1=0,t,q;
    string s;
    cin>>t;
    for(q=1;q<=t;q++)
    {
        //memset(dp,sizeof(dp),0);
        cin>>n;
        for(i=0;i<=n;i++)
        dp[i]=0;
        ans1=ans(1,n);

   cout<<"Case #"<<q<<": "<<ans1<<endl;
    }
    return 0;
}

