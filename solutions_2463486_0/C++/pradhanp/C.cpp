#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

#define FOR(i,n) for(int i=0;i<n;i++)
#define FOX(i,x) for(int i=0;i<x.size();i++)
#define FO(i,j,n) for(int i=j;i<n;i++)

typedef long long ll;
typedef long double ld;

#define X first
#define Y second
#define PB push_back
#define S(x) sort(x.begin(), x.end())
#define R(x) reverse(x.begin(), x.end())

typedef pair<ll,ll> PL;
typedef vector<int> VI;
typedef vector<PL> VP;
typedef vector<ll> VL;
typedef vector<VL> VVL;

VL fair;

int cnt(ll a)
{
  if(fair.back()<=a)
    return fair.size();
  if(a<fair[0])
    return 0;
  int lo=0,hi=(fair.size())-1;
  while(hi-lo>1)
    {
      int d=(hi+lo)/2;
      if(fair[d]>a)
	hi=d;
      else
	lo=d;
    }
  //  cout<<"Fair size "<<fair.size()<<endl;
  //  cout<<"Cnt "<<a<<" "<<hi<<endl;
  return hi;
}

bool palin(ll a)
{
  VI digits;
  while(a)
    {
      digits.push_back(a%10);
      a/=10;
    }
  VI rd=digits;
  R(rd);
  return (rd==digits);
}

void check(ll a)
{
  if(palin(a) and palin(a*a))
    {
      fair.push_back(a*a);
      //      cout<<"Fair "<<a*a<<endl;
    }

}

int main()
{
  int up = (int)(1e7);
  FO(i,1,up)
    {
      check((ll)i);
    }
  int T;
  cin>>T;
  FO(t,1,T+1)
    {
      ll a,b;
      cin>>a>>b;
      printf("Case #%d: %d\n", t, cnt(b)-cnt(a-1));
    }
  return 0;
}
