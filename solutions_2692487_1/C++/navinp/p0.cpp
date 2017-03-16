#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int A, N;
int dp[201][2000002];

vector < int >v;
int
go (int lvl, int curmote)
{
  if (lvl >= N)
    return 0;
  int z = 0;
if(dp[lvl][curmote]!=-1) return dp[lvl][curmote];
  if (curmote > v[lvl])
    {
      z = go (lvl + 1, curmote + v[lvl]);
      return dp[lvl][curmote]=z;
    }
  else
    {
      int mx;
      if (curmote > 1)
	mx = 1 + go (lvl, curmote + curmote - 1);
      else
	mx = N;
      int mn = 1 + go (lvl + 1, curmote);
      return dp[lvl][curmote]=min (mx, mn);
    }

}

int
main ()
{
  int T;
  scanf(" %d",&T);
  int tc = 1;
  while (T--)
    {
	scanf(" %d %d",&A,&N);
	memset(dp,-1,sizeof(dp));
      int x, i;
      v.clear ();
      for (i = 0; i < N; i++)
	{
	 scanf(" %d",&x);
	  v.push_back (x);
	}
      sort (v.begin (), v.end ());


      printf ("Case #%d: ", tc++);
      printf ("%d\n", go (0, A));

    }
  return 0;
}
