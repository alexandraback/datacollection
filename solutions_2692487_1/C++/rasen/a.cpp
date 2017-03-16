#include <algorithm>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <cmath>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long            int64;
typedef long long            ll;
typedef pair<double, double> pdd;
typedef pair<int,  int>      pii;
typedef pair<int64,int64>    pii64;
typedef unsigned long long   uint64;
typedef vector<double>       vd;
typedef vector<int64>        vi64;
typedef vector<int>          vi;
typedef vector<vi>           vvi;

const double eps = 1e-11;
const double pi  = acos(-1.0);
const int    p   = 1000000007;

int solve() {
  return 0;
}

int todel(ll a, vector<int>::iterator it, vector<int>::iterator end) {
    //cout << "TODEL: " << a << " " << *it << "\n"; 
    if (it == end) {
        return 0;
    }

    // Eat insert or del
    // Eat
    if (a > *it) {
        return todel(a+*it, it+1, end);
    }

    // Del
    int del = end - it;

    // Insert 
    int ins = 0;
    while (ins < del && a <= *it) {
        a = a*2 - 1;
        ins++;
    }
    if (ins >= del) {
        return del;
    }

    a += *it;
    ins += todel(a, it+1, end);
    
    return min(ins, del);
}

int main() {
    unsigned int nTests;
    scanf("%d", &nTests);

    for(unsigned int testNumber = 0; testNumber < nTests; testNumber++) {
      printf("Case #%d: ", testNumber + 1);

      ll a, n;
      cin >> a >> n;
      vi x(n);
      for (int i = 0; i < n; i++) {
          cin >> x[i];
      }

      sort(x.begin(), x.end());

//* 
      vector<int>::iterator it = x.begin();
      int res = 0;
      while (it != x.end() && a*2 - 1 > *it) {
          if (*it >= a) {
              res++;
              a = a*2 -1;
          } else {
              a += *it;
              it++;
          }
      } 
      cout << res + todel(a, it, x.end()) << "\n";
      /*/
      
      cout << todel(a, x.begin(), x.end()) << "\n";

      // */

    }
    return 0;
}
