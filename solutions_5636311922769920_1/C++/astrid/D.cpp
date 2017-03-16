#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string.h>
#include <strings.h>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <map>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <climits>
#include <assert.h>

using namespace std;

#define FOR(i,a,b) for(int i=int(a); i<int(b); ++i)

typedef long long int ll;

int main () {
  int testnb;
  ll K, C, S;
  
  cin >> testnb;
  
  for (int test = 1; test <= testnb; test ++) {
    cin >> K >> C >> S;

    ll cpt = 0;
    vector<ll> sol (0);
    while (cpt < K) {
      ll powK = 1;
      ll look = 0;
      FOR(i,0,C) {
	look += powK * min(cpt,K-1);
	powK *= K;
	cpt ++;
      }
      sol.push_back(look);
    }
    int solsiz = sol.size();
    assert (solsiz == (K - 1) / C + 1);
    if (solsiz > S)
      cout << "Case #" << test << ": IMPOSSIBLE" << endl;
    else {
      cout << "Case #" << test << ": ";
      FOR (i,0,solsiz) cout << sol[i] + 1 << " ";
      cout << endl;
    }
  }
  return (0);
}
