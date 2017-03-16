#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <istream>
#include <ostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <string.h>
#include <strings.h>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <math.h>
#include <ctime>
#include <cassert>
#include <assert.h>
#include <bitset>
#include <functional>
#include <utility>
#include <iomanip>
#include <cctype>
//#include <gmp.h>
//#include <gmpxx.h>
//#include <ext/hash_set>
//#include <ext/hash_map>

using namespace std;
// using namespace __gnu_cxx;

//////////////////////////////////////////////////////////////////////////////////////////////////

bool comp(pair<int,int> a,pair<int,int> b) {return a.first < b.first; }
//////////////////////////////////////////////////////////////////////////

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

//////////////////////////////////////////////////////////////////////////

int main (int argc, char* argv[]) {
  assert(argc == 2);
  ifstream in (argv[1]);
  ofstream out ("problem.out");
  string line;
  int nbTests;
  out.precision(12);

  in >> nbTests;
  getline(in, line);

  for (int test=0; test<nbTests; test++) {
    
    int n;
    in >> n;
    vector<pair<pair<ll, ll> , int> > v(n);
    ll a, b;
    FOR(j,0,n) {
      
      in >> a >> b;
      assert(a <= b);
      v[j] = mp(mp(a,b), 0);
    }
    ll cpt = 0;
    ll st = 0;
    ll deb = 0;
    bool bad = false;
    sort(all(v));
    FOR(j,0,n-1) {
      assert(v[j].first.first <= v[j+1].first.first);
    }
    /*if(test+1 == 19)
      FOR(j,0,n) {
	cout << v[j].first.first << " " << v[j].first.second << endl;
	}*/
    while(1) {
      bool flag = false;
      ll i;
      ll gt = 0;
      ll indgt = -1;
      
      for(i = deb; i < n; i++) {
    
	/* Take a two-level if possible */
	if(v[i].first.second <= st) {
	  cpt++;
	  st += 2 - v[i].second;
	  v[i].second = 2;
	  //cout << "level 2: " << v[i].first.first << " " << v[i].first.second << " " << st << endl;
	  swap(v[i], v[deb]);
	  deb++;

	  
	  flag = true;
	  //break;
	  continue;
	}
	if(v[i].first.first > st)
	  break;
	if(v[i].second == 0 && v[i].first.second > gt) {
	  gt = v[i].first.second;
	  indgt = i;
	}
      }
      
      if(flag) {
	if(deb == n)
	  break;
	else
	  continue;
      }
      /* No level accessible */
      if(indgt == -1) {
	bad = true;
	break;
      }
      /* Choose level-1 accessible which have greatest level-2 */
      else {
	
	cpt++;
	st++;
	v[indgt].second++;
	assert(deb <= i);
	//cout << "level 1: " << v[indgt].first.first << " " << v[indgt].first.second << " " << st << endl;
	
      }
    }
    if(bad)
      out << "Case #" << test+1 << ": Too Bad" << endl;
    else
      out << "Case #" << test+1 << ": " << cpt << endl;
    
  }
}

