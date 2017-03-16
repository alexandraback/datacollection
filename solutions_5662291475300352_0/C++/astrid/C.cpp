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
#include <gmp.h>
#include <gmpxx.h>

typedef mpz_class mpz; 

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
#define del(s,x) do {__typeof((s).begin()) abcde=(s).find(x); if(abcde !=(s).end()) s.erase(abcde); } while(0);
#define del2(s,x) do {__typeof((s).begin()) abcde=find(all(s),x); if(abcde !=(s).end()) s.erase(abcde); } while(0);

#define FOR(i,a,b) for(int i=int(a); i<int(b); ++i)

int main() {
  int T;
  cin >> T;
  cout.precision(12);
  FOR (test, 1, T+1) {
    int n, nb; mpz angle, speed, dist, time; 
    cin >> n;
    vector<pair<mpz,mpz> > hik(0);
    FOR(i,0,n) {
      cin >> angle >> nb >> speed;
      FOR(j,0,nb) {
	hik.pb(make_pair(speed, angle));
	speed ++;
      }
    }
    sort (all (hik));
    assert (hik.size () <= 2);
    if ((hik.size () <= 1) || (hik[0].first == hik[1].first)) 
      cout << "Case #" << test << ": 0" << endl;
    else {
      mpz vslow = hik[1].first;
      mpz pslow = hik[1].second;
      mpz vquick = hik[0].first;
      mpz pquick = hik[0].second;
      assert (pslow - pquick + 360 >= 0);
      assert (vquick <= vslow);
      dist = (pslow - pquick + 360) % 360;
      if (dist == 0)
	dist = 360;
      //mpz timeslow, timemet;
      //timeslow = (360 - pslow); /* time when the slower reach the first time the arrival, divided by vslow/360 */
      //timemet = (dist * vquick); /* ""time"" when the slower and the quicker met the first time, not counting departure, divided by vslow/360 and multiplied by vslow - vquick */
      //if (timeslow * (vslow - vquick) < timemet)

      mpz tslow = (360 - pslow) * vslow;
      mpz tquick;
      //      if (pquick >= pslow)
	tquick = (360 + 360 - pquick) * vquick;
	//else
	//tquick = (360 - pquick) * vquick;

      if (tslow < tquick)
	cout << "Case #" << test << ": 0" << endl; /* Stay behind slow! */
      else
	cout << "Case #" << test << ": 1" << endl;
    }
  }
  return 0;
}
