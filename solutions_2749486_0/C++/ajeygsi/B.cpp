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

  for( int tc = 1 ; tc <= tests ;tc++ )
    {
      int x,y;
      scanf("%d%d",&x,&y);
      
      string ans;
      
      string xstr = "" , ystr = "";
      if( x >= 0 )
	{
	  xstr = "WE";
	}
      else
	{
	  xstr = "EW";
	}

      if( y >= 0 )
	{
	  ystr = "SN";
	}
      else
	{
	  ystr = "NS";
	}

      int absx = abs(x);
      int absy = abs(y);
      
      for( int i = 0 ; i < absx ; i++ )
	{
	  ans = ans + xstr;
	}

      for( int i = 0 ; i < absy ; i++ )
	{
	  ans = ans + ystr;
	}

      cout << "Case #" << tc << ": " << ans << endl;
    }
}



