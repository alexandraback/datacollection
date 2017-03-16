#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cfloat>
#include <climits>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <set>

#define INF 1000000007
#define EPS (1e-8)
#define pb(a) push_back(a)
#define pf(a) push_front(a)
typedef long long LL;

using namespace std;


class Rename
{
public:
};


main()
{
  int tests;
  scanf("%d",&tests);
  
  int num_typed;
  int total_chars;

  for( int tc = 1 ; tc <= tests ; tc++ )
    {
      scanf("%d%d",&num_typed,&total_chars);
      
      vector<double> prob_perfect(num_typed);
      double tprob;
      
      for(int i = 0 ;i < num_typed ; i++)
	{
	  cin >> tprob;
	  
	  if( i == 0  )
	    {
	      prob_perfect[i] = tprob;
	    }
	  else
	    {
	      prob_perfect[i] = tprob * prob_perfect[i-1];
	    }
	}

      double min_expected = 1000000.0;
      double expected;
      double pmistake, pcorrect;
      int correct_keys, mistake_keys;
      
      // finish typing password.
      
      correct_keys = 1 + (total_chars - num_typed);
      mistake_keys = correct_keys + total_chars + 1;


      pmistake = 1.0 - prob_perfect[num_typed-1];
      expected = prob_perfect[num_typed-1] * correct_keys + pmistake * mistake_keys;
      
      min_expected = min ( min_expected , expected );
      
      
      // Give up.
      expected = 1 + total_chars + 1;
      min_expected = min( min_expected, expected);
      
      
      // Press backspace some times.
      for( int backsp = 1 ; backsp <= num_typed ;backsp++ )
	{
	  correct_keys = 2*backsp + (total_chars - num_typed) + 1;
	  mistake_keys = correct_keys + total_chars + 1;
	  
	  if( backsp == num_typed )
	    {
	      pmistake = 0;
	      pcorrect = 1.0;
	    }
	  else
	    {
	      pmistake = 1.0 - prob_perfect[num_typed - 1 - backsp];
	      pcorrect = prob_perfect[num_typed-1-backsp];
	    }

	  expected = correct_keys*pcorrect + mistake_keys*pmistake;
	  min_expected = min ( min_expected , expected );
	}

      printf("Case #%d: %f\n",tc,min_expected);
    }
}

	  
	  


