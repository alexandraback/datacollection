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

ll tests, n, order[11];
vector<string> vc;

inline bool valid ()
{
  string tot;  
  for(int i = 0 ; i < n ; i++)
    tot = tot + vc[order[i]];
  string hlp = tot;
  sort(hlp.begin(), hlp.end());
  hlp.resize(unique(hlp.begin(), hlp.end()) - hlp.begin());
  tot.resize(unique(tot.begin(), tot.end()) - tot.begin());
  return tot.size() == hlp.size();
}

int main ()
{
  ios_base :: sync_with_stdio(0);
  cin >> tests ;
  for(int counter = 1 ; counter <= tests ; counter++)
    {
      ll ret = 0;
      cin >> n ; 
      vc.resize(n);
      for(int i = 0 ; i < n ; i++)
	{
	  cin >> vc[i] ; 
	  vc[i].resize(unique(vc[i].begin(), vc[i].end()) - vc[i].begin());
	  order[i] = i;
	}
      do
	{
	  if(valid())
	    ret ++;
	} while(next_permutation(order, order + n));
      cout << "Case #" << counter << ": " << ret << endl ;
    }
}
