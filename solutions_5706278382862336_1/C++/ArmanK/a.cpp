//In the name of God
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <climits>
#include <complex>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <bitset>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <ctime>
#include <set>
#include <map>

#define X first
#define Y second
// #define X real()
// #define Y imag()
// #define cin fin
// #define cout fout

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef complex<ld> point;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;

ll tests, a, b;
char c;

inline bool valid (ll x)
{
  for(; x % 2 == 0 ; x /= 2);
  return x == 1;
}

int main ()
{
  ios_base :: sync_with_stdio(0);
  cin >> tests ;
  for(ll counter = 1 ; counter <= tests ; counter++)
    {
      cin >> a >> c >> b ;
      ll g = __gcd(a, b);
      a /= g;
      b /= g;
      cout << "Case #" << counter << ": " ; 
      if(valid(b))
	{
	  ll ans = 0;
	  while(a)
	    a /= 2, b /= 2;
	  while(b && b % 2 == 0)
	    b /= 2, ans ++;
	  ans ++;
	  cout << ans << endl ;
	}
      else
	cout << "impossible" << endl ;
    }
}
