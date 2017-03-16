#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <queue>
#include <list>
#include <stack>
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

string solve(string str){
  string ret = "";
  rep(i,str.length()){
    if(ret[0] <= str[i]){
      ret = string("") + str[i] + ret;
    }else{
      ret += string("") + str[i];
    }
  }
  return ret;
}

int main(){
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  rep(t,T){
    string str;
    cin >> str;
    string ret = solve(str);
    cout << "Case #" << t+1 << ": " << ret << endl;
  }
  
  return 0;
}

