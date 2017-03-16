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


map<int, int> MM;

int main() {
  cout.precision(16);
  int T;
  cin >> T;
  for(int i = 1; i <= T; i++) {
    MM.clear();
    int N;
    cin >> N;
    VI S(N);
    bool ok = false;
    for(int n = 0; n < N; n++) cin >> S[n];

    cout << "Case #" << i << ":" << endl;
    for(int m = 1; m < (1 << N); m++) {
      int sum = 0;
      for(int j = 0; j < N; j++) if(m & (1 << j)) sum += S[j];

      if(MM[sum] != 0) {
        for(int j = 0; j < N; j++) if(m & (1 << j)) cout << S[j] << " ";
        cout << endl;
        for(int j = 0; j < N; j++) if(MM[sum] & (1 << j)) cout << S[j] << " ";
        cout << endl;
        ok = true;
        break;
      }
      else MM[sum] = m;
    }
    if(!ok) cout << "Impossible" << endl;

  }
}
