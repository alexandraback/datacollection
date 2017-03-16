#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<ll>
#define pp pair<ll,ll>
#define mp make_pair
#define pb push_back
#define s1(x) scanf("%lld",&x)
#define s2(x,y) scanf("%lld",&x,&y)
#define s3(x,y,z) scanf("%lld",&x,&y,&z)
#define pf(x) printf("%lld\n",x)
#define FOR(x,y) for(x=0;x<y;x++)
#define M 1000000007
#define MAX 100000
vector<pair<ll,ll> > tree(4*MAX+6);

int main()
{
  ll t,i,j,k,n,x;
  scanf("%lld",&t);

  for(i=0;i<t;i++)
  {
    ll hash[2500+4]={0};
     vi v;
     scanf("%lld",&n);
     ll maxx=-1;
     for(k=0;k<2*n-1;k++)
     {
       for(j=0;j<n;j++)
       {
         scanf("%lld",&x);
         hash[x]++;
          maxx=max(maxx,x);
       }
     }
     for(j=1;j<=maxx;j++)
     {
       if(hash[j]%2==1)
        v.pb(j);
     }
     sort(v.begin(),v.end());
     printf("Case #%lld: ",i+1);
     for(j=0;j<n;j++)
     {
       printf("%lld ",v[j]);
     }
     printf("\n");
  }
  return 0;
}
