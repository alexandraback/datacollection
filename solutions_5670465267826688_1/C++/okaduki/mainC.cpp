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

int tab[5][5] = {
  {0,0,0,0,0},
  {0,1,2,3,4},
  {0,2,-1,4,-3},
  {0,3,-4,-1,2},
  {0,4,3,-2,-1}
};

int sign(int x){
  return x / abs(x);
}

int main(){
  int T; cin >> T;
  FOR(t,1,T+1){
    LL L, X; cin >> L >> X;
    string tmp; cin >> tmp;
    string str;
    REP(i,min(8LL,X))
      str += tmp;
    L *= X;
    bool ok = false;
    int pr = 1, step = 2;
    for(int i=0;i<SZ(str);++i){
      pr = sign(pr) * tab[abs(pr)][str[i]-'i'+2];
      if(pr == step){
	if(step == 2)
	  step += 2;
	else{
	  step = -1;
	  break;
	}
      }
    }

    if(step < 0){
      pr = 1;
      for(int i=0;i<SZ(tmp);++i)
	pr = sign(pr) * tab[abs(pr)][tmp[i]-'i'+2];
      if(pr == -1) ok = X % 2 == 1;
      else if(pr != 1) ok = X % 4 == 2;
    }
    
    cout << "Case #" << t << ": " << (ok? "YES": "NO") << endl;
  }

  return 0;
}
