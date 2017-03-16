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



ll solve(const string& str){
  map<char,int> memo;
  rep(i,str.length()){
    memo[str[i]]++;
  }
  map<int,int> ret;
  if(memo['Z'] > 0){
    ret[0] = memo['Z'];
    memo['Z'] -= ret[0];
    memo['E'] -= ret[0];
    memo['R'] -= ret[0];
    memo['O'] -= ret[0];
  }
  if(memo['W'] > 0){
    ret[2] = memo['W'];
    memo['T'] -= ret[2];
    memo['W'] -= ret[2];
    memo['O'] -= ret[2];
  }
  if(memo['U'] > 0){
    ret[4] = memo['U'];
    memo['F'] -= ret[4];
    memo['O'] -= ret[4];
    memo['U'] -= ret[4];
    memo['R'] -= ret[4];
  }
  if(memo['X'] > 0){
    ret[6] = memo['X'];
    memo['S'] -= ret[6];
    memo['I'] -= ret[6];
    memo['X'] -= ret[6];
  }
  if(memo['G'] > 0){
    ret[8] = memo['G'];
    memo['E'] -= ret[8];
    memo['I'] -= ret[8];
    memo['G'] -= ret[8];
    memo['H'] -= ret[8];
    memo['T'] -= ret[8];
  }
  if(memo['O'] > 0){
    ret[1] = memo['O'];
    memo['O'] -= ret[1];
    memo['N'] -= ret[1];
    memo['E'] -= ret[1];
  }
  if(memo['R'] > 0){
    ret[3] = memo['R'];
    memo['T'] -= ret[3];
    memo['H'] -= ret[3];
    memo['R'] -= ret[3];
    memo['E'] -= ret[3];
    memo['E'] -= ret[3];
  }
  if(memo['F'] > 0){
    ret[5] = memo['F'];
    memo['F'] -= ret[5];
    memo['I'] -= ret[5];
    memo['V'] -= ret[5];
    memo['E'] -= ret[5];
  }
  if(memo['V'] > 0){
    ret[7] = memo['V'];
    memo['S'] -= ret[7];
    memo['E'] -= ret[7];
    memo['V'] -= ret[7];
    memo['E'] -= ret[7];
    memo['N'] -= ret[7];
  }
  if(memo['I'] > 0){
    ret[9] = memo['I'];
  }

  rep(i,10){
    int num = ret[i];
    rep(j,num){
      cout << i;
    }
  }
  
}

int main(){
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  rep(t,T){
    string str;
    cin >> str;
    cout << "Case #" << t+1 << ": ";
    solve(str);
    cout << endl;
  }
  
  return 0;
}

