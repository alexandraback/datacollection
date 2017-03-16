// Authored by dolphinigle
// Codeforces #115
// 14 April 2012
// Author: Gerald, undef, ashmelev

#include <vector>
#include <list>
#include <map>
#include <set>

#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <assert.h>

#define FORN(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define REP(X,Y,Z) for (int (X) = (Y);(X) < (Z);++(X))

#define SZ(Z) ((int)(Z).size())
#define ALL(W) W.begin(), W.end()
#define PB push_back

#define MP make_pair
#define A first
#define B second

#define INF 1023123123
#define EPS 1e-11

#define MX(Z,Y) Z = max((Z),(Y))
#define MN(X,Y) X = min((X),(Y))

#define FORIT(X,Y) for(typeof((Y).begin()) X = (Y).begin();X!=(Y).end();X++)

using namespace std;

typedef long long ll;
typedef double db;
typedef vector<int> vint;

char itu[5000];

string init[5000];
string after[5000];

char nn[26];

int main() {
  
  int n;
  scanf("%d\n", &n);
  
  FORN(i, n) {
    scanf("%[^\n]\n", itu);
    init[i] = itu;
  }
  
  FORN(i, n) {
    scanf("%[^\n]\n", itu);
    after[i] = itu;
    cout << after[i] << endl;
  }  
  
  FORN(i, 26) nn[i] = 'a' + i;
  
  FORN(i, n) FORN(j, SZ(init[i])) if (init[i][j] != ' ') {
    char targ = after[i][j];
    int postarg = -1;
    FORN(k, 26) if (nn[k] == targ) postarg = k;
    // cout << postarg << " " << (init[i][j] - 'a') << endl;
    swap(nn[postarg], nn[init[i][j] - 'a']);
  }
  cout << "{";
  FORN(i, 26) {
    if (i) cout << ", ";
    cout << "'";
    cout << nn[i];
    cout << "'";    
  }
  cout << "}\n" << endl;
  
}
