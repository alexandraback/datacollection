//Grzegorz Pstrucha

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <functional>
#include <iostream>
#include <sstream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <math.h>

#define ASSERT_ for (;;) {}
#define PII pair<int, int>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<string> vs;

#define REP(i,n)    for(int i=0; i<(n); ++i)
#define FOR(i,p,k)  for(typeof(p) i=(p); i<=(k); ++i)
#define FORD(i,p,k) for(typeof(p) i=(p); i>=(k); --i)

int solve(vll &data, long long x, int l, int p) {
  for(int i=l; i <= p; i++){
    if (x > data[i]) {
      x += data[i];
    } else {
      int s1 = 2000000000;
      if (x > 1) {
        int ile = 0;
        long long y = x;
        while (y <= data[i]){
          y += (y-1);
          ile += 1;
        }
        s1 = solve(data, y+data[i], i+1, p) + ile;
      }
      int s2 = data.size() - i;
      return min(s1,s2);

      break;
    }
  }

  return 0;
}

int main() {
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    REP(i,t) {
      long long x,n;
      cin >> x >> n;
      long long dummy;
      vll data;
      REP(j, n) {
        cin >> dummy;
        data.push_back(dummy);
      }
      sort(data.begin(), data.end());
      cout << "Case #" << i + 1 << ": " << solve(data,x, 0, data.size()-1) << endl;

    }

    return 0;
}
