#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <set>
#include <sstream>
#include <numeric>
#include <bitset>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cctype>
#include <cassert>
using namespace std;

typedef long long ll;
static const double EPS = 1e-8;
static const double PI = acos(-1);
bool ISINT(double x){return fabs(x-(int)round(x))<EPS;}
bool ISEQ(double x,double y){return fabs(x-y)<EPS;}
string itos(ll x){stringstream ss;ss<<x;return ss.str();}
#define foreach(itr,c) for(__typeof(c.begin()) itr=c.begin();itr!=c.end();itr++)

int n, m;
int t[102];

int main(void){
  int T;
  cin >> T;

  for(int CASE = 1; CASE <= T; CASE++){
    cout << "Case #" << CASE << ": ";
    cin >> n >> m;

    for(int i = 0; i < m; i++){
      cin >> t[i];
    }
    sort(t, t + m);

    int ans = INT_MAX;
    int cnt = 0;

    for(int i = 0; i < m; i++){
      if(n > t[i]){
        n += t[i];
        continue;
      }

      ans = min(ans, cnt + m - i);

      if(n <= t[i]){
        if(n - 1 == 0){
          cnt = INT_MAX;
          break;
        }

        while(n <= t[i]){
          cnt++;
          n += (n - 1);
        }
      }

      n += t[i];
    }

    ans = min(ans, cnt);
    cout << ans << endl;
  }
}
