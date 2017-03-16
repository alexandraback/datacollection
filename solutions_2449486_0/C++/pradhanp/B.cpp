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
typedef vector<VI> VVI;
typedef vector<PL> VP;
typedef vector<ll> VL;
typedef vector<VL> VVL;

int main()
{
  int T;
  cin>>T;
  FO(t,1,T+1)
    {
      int n,m;
      cin>>n>>m;
      VVI inp(n,VI(m,0));
      FOR(i,n)
	FOR(j,m)
	cin>>inp[i][j];
      string ret="YES";
      VI rmax(n,0),cmax(m,0);
      FOR(i,n)
	{
	  FOR(j,m)
	    {
	      rmax[i]=max(rmax[i], inp[i][j]);
	      cmax[j]=max(cmax[j], inp[i][j]);
	    }
	}
      FOR(i,n)
	{
	  FOR(j,m)
	    {
	      if(inp[i][j]!=rmax[i] and inp[i][j]!=cmax[j])
		ret = "NO";
	    }
	}

      printf("Case #%d: %s\n", t, ret.c_str());
    }
  return 0;
}
