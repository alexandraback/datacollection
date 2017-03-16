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

static const string mapping[] = {
  "y", //a
  "h", //b
  "e", //c
  "s", //d
  "o", //e
  "c", //f
  "v", //g
  "x", //h
  "d", //i
  "u", //j
  "i", //k
  "g", //l
  "l", //m
  "b", //n
  "k", //o
  "r", //p
  "z", //q
  "t", //r
  "n", //s
  "w", //t
  "j", //u
  "p", //v
  "f", //w
  "m", //x
  "a", //y
  "q" //z
  };

string solve(const string& text){
  string ret = "";
  rep(i,text.length()){
    if(text[i]==' ') ret += " ";
    else ret += mapping[text[i]-'a'];
  }
  return ret;
}

int main(){
  int T;
  string text;

  cin >> T;
  getline(cin, text);
  
  rep(t,T){
    getline(cin, text);
    cout << "Case #" << t+1 << ": " << solve(text) << endl;
  }
  
  return 0;
}
