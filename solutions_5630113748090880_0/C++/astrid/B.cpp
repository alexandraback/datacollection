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
  cin >> T;
  cout.precision(12);
  FOR (test, 1, T+1) {
    int n;
    cin >> n;
    vector<vector<int> > G (2*n-1, vector<int> (n,0));
    FOR(i,0,2*n-1) {
      FOR(j,0,n) {
	cin >> G[i][j];
      }
    }
    vector <int> p(2*n - 1,0); 
    FOR(i,0,n) {
      p[2*n-2-i] = 1;
    }
    do {
      vector<vector<int> > Grow (n, vector<int> (n,0));
      vector<vector<int> > Gcol (n-1, vector<int> (n,0));
      int cpt1 = 0, cpt2 = 0;
      FOR(k,0,2*n-1) {
	if (p[k] == 1) {
	  FOR(i,0,n) Grow[cpt1][i] = G[k][i];
	  cpt1 ++;
	}
	else {
	  FOR(i,0,n) Gcol[cpt2][i] = G[k][i];
	  cpt2 ++;
	}
      }
      assert (cpt1 == n);
      assert (cpt2 == n - 1);
      //FOR(i,0,2*n-1) cout << p[i];
      //cout << endl;

      sort (all (Grow));
      sort (all (Gcol));
      //FOR(i,0,n) {FOR(j,0,n) cout << Grow[i][j] << " "; cout << endl;}
      //cout << endl;
      //FOR(i,0,n-1) {FOR(j,0,n) cout << Gcol[i][j] << " "; cout << endl;}
      //cout << endl;

      int ok = 1;
      int pass = 0;
      int ipass = -1;
      int icol;

      FOR (irow,0,n) {
	icol = irow - pass;
	if (icol == n-1) {
	  if (pass == 1) ok = false;
	  else {
	    pass = 1;
	    ipass = n-1;
	  }
	  break;
	}
	FOR (j,0,n) {
	  assert (icol >= 0);
	  if ((Grow[j][irow] != Gcol[icol][j])) {
	    if (pass == 1) {
	      ok = 0;
	    }
	    else {
	      pass = 1;
	      ipass = irow;
	      break;
	    }
	  }
	}
      }
      if (ok == 1) {
	cout << "Case #" << test << ": ";
	FOR(j,0,n) cout << Grow[j][ipass] << " ";
	cout << endl;
	break;
      }
    } while (next_permutation (p.begin(), p.end()));
  }
  return 0;
}
