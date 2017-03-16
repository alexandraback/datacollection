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
  ll t,i,j,k;
  char s[2000+4];
  scanf("%lld",&t);

  for(i=0;i<t;i++)
  {
    scanf("%s",s);
    ll len=strlen(s);
     char max='0';
     string str;
    for(j=0;j<len;j++)
    {
      if(s[j]>=max)
      {
        max=s[j];
        str=s[j]+str;
      }
      else
      {
        str=str+s[j];
      }
    }
    cout<<"Case #"<<i+1<<": "<<str<<endl;
  }
  return 0;
}
