#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

typedef long long ll;
#define INF 987654321
using namespace std;

int main() {
  freopen("A_in.txt","r",stdin);
  freopen("A_out.txt","w",stdout);
  ll T, a, b;
  cin >> T;
  for(int t = 1; t<=T; t++) {
    scanf("%lld/%lld", &a, &b);
    ll p = 0;
    ll x = __gcd(a,b);
    bool ok=0;
    a/=x;
    b/=x;
    if((b&(b-1)) == 0) {
      ok=1;
      while(a < b) {
        p++;
        a*=2;
      }
    }

    if(ok)
      cout << "Case #" << t << ": " << p << endl;
    else
      cout << "Case #" << t << ": impossible" << endl;
  }
  return 0;
}
