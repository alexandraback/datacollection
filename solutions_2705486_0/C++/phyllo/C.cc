#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <fstream>
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

struct ST {
  int i;
  int cnt;
};

//vector<string> dics;
int dp[4010][6];

vector<string> getKouho(const string& S, int i){
  vector<string> ret;
  ifstream ifs("garbled_email_dictionary.txt");
  string tmp;
  while(ifs >> tmp){
    if(i+tmp.length() > S.length()) continue;
    int cnt = 0;
    rep(j,tmp.length()){
      if(S[i+j] != tmp[j]) cnt++;
    }
    if(cnt<=3){
      ret.push_back(tmp);
    }
  }

  return ret;
}


pair<int,int> check(const string& S, int i, int j, const string& kouho){
  int cnt = 0;
  int last = -j;
  rep(k,kouho.length()){
    if(kouho[k] != S[i+k]){
      if(k<5-j || k-last<5) return make_pair<int,int>(-1,-1);
      cnt++;
      last = k;
    }
  }
  last = kouho.length()-last;
  if(last > 5) last = 5;
  return make_pair<int,int>(last, cnt);
}

int solve(string S){
  int ret = 10000000;
  rep(i,4010) rep(j,6) dp[i][j] = -1;

  dp[0][5] = 0;
  
  rep(i,S.length()){
    vector<string> kouho = getKouho(S, i);

    rep(k,kouho.size()){
      for(int j=5; j>0; j--){
        if(dp[i][j]!=-1){
          pair<int,int> res = check(S, i, j, kouho[k]);
          if(res.first < 0) continue;

          //cerr << i << " " << kouho[k] << endl;
          if(dp[i+kouho[k].length()][res.first] == -1){
            dp[i+kouho[k].length()][res.first] = dp[i][j] + res.second;
          }else{
            dp[i+kouho[k].length()][res.first] = min(dp[i+kouho[k].length()][res.first], dp[i][j] + res.second);
          }
          
        }
      }
    }
  }

  rep(i,6){
    if(dp[S.length()][i] != -1){
      ret = min(ret, dp[S.length()][i]);
    }
  }
  return ret;
}

int main(){

  
  int T;
  cin >> T;
  
  rep(t,T){
    string S;
    cin >> S;
    
    cout << "Case #" << t+1 << ": " << solve(S) << endl;
  }
  
  return 0;
}
