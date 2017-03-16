#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <queue>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;

inline int str2int(const string& str){
  int ret = 0;
  int p = 1;
  for(int i=str.length()-1; i>=0; i--){
    ret += (str[i]-'0')*p;
    p *= 10;
  }
  return ret;
}
  
ll calc(int A, int B, int n, string str){
  set<string> check;
  ll ret = 0;
  string tmp = str;
  rep(i,str.length()-1){
    tmp = tmp.substr(1) + tmp[0];
    if(tmp[0]=='0') continue;
    int m = str2int(tmp);
    if(n < m && m<=B){
      //cout << str << "->" << tmp << endl;
      if(check.count(tmp)==0){
        check.insert(tmp);
        ret++;
      }
    }
  }
  return ret;
}

ll solve(int A, int B){
  ll ret = 0;
  REP(n,A,B+1){
    stringstream ss;
    ss << n;
    ret += calc(A, B, n, ss.str());
  }

  return ret;
}

int main(){
  int T;
  int A, B;
  cin >> T;  
  rep(t,T){
    cin >> A >> B;
    cout << "Case #" << t+1 << ": " << solve(A, B) << endl;
  }
  
  return 0;
}
