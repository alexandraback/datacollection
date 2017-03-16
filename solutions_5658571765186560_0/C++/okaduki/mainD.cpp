//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <set>
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
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <climits>
#include <queue>
 
using namespace std;
 
//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;
 
//container util
//------------------------------------------
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
 
//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
 
//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI = acos(-1.0);


int main(){
  int T; cin >> T;
  FOR(t,1,T+1){
    int X, R, C; cin >> X >> R >> C;
    if(R > C) swap(R, C);
    bool ok = true;
    // R <= C
    switch(X){
    case 1: break;
    case 2: ok = R*C % 2 == 0; break;
    case 3:
      switch(R){
      case 1: ok = false; break;
      case 2: if(C == 2 || C == 4) ok = false; break;
      case 3: break; //if(R == 3) ok = false; break;
      case 4: ok = false; break;
      }
      break;
    case 4:
      if(C < 4) ok = false;
      else if(R == 1 || R == 2) ok = false;
    }

    cout << "Case #" << t << ": " << (ok? "GABRIEL": "RICHARD") << endl;
  }
  
  return 0;
}
