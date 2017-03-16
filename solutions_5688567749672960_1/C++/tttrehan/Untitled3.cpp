#include<bits/stdc++.h>

using namespace std;

long long minimum(int n)
{
    if(n==0)
    {
        return 0;
    }
    if(n==1)
    {
        return 0;
    }
    if(n==2)
    {
        return 10;
    }
    if(n>=3)
    {
        long long ans=10;
        ans=ans+(n-2)*9;
        for(int i=1;i<=n-2;i++)
        {
            ans=ans+pow(10,i);
        }
        return ans;
    }
}
 
long long fuckit(long long n,int len, int most)
{
    long long ans=n- most*(pow(10,len-1));
    return ans;
}
 int findlength(long long n)      
{
    if(n==0)
    {
        return 0;
    }
    int ans=0;
    while(n>0)
    {
        n/=10;
        ans+=1;
    }
    return ans;
}
 

 
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t, z;
    scanf("%d",&t);
    for (z=1;z<=t;z++)
    {
        long long ans;
        long long n;
        scanf("%lld",&n);
        int len=findlength(n);
        long long lol=minimum(len);
 
        int sign=n/pow(10, len-1);
        long long  last=fuckit(n, len,sign);
 
        if (n<=10)
        {
            ans=n;
        }
       else if(sign==1)
        {
            ans=lol+last;
        }
         else if(sign!=1)
        {
            ans=lol+sign+last;
        }
        printf("Case #%d: %lld\n",z,ans);
    }
    return 0;
}

