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

string short_str(const string& str){
  string ret = "";
  for(int i=0; i<str.length();){
    ret += str[i];
    int j = i;
    while(j<str.length() && str[i] == str[j]){ j++; }
    i = j;
  }
  return ret;
}

bool check(const string& str){
  for(int i=0; i<str.length();){
    int j = i;
    while(j<str.length() && str[i] == str[j]){ j++; }
    REP(k,j,str.length()){
      if(str[k] == str[i]) return false;
    }
    i = j;
  }
  return true;
}


ll solve(const vector<string>& v){
  ll ret = 0;
  vector<int> idx;
  rep(i,v.size()) idx.push_back(i);

  rep(i,v.size()){
    if(v[i].length()>=3){
      for(int j=1; j<v[i].length()-1; j++){
        rep(k,v.size()) if(i!=k){
          rep(l,v[k].length()){
            if(v[i][j] == v[k][l]) return 0;
          }
        }
      }
    }
  }

  
  do{
    string str = "";
    rep(i,v.size()){
      str += v[idx[i]];
    }

    if(check(str)){
      ret++;
    }

  }while(next_permutation(ALLOF(idx)));

  return ret;
}


int main(){
  int T;
  cin >> T;

  for(int t=0; t<T; t++){
    cerr << t << endl;
    int N;
    cin >> N;
    
    string str;
    vector<string> v;
    rep(i,N){
      cin >> str;
      v.push_back(short_str(str));
    }

    cout << "Case #" << t+1 << ": " << solve(v) << endl;
  }
  
  return 0;
}
