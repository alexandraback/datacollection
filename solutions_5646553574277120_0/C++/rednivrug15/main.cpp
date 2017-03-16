/*Author:rednivrug15*/
#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define ll long long
#define MOD 1000000007

long long power(long long a,long long b,long long mod)
{
    long long ret=1;

    while(b)
    {
        if(b%2==1)
            ret=(ret*a)%mod;
        b/=2;
        a=(a*a)%mod;
    }
    return ret;
}

int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}

int hashe[10001];

int main()
{
    freopen("inp.txt","r",stdin);
    freopen("op.txt","w",stdout);
    int t;
    scanf("%d",&t);

    for(int kase=1; kase<=t; kase++)
    {
       printf("Case #%d: ",kase);

       int c,d,v;
       cin>>c>>d>>v;

       memset(hashe,0,sizeof hashe);
       int arr[d];
       for(int i=0; i<d; i++)
        cin>>arr[i];

       for(int i=1; i<(1<<d); i++)
       {
           int sum=0;
           for(int j=0; j<d; j++)
           {
               if((i&(1<<j)))
                sum+=arr[j];
           }
           if(sum<=v)
            hashe[sum]=1;
       }

       int ans=0;
       for(int i=1; i<=v; i++)
       {
           if(hashe[i]==0)
           {
               ans++;
               hashe[i]=1;
               for(int j=v; j>=1; j--)
               {
                   if(hashe[j]==1 && i!=j && i+j<=v)
                   {
                       hashe[i+j]=1;
                   }
               }
           }
       }
       printf("%d\n",ans);
    }
    return 0;
}
