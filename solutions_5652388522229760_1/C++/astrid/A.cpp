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
  ll n;
  ll cur;
  ll curcp;
  int seen[10];
  int testnb;
  int ok = 0;
  
  cin >> testnb;
  
  for (int test = 1; test <= testnb; test ++) {
    cout << "Case #" << test << ": ";
    cin >> n;
    if (n == 0) {
      cout << "INSOMNIA" << endl;
      continue;
    }
    FOR(i,0,10) seen[i] = 0;
  
    for (int i = 0, cur = n; ; i ++, cur += n) { 
      assert (i <= 100); /* Sould never exceed 100 iterations */
      curcp = cur;
      while (curcp > 0) {
	seen[curcp % 10] = 1;
	curcp /= 10;
      }
      ok = 1;
      FOR(i,0,10) if (seen[i] == 0) ok = 0;
      if (ok) {
	cout << cur << endl;
	break;
      }
    }
  }
  return (0);
}
