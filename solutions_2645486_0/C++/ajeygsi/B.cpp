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


main()
{
  int tests;
  scanf("%d",&tests);
  
  LL e,r,n;
  for( int tc = 1 ; tc <= tests ; tc++ )
    {
      scanf("%lld%lld%lld",&e,&r,&n);
      
      vector<LL> values(n);
      for( int i = 0 ; i < n ; i++ )
	{
	  scanf("%lld",&values[i]);
	}

      vector<int> nextbetter(n,-1);
      for( int i = 0 ; i < n ; i++)
	{
	  for( int j = i+1 ; j < n ; j++)
	    {
	      if( values[j] > values[i] )
		{
		  nextbetter[i] = j;
		  break;
		}
	    }
	}
      
      if( r > e )
	{
	  r = e;
	}
      
      LL currene = e;
      LL ans = 0;
      
      for( int i = 0 ; i < n ; i++ )
	{
	  LL currpos = i;
	  LL betterpos = nextbetter[currpos];
	  LL spendenergy  = 0;
	  
	  // there is no better guy.
	  if( betterpos == -1 )
	    {
	      spendenergy = currene;
	    }
	  else
	    {
	      LL maxregain = ( betterpos - currpos ) * r;
	      LL excessenergy = ( currene + maxregain - e );
	      
	      if( excessenergy > 0 )
		{
		  spendenergy = min( excessenergy , currene );
		}
	      else
		{
		  spendenergy = 0;
		}
	    }
	  
	  ans = ans + values[i]*spendenergy;
	  currene = min( e , currene - spendenergy + r );
	}
      
      printf("Case #%d: %lld\n",tc,ans);
    }
}





