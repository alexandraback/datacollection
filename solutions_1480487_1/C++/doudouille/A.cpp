#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <cmath>
using namespace std;

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef long long LL;
typedef stringstream SS;


#define pb(x) push_back(x)
#define ins(x) insert(x)
#define sz size()
#define len length()

#define REP(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,b) for(int i=(a),_d=((a)<(b))?1:-1; _d*i<=_d*(b); i+=_d)
#define FOREACH(it,s) for (typeof((s).begin()) it = (s).begin(); it != (s).end(); ++it)
#define SORT(x) (sort((x).begin(),(x).end()))
#define UNIQ(x) ((x).erase(unique((x).begin(),(x).end()),(x).end()))

#define INF 2147450751




int main() {
  cout.precision(16);
  int T;
  cin >> T;
  for(int i = 1; i <= T; i++) {
    int N;
    cin >> N;
    VI J(N);
    for(int n = 0; n < N; n++) cin >> J[n];
    VI J2(J);
    SORT(J2);
    int S = 0;
    for(int n = 0; n < N; n++) S += J[n];
    J2.push_back(2*S);


    int X = 0;
    cout << "Case #" << i << ": ";
    
      int R = 0, k = 0, nb = 0;
      for(k = 0; k < N+1; k++) {
        R = 0;
        nb = 0;
        for(int j = 0; j < N; j++) if(J2[k] > J[j]) {nb++; R += J2[k] - J[j];}
        if(R >= S) break;
      }
      double sc = J2[k] - (R - S)/double(nb);
    for(int n = 0; n < N; n++) cout << 100*max(sc - J[n], 0.)/double(S) << " " ;
    cout << endl;
  }
}
