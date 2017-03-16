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
 
template<class T> inline bool comp(T a, T b) {return a>b;} // sort(t, t+9, comp<int>);

#define FOR(i,a,b) for(int i=int(a); i<int(b); ++i)

bool matching_rec (vector<vector<int> > &G, vector<int> &mata, vector<int> &matb, vector<bool> &vis, int v) {
  if (v == -1) return true;
  if (vis[v]) return false;
  vis[v] = true; 
  int n = G[v].size();
  for (int j = 0; j < n; j++) {
    int w = G[v][j];
    if (matching_rec(G,mata,matb,vis,matb[w])) {
      mata[v] = w;
      matb[w] = v;
      return true;
    }
  }
  return false;
}

/* We want to find a matching of bipartite graph G. Let call Ea (of size na) and Eb (of size nb) the first and second set of vertices.
   --> G should be of lenght na, and for i in Ea, G[i] should be the list of vertices adjacent to i (which are in Eb).  
   --> for i in Ea, mata[i] is the vertex of Eb to which i is matched (or -1 if not matched) 
   --> for i in Eb, matb[i] is the vertex of Ea to which i is matched (or -1 if not matched)
 */
int matching (vector<vector<int> > &G, vector<int> &mata, vector<int> &matb) {
  int na = G.size();
  int cpt = 0;
  for (int i = 0; i < na; i++) {
    vector<bool> vis(na,false);
    if (matching_rec (G,mata,matb,vis,i))
      cpt++;
  }
  return cpt;
}

int main() {
  int T;
  cin >> T;
  cout.precision(12);

  FOR (test, 1, T+1) {
    map<string,int> E1;
    map<string,int> E2;
    int z;
    cin >> z;
    int nb1 = 0, nb2 = 0;
    vector<vector<int> > G(0);
    FOR(i,0,z) {
      string a, b;
      cin >> a >> b;
      if (!present(E1,a)) {
	E1.insert (mp (a,nb1));
	nb1++;
	G.pb(vector<int>(0));
      }
      if (!present (E2,b)) {
	E2.insert (mp (b,nb2));
	nb2++;
      }
      G[E1[a]].pb(E2[b]);
    }
    vector<int> mata(nb1,-1);
    vector<int> matb(nb2,-1);
    int p = matching (G, mata, matb);
    int sol = z - (nb1 + nb2 - p);
    
    cout << "Case #" << test << ": " << sol << endl;
  }
  return 0;
}
