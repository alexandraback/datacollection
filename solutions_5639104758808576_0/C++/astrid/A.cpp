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

int main() {
  int T;
  cin >> T;
  cout.precision(12);
  FOR (test, 1, T+1) {
    int n; string s;
    cin >> n >> s; n++;
    vector<int> v(n+1,0);
    FOR(i,0,n) v[i] = (int) (s[i]-'0');
    
    int nb = 0;
    int sol = 0;
    FOR(i,0,n) {
      if (nb < i) {
	sol += i - nb;
	nb = i;
      }
      nb += v[i];
    }

    cout << "Case #" << test << ": " << sol << endl;
  }
  return 0;
}
