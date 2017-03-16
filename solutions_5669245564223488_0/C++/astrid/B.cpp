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
ll MOD = 1000000007;

int main() {
  //ios_base::sync_with_stdio(0);

  vector<ll> facto(101,0);
  facto[0] = 1;
  FOR(i,1,101) 
    facto[i] = (facto[i-1]*((ll)i))%MOD;

  int T;
  cin >> T;
  cout.precision(12);
  FOR (test, 1, T+1) {
    int n; cin >> n;
    vector<string> tab(n);
    vector<int> only(26,0);
    vector<int> begin(26,0);
    vector<int> end(26,0);
    vector<int> middle(26,0);

    FOR(i,0,n) cin >> tab[i];

    bool fini = false;
    vector<string> tab2;
    FOR(i,0,n) {
      int m = tab[i].size();
      bool ok = true;
      FOR(j,0,m) 
	if (tab[i][j] != tab[i][0]) {
	  ok = false;
	  break;
	}
      if (ok) {
	only[(int)(tab[i][0]-'a')] ++;
	continue;
      }
      begin[(int)(tab[i][0]-'a')]++;
      end[(int)(tab[i][m-1]-'a')]++;
      if ((int)(tab[i][0]-'a') == (int)(tab[i][m-1]-'a')) {
	fini = true;
	break;
      }
      int j, k;
      for (j = 0; j < m; j++) if (tab[i][j] != tab[i][0]) break;
      for (k = m - 1; k >= 0; k--) if (tab[i][k] != tab[i][m-1]) break;
      for (; j <= k; j++) {
        middle[(int)(tab[i][j]-'a')] ++;
	int jj = j;
	while (tab[i][j] == tab[i][jj]) {assert(j <= k); j++;}
      }
      
      tab2.pb(tab[i]);
    }
    if (fini) { 
      cout << "Case #" << test << ": 0" << endl;
      continue;
    }

    FOR(i,0,26) {
      if (middle[i] > 1 || begin[i] > 1 || end[i] > 1 
	  || (middle[i]==1 && (begin[i]+end[i] >= 1))) {
	//cout << "ici" << endl;
	cout << "Case #" << test << ": 0" << endl;
	fini = true;
	break;
      }
    }
    if (fini) continue;
 

    ll sol = 1;
    int nn = 0;
    FOR(i,0,26) {
      if (only[i] != 0) {
	sol = (sol * facto[only[i]]) % MOD;
	if (begin[i] + end[i] == 0) {
	  //cout << "oooo " << (char)('a'+i) << endl;
	  nn+=2;
	}
      }
      if (begin[i] + end[i] == 1) {
	//cout << (char)('a'+i) << endl;
	nn++;
      }
    }
    //cout << nn << endl;
    assert(nn%2==0);
    sol = (sol * facto[nn/2]) % MOD;
    
    vector<int> next(26,-1);
    FOR(i,0,tab2.size()) {
      int m = tab2[i].size();
      assert(next[(int)(tab2[i][0]-'a')] == -1);
      next[(int)(tab2[i][0]-'a')] = (int)(tab2[i][m-1]-'a');
      
      /*FOR(j,0,tab2.size()) {
	int m = tab2[i].size();
	if (tab2[i][m-1]==tab2[j][0]) {
	  assert(next[(int)(tab2[i][0]-'a')] == -1);
	  next[(int)(tab2[i][m-1]-'a')] = ;
	}
	}*/
    }
    fini = false;
    FOR(i,0,26) {
	int ii = i;
	do {
	  if (next[ii] == -1) break;
	  ii = next[ii];
	} while (i != ii);
	if (ii == i && next[ii] != -1) {
	  fini = true;
	  break;
	}
    }
    if (fini) sol = 0;
    cout << "Case #" << test << ": " << sol << endl;

  }
  return 0;
}
