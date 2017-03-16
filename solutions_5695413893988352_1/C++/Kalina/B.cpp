#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

char c[26],j[26];

int dc[26],dj[26];

unsigned long long dp[26][4];
unsigned long long C[26][4], J[26][4];

unsigned long long abss(unsigned long long x, unsigned long long y)
{
  if (x >= y) return x - y;
  return y - x;
}

int attc[26],attj[26],numA;

void prin(int n, unsigned long long x)
{
  int d=0;
  unsigned long long y = x;
  if (x == 0) d = 1;
  while(x)
    {
      d++;
      x /= 10;
    }
  for (int i = 0; i < n - d; i++) cout << '0';
  cout << y;
}

int main()
{
  char useless;
  int T;
  unsigned long long B;
  scanf ("%d%c",&T,&useless);
  for (int t=1; t<=T; t++)
    {
      scanf ("%s%s",c,j);
      int n = strlen(c);
      B = 1;
      for (int i=0; i<n; i++)
	{
	  dc[i] = (int)c[i] - 48;
	  dj[i] = (int)j[i] - 48;
	}
      C[n][0] = C[n][1] = C[n][2] = 0;
      J[n][0] = J[n][1] = J[n][2] = 0;
      dp[n][0] = dp[n][1] = dp[n][2] = 0;
      for (int i=n-1; i>=0; i--)
	{
	  // Case 0: they're equal

	  // No choice
	  if (c[i] != '?' && j[i] != '?')
	    {
	      numA = 1;
	      attc[0] = dc[i]; attj[0] = dj[i];
	    }
	  // Full freedom
	  else if (c[i] == '?' && j[i] == '?')
	    {
	      numA = 3;
	      attc[0] = 0; attj[0] = 0;
	      attc[1] = 0; attj[1] = 1;
	      attc[2] = 1; attj[2] = 0;
	    }
	  // Freedom for first one
	  else if (c[i] == '?' && j[i] != '?')
	    {
	      if (dj[i] == 9) { numA = 2; attc[0] = 8; attj[0] = 9; attc[1] = 9; attj[1] = 9; }
	      else if (dj[i] == 0) { numA = 2; attc[0] = 0; attj[0] = 0; attc[1] = 1; attj[1] = 0; }
	      else { numA = 3; attc[0] = dj[i]-1; attc[1] = dj[i]; attc[2] = dj[i] + 1; attj[0] = attj[1] = attj[2] = dj[i]; }
	    }
	  // Freedom for second one
	  else
	    {
	      if (dc[i] == 9) { numA = 2; attc[0] = 9; attj[0] = 8; attc[1] = 9; attj[1] = 9; }
	      else if (dc[i] == 0) { numA = 2; attc[0] = 0; attj[0] = 0; attc[1] = 0; attj[1] = 1; }
	      else { numA = 3; attj[0] = dc[i]-1; attj[1] = dc[i]; attj[2] = dc[i] + 1; attc[0] = attc[1] = attc[2] = dc[i]; }
	    }

	  for (int k=0; k<numA; k++)
	    {
	      int Cdig = attc[k], Jdig = attj[k];
	      int ind = 0;
	      if (Cdig > Jdig) ind = 1;
	      if (Cdig < Jdig) ind = 2;
	      unsigned long long Ccand = B*Cdig + C[i+1][ind];
	      unsigned long long Jcand = B*Jdig + J[i+1][ind];
	      unsigned long long diff = abss(Ccand, Jcand);
	      if (k == 0 || diff < dp[i][0])
		{
		  dp[i][0] = diff;
		  C[i][0] = Ccand;
		  J[i][0] = Jcand;
		}
	    }
	  
	  // Case 1: first is bigger
	  attc[0] = dc[i]; attj[0] = dj[i];
	  if (c[i] == '?') attc[0] = 0;
	  if (j[i] == '?') attj[0] = 9;

	  C[i][1] = B*attc[0] + C[i+1][1];
	  J[i][1] = B*attj[0] + J[i+1][1];
	  dp[i][1] = 10*B + C[i][1] - J[i][1];
	  	 
	  // Case 2: second is bigger
	  attc[0] = dc[i]; attj[0] = dj[i];
	  if (c[i] == '?') attc[0] = 9;
	  if (j[i] == '?') attj[0] = 0;
	 
	  C[i][2] = B*attc[0] + C[i+1][2];
	  J[i][2] = B*attj[0] + J[i+1][2];
	  dp[i][2] = 10*B + J[i][2] - C[i][2];
	  
	  B *= 10;
	}
      cout << "Case #" << t <<": ";
      prin(n,C[0][0]);
      cout << ' ';
      prin(n,J[0][0]);
      cout << endl;
    }
}
