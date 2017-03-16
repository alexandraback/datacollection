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
  bool ok;
  cin >> T;
  cout.precision(12);
  FOR (test, 1, T+1) {
    int c, v, d;
    cin >> c >> d >> v;
    vector<int> val(d,0);
    FOR(i,0,d) cin >> val[i];
    int sol = -1;

    FOR(nb, 0, 6) {
      vector<int> take(31,0);
      for (int i = 30; i >= 30 - nb + 1; i --) take[i] = 1;
      do {
	vector<int> values(val);
	vector<bool> can(200,false);

	FOR(i,1,30) if (take[i]) values.push_back(i);
	sort (all(values));
	int d = values.size();
	ok = true;
	FOR(i,0,d-1) if (values[i] == values[i+1]) {ok = false; break;}
	if (!ok) {goto endloop;}
	
	FOR(i,0,(1 << d)) {
	  int icp = i;
	  int sum = 0;
	  int cpt = 0;
	  while (icp > 0) {
	    if (icp & 1) {
	      sum += values[cpt];
	    }
	    cpt++;
	    icp /= 2;
	  }
	  can[sum] = true;
	}
	ok = true;
	FOR(i,0,v+1) if (!can[i]) ok = false;
	if (ok) {
	  sol = nb;
	  goto endprog;
	}
      endloop:
	nb = nb;
      } while (next_permutation(all(take)));
    }
  endprog:
    cout << "Case #" << test << ": " << sol << endl;
  }
  return 0;
}
