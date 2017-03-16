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

  string str;
  int n;
  for( int tc = 1 ; tc <= tests ; tc++ )
    {
      cin >> str >> n;
      
      LL len = str.length();

      // consonant = 1
      // vowel = 0;
      vector<int> arr( str.length() , 1 );
      
      for( int i = 0 ; i < str.length() ; i++ )
	{
	  if( str[i] == 'a' ||
	      str[i] == 'e' ||
	      str[i] == 'i' ||
	      str[i] == 'o' ||
	      str[i] == 'u' )
	    {
	      arr[i] = 0;
	    }
	}

      vector<int> carr( str.length() , 0 );
      
      int consonants_seen = 0;
      for( int i = 0 ; i < len ; i++ )
	{
	  if( arr[i] == 1 )
	    {
	      consonants_seen++;
	    }
	  else
	    {
	      consonants_seen = 0;
	    }
	  carr[i] = consonants_seen;
	}

      LL l = 0 , r = 0;
      LL ans = 0;
      
      while( true )
	{
	  if( r >= len )
	    {
	      break;
	    }

	  if( l >= len )
	    {
	      break;
	    }

	  
	  if( ( r - l + 1 ) < n )
	    {
	      r++;
	      continue;
	    }

	  if( carr[r] >= n )
	    {
	      ans = ans + ( len - r );
	      l++;
	      continue;
	    }
	  
	  r++;
	}
    
      printf("Case #%d: %lld\n",tc,ans);
    }
}

