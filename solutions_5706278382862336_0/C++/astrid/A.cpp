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
//#include <unordered_set>
//#include <unordered_map>
#include <assert.h>

using namespace std;

typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> int2;
typedef pair<float, float> float2;
typedef pair<ull, ull> ull2;

#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(s,i) for ( __typeof((s).begin()) i = ((s).begin())   ; i != (s).end(); ++i)  
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define mp(a,b) make_pair(a,b)
#define del(s,x) if(s.find(x)!=s.end()) s.erase(s.find(x))

#define FOR(i,a,b) for(int i=int(a); i<int(b); ++i)

bool comp(pair<int,int> a,pair<int,int> b) {return a.first < b.first; }

ll gcd (ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a%b);
}

int main() {
  //ios_base::sync_with_stdio(0);
  int T;
  cin >> T;
  cout.precision(12);
  FOR (test, 1, T+1) {
    ll p,q;
    char c;
    cin >> p >> c >> q;
    ll g = gcd(p,q);
    p /= g, q /= g;
    ll qcp = q, pcp =p;
    int qq = 0, pp = 0;
    while (qcp % 2 == 0) {
      qq++;
      qcp /= (ll)2;
    }
    if (qcp != 1 || qq > 40) {
      cout << "Case #" << test << ": impossible" << endl;
      continue;
    }
    while (pcp > (ll)1) {
      pcp /= (ll)2;
      pp++;
    }
    cout << "Case #" << test << ": " << qq - pp << endl;
  }
  return 0;
}
