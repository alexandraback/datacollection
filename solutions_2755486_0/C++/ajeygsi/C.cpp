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


class Attack
{
public:
  int w;
  int e;
  int day;
  int s;
};

bool operator<( const Attack& lhs , const Attack& rhs )
{
  if( lhs.day < rhs.day )
    {
      return true;
    }
  return false;
}

main()
{
  int tests;
  scanf("%d",&tests);

  int num_tribes;
  for( int tc = 1 ; tc <= tests ;tc++ )
    {
      
      scanf("%d",&num_tribes);
      vector<Attack> allattacks;
      
      int day , attacks, w , e , s , deld, delp , dels;

      for( int i = 0 ; i < num_tribes ;i++ )
	{
	  scanf("%d%d%d%d%d%d%d%d",&day,&attacks,&w,&e,&s,&deld,&delp,&dels);
	  
	  Attack tmp;
	  tmp.day = day;
	  tmp.w = w;
	  tmp.e = e;
	  tmp.s = s;
	  
	  for( int j = 0 ; j < attacks ; j++)
	    {
	      allattacks.pb( tmp );
	      
	      tmp.day += deld;
	      tmp.w += delp;
	      tmp.e += delp;
	      tmp.s += dels;
	    }
	}

      sort( allattacks.begin() , allattacks.end() );

      vector<int> wall( 10000 , 0 );
      
      int num_successful = 0;
      for( int i = 0 ; i < allattacks.size() ;i++ )
	{
	  bool success = false;

	  w = allattacks[i].w;
	  e = allattacks[i].e;
	  s = allattacks[i].s;
	  
	  for( int pos = w ; pos < e ; pos++ )
	    {
	      if( wall[5000+pos] < s )
		{
		  success = true;
		}

	      //	      wall[5000+pos] = max( wall[5000+pos] , s );
	    }

	  if( success )
	    {
	      num_successful++;
	    }

	  // build the wall
	  if( ( i < allattacks.size()-1) && ( allattacks[i].day < allattacks[i+1].day ) )
	    {
	      int today = allattacks[i].day;
	      for( int j = i ; ( j >= 0 && allattacks[j].day == today ) ; j-- )
		{
		  int tw = allattacks[j].w;
		  int te = allattacks[j].e;
		  int ts = allattacks[j].s;
		  
		  for(int tpos = tw ; tpos < te ; tpos++ )
		    {
		      wall[5000+tpos] = max( wall[5000+tpos],ts);
		    }
		}
	    }

		  
	}
      
      printf("Case #%d: %d\n",tc,num_successful);
    }
}

