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

int tests, a, b, k;

int main ()
{
  ios_base :: sync_with_stdio(0);
  cin >> tests ;
  for(int counter = 1 ; counter <= tests ; counter++)
    {
      cin >> a >> b >> k ; 
      int ans = 0;
      for(int i = 0 ; i < a ; i++)
	for(int j = 0 ; j < b ; j++)
	  if((i & j) < k)
	    ans ++;
      cout << "Case #" << counter << ": " << ans << endl ;
    }
}
