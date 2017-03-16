#include <cstdio>
#include <cstring>
#include <string>
#include <map>

using namespace std;

string s1, s2;

int a[26],b[26];

int dp[66006];

int main()
{
  int T,na,nb;
  scanf ("%d",&T);
  for (int t = 1; t <= T; t++)
    {
      map <string,int> ma,mb; 
      int n;
      na = 0;
      nb = 0;
      scanf ("%d",&n);
      for (int i=0; i<n; i++)
	{
	  cin >> s1 >> s2;
	  if (ma[s1] != 0) a[i] = ma[s1];
	  else
	    {
	      na++;
	      ma[s1] = na;
	      a[i] = na;
	    }
	  if (mb[s2] != 0) b[i] = mb[s2];
	  else
	    {
	      nb++;
	      mb[s2] = nb;
	      b[i] = nb;
	    }
	}
      long mask;
      for (mask = 0; mask < (1 << n); mask++)
	{
	  if (mask == 0)
	    {
	      dp[mask] = 0;
	      continue;
	    }
	  dp[mask] = 0;
	  for (int i=0; i<n; i++)
	    {
	      if (!(mask & (1 << i))) continue;
	      long oldMask = mask ^ (1 << i);
	      bool f1=0,f2=0;
	      for (int j=0; j<n; j++)
		{
		  if (i == j) continue;
		  if (!(mask & (1 << j))) continue;
		  if (a[i] == a[j]) f1 = 1;
		  if (b[i] == b[j]) f2 = 1;
		}
	      if (dp[mask] < dp[oldMask] + (f1&f2))
		  dp[mask] = dp[oldMask] + (f1&f2);
	    }
	}
      printf ("Case #%d: %d\n",t,dp[(1<<n)-1]);
    }
}
