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
#include <deque>
#include <map>
#include <set>
#include <utility>
#include <sys/time.h>

#define INF 1000000007
#define EPS (1e-8)
#define pb(a) push_back(a)
#define pf(a) push_front(a)
#define mp make_pair
#define FOR(i,k) for(i=0;i<k;i++)
#define RFOR(i,k) for(i=k-1;i>=0;i--)
const long double PI = 3.1415926535897932384626433832795;
typedef long long LL;


using namespace std;

void computeAdditional( int& currsize , int nextsize , int& intermediaries )
{
  while( true )
    {
      if( currsize <= nextsize )
	{
	  currsize = currsize + currsize - 1;
	  intermediaries++;
	}
      else
	{
	  break;
	}
    }

  currsize = currsize + nextsize;
}
	  


main()
{
  int tests;
  scanf("%d",&tests);
  
  int armisize, num_motes;
  for( int tc = 1 ; tc <= tests ;tc++ )
    {
      scanf("%d%d",&armisize,&num_motes);
      
      vector<int> allmotes(num_motes);
      for( int i = 0 ; i < num_motes ; i++ )
	{
	  scanf("%d",&allmotes[i]);
	}

      if( armisize == 1 ) 
	{
	  printf("Case #%d: %d\n",tc,num_motes);
	  continue;
	}

      sort( allmotes.begin() , allmotes.end() );
      
      int currsize = armisize;
      int ans = num_motes;
      int intermediaries_added = 0;

      for( int i = 0 ; i < num_motes ; i++ )
	{
	  // If it can be consumed, then consume it.
	  if( currsize > allmotes[i] )
	    {
	      currsize = currsize + allmotes[i];
	      
	      ans = min ( ans , intermediaries_added + num_motes - i - 1);
	    }
	  else
	    {
	      // I don't eat it.
	      ans = min( ans , intermediaries_added + num_motes - i );

	      // I eat it.
	      int intermediaries = 0;
	      computeAdditional( currsize , allmotes[i] , intermediaries );
	      intermediaries_added += intermediaries;
	      
	      ans = min( ans , intermediaries_added + ( num_motes - i - 1 ) );
	    }
	}

      printf("Case #%d: %d\n",tc,ans);
    }
}
