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

int depth(int n, vector<vector<int> > &G, int v, int skip) {
  int maxi = 0;
  FOR(i,0,G[v].size()) {
    if (G[v][i] != skip) 
      maxi = max (maxi, depth(n,G,G[v][i],skip));
  }
  return 1 + maxi;
}

int main() {
  int T;
  cin >> T;
  cout.precision(12);
  FOR (test, 1, T+1) {
    int n;
    cin >> n;
    vector<int> BF(n,0);
    vector<vector<int> > G(n, vector<int> (0));
    FOR (i,0,n) {
      int v;
      cin >> v;
      v --;
      BF[i] = v;
      //if ((v > i) || ((v <= i) && BF[v] != i))
      G[v].pb(i);
    }
    int sum = 0;
    FOR(i,0,n) {
      if ((BF[BF[i]] == i) && (i < BF[i])) {
	//cout << i << " " << depth(n,G,i,BF[i]) << " " << depth(n,G,BF[i],i) << endl;
	sum += depth(n,G,i,BF[i]) + depth(n,G,BF[i],i);
      }
    }
    FOR(i,0,n) {
      int p = BF[i];
      FOR(j,0,n) {
	if (p == i) {
	  // cout << "cycle " << j+1 << endl;
	  sum = max (sum, j + 1);
	  break;
	}
	p = BF[p];
      }
    }
    cout << "Case #" << test << ": " << sum << endl;
  }
  return 0;
}
