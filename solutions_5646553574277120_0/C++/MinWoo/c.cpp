
/*********************************
 * Google Codejam 2015: Round 1C
 * Author: MinWoo Byeon 
 *********************************/

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <queue>
using namespace std;

pair<bool, vector<bool> > check(const vector<int>& coins, const int V) {
  const int N = coins.size();
  vector<bool> make(V+1);
  //cout << N << endl;

  make[0] = true;
  for ( int i=0 ; i<N ; ++i ) {
    for ( int j=V ; j>=coins[i] ; --j ) {
      if ( make[j-coins[i]] ) {
        make[j] = true;
      }
    }
  }
  
  bool res = true;
  for ( int i=1 ; i<=V ; ++i ) {
    if ( not make[i] ) {
      res = false;
      break;
    }
  }
  return make_pair(res, make);
}

int main() {
  int TC;
  cin >> TC;
  for ( int tc=1 ; tc<=TC ; ++tc ) {
    int res = 1e9;

    int C, D, V;
    cin >> C >> D >> V;
    vector<int> coins(D);
    for ( int i=0 ; i<D ; ++i ) {
      cin >> coins[i];
    }

    queue< vector<int> > q;
    q.push(coins);
    while ( not q.empty() ) {
      vector<int> curr = q.front(); q.pop();
      pair<bool, vector<bool> > checked = check(curr, V);
      if ( checked.first ) {
        res = min(res, (int)(curr.size()));
      }
      else {
        for ( int i=1 ; i<=V ; ++i ) {
          if ( checked.second[i] ) continue;

          bool ok = true;
          for ( int j=0 ; j<curr.size() ; ++j ) {
            if ( curr[j] == i ) {
              ok = false;
              break;
            }
          }
          if ( ok ) {
            curr.push_back(i);
            if ( curr.size() < res ) {
              q.push(curr);              
            }
            curr.pop_back();
          }
        }
      }
    }

    printf("Case #%d: %d\n", tc, res - coins.size());
  }
}

