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

ll dp[110][2];

int main()
{
  int t;
  cin>>t;
  FO(T,1,t+1)
    {
      memset(dp,0,sizeof(dp));
      ll A;
      cin>>A;
      int n;
      cin>>n;
      VL inp(n);
      FOR(i,n)
	cin>>inp[i];

      S(inp);

      FOR(i,n)
	{
	  int prev,motesize;
	  if(i==0)
	    {
	      prev=0;
	      motesize=A;
	    }
	  else
	    {
	      prev=dp[i-1][0];
	      motesize=dp[i-1][1];
	    }

	  while(motesize<=inp[i])
	    {
	      if(motesize==1)
		{
		  prev=1000000;
		  break;
		}
	      motesize+=(motesize-1);
	      prev++;
	    }

	  dp[i][0]=prev;
	  dp[i][1]=motesize+inp[i];
	}

      int ret=n;

      FOR(i,n)
	{
	  ll temp=n-i-1;
	  temp+=dp[i][0];
	  int it = (int)(temp);
	  if(it<ret)
	    ret=it;
	}

      printf("Case #%d: %d\n", T, ret);
    }
  return 0;
}
