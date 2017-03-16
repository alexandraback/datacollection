#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

int numLetters[16] = {4,3,3,5,4,4,3,5,5,4};
int counts[16];

char s[2006],dig[16][16] = {{'Z','E','R','O'},
			    {'O','N','E'},
			    {'T','W','O'},
			    {'T','H','R','E','E'},
			    {'F','O','U','R'},
			    {'F','I','V','E'},
			    {'S','I','X'},
			    {'S','E','V','E','N'},
			    {'E','I','G','H','T'},
			    {'N','I','N','E'}};

char repr[16] = {'Z','O','W','R','U','F','X','S','G','I'};
int order[16] = {0,2,4,5,3,6,1,8,7,9};

int num[16];

int main()
{
  int i,t,n;
  char useless;
  scanf ("%d%c",&t,&useless);
  for (int T = 1; T <= t; T++ )
    {
      scanf ("%s",s);
      n = strlen(s);
      for (i=0; i<10; i++) num[i] = 0;
      for (int ii=0; ii<10; ii++)
	{
	  int digit = order[ii];
	  for (i=0; i<n; i++)
	    if (s[i] == repr[digit]) num[digit]++;
	  for (i=0; i<numLetters[digit]; i++)
	    counts[i] = num[digit];
	  for (i=0; i<n; i++)
	    {
	      for (int j=0; j<numLetters[digit]; j++)
		if ((s[i] == dig[digit][j]) && counts[j])
		  {
		    s[i] = 'A';
		    counts[j]--;
		    break;
		  }
	    }
	}

      printf("Case #%d: ",T);
      for (i=0; i<10; i++)
	for (int j=0; j<num[i]; j++)
	  printf("%d",i);
      printf ("\n");
    }
}
