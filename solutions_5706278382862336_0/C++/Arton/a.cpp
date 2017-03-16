#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <memory.h>
#include <cmath>
#include <string>
#include <ctime>

using namespace std;

// #def ArtonTest

template<class T> inline T gcd(T a,T b)//NOTES:gcd(
  {if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}

long long p,q;

int log2( long long x ) {
    int ans = 0;
    while ( true )
    {
        if ( x % 2 == 0 )
        {
            ans++;
            x = x /2 ;
        }
        else if ( x != 1 )
        {
            return -1;
        }
        else
            break;
    }

    return ans;
}

long long solve() {
    long long g = gcd( p,q );
    p = p / g;
    q = q / g;

    if ( log2( q ) == -1 )
    {
        return -1;
    }

    long long ans = 0;
    while ( true )
    {
        ans++;
        if ( p*2 >= q )
        {
            return ans;
        }
        else
        {
            p *= 2;
        }
    }
}

void solveTest(int CS) {
  printf("Case #%d: ", CS);
  char c;
  scanf( "%lld%c%lld", &p, &c, &q );
  long long ans = solve();
  if ( ans == -1 )
        printf( "impossible\n" );
  else
      printf("%lld\n", ans);
}

int main() {
#ifdef ArtonTest
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int T;
  scanf("%d\n", &T);
  for (int test = 1; test <= T; ++test) {
    solveTest(test);
  }
  return 0;
}
