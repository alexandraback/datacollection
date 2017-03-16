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
#define del(s,x) if(s.find(x)!=s.end()) s.erase(s.find(x))

#define FOR(i,a,b) for(int i=int(a); i<int(b); ++i)

bool comp(pair<int,int> a,pair<int,int> b) {return a.first < b.first; }


int main() {
  int T;
  cin >> T;
  cout.precision(12);
  FOR (test, 1, T+1) {
    int n;
    cin >> n;
    vector<int> v (n,0);
    FOR(i,0,n) cin >> v[i];

    priority_queue<pair<int, pair<int,int> > > s;
    int sum = 0, maxi = 0;
    FOR(i,0,n) {
      sum += (v[i]-1);
      maxi = max(maxi, v[i]);
      s.push (mp(v[i], mp(v[i],1)));
    }
    int mincost = maxi;
    FOR(val,1,sum+1) {
      pair<int, pair<int,int> > e = s.top();
      int d = e.second.first;
      int nb = e.second.second;
      nb++;
      s.pop ();
      s.push (mp((d + nb - 1) / nb, mp (d, nb)));
      mincost = min (mincost, val + s.top().first);
    }
    cout << "Case #" << test << ": " << mincost << endl;
  }
  return 0;
}
