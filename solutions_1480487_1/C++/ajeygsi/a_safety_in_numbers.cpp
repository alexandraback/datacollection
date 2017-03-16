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



main()
{
  int tests;
  int num_contestants;
  int tmp;

  scanf("%d",&tests);
  for( int tc = 1 ; tc <= tests ; tc++ )
    {
      scanf("%d",&num_contestants);
      
      vector<int> scores( num_contestants );
      double points_for_grabs = 0.0;      
      for(int i = 0 ; i < num_contestants ; i++ )
	{
	  scanf("%d",&scores[i]);
	  points_for_grabs = points_for_grabs + scores[i];
	}

      double audience_points = points_for_grabs;
      double score1 = 0.0;
      int num_left = 0;

      for(int i = 0; i < num_contestants ;i++)
	{
	  if( scores[i] >= ( 2 * audience_points / num_contestants ))
	    {
	      // Seeing an already qualified person.
	    }
	  else
	    {
	      score1 += scores[i];
	      num_left++;
	    }
	}
      
      double total_meta_score = score1 + audience_points;
      double each_score = total_meta_score/(double)num_left;

      double  ans;
      printf("Case #%d: ",tc);
      for( int i = 0 ; i < num_contestants ; i++ )
	{
	  if( ( scores[i] >= ( 2 * audience_points / num_contestants ) ) || ( scores[i] >= each_score ) )
	    {
	      ans = 0.0; 
	    }
	  else
	    {
	      ans = ( each_score - scores[i] ) * 100 / audience_points;
	    }

	  printf("%f",ans);
	  
	  if( i != ( num_contestants - 1 ) )
	    {
	      printf(" ");
	    }
	  else
	    {
	      printf("\n");
	    }
	}

    }
}
