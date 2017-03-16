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
/*
bool possible(vector<int> coins, int C, vector<int> P) {
  if(coins.size() == 0) {
    for(int i = 0; i < P.size(); i++) if(!P[i]) return false;
    return true;
  }
  vector<int> NP = P;
  int val = coins.back();
  coins.pop_back();

  for(int c = 1; c <= C; c++) 
    for(int i = 0; i + c*value < possible.size(); i++) 
      if(possible[i])
        NP[i+c*value] = 1;

  return possible(coins, C, NP);
}
*/

vector<int> add_possible(int val, vector<int> P) {
  vector<int> NP = P;
  for(int i = 0; i + val < P.size(); i++) if(P[i]) NP[i+val] = 1;
  return NP;
}

int first_val(vector<int> P) {
  for(int i = 0; i < P.size(); i++) if(P[i] == 0) return i;
  return -1;
}


int main() {
  cout.precision(16);
  int N,C, D, V;
  cin >> N;
  for(int i = 1; i <= N; i++) {
    cin >> C >> D >> V;
    vector<int> Coins(D);
    for(int j = 0; j < D; j++) cin >> Coins[j];

    vector<int> P0(V+1);
    P0[0] = 1;
    for(int j = 0; j < D; j++) P0 = add_possible(Coins[j], P0);

    int nb = 0;
    while(true) {
      int val = first_val(P0);
      if( val == -1) break;
      P0 = add_possible(val, P0);
      nb++;
    }
    cout << "Case #" << i << ": " << nb << endl;
  }
}
