#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include<cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include<bitset>

#define REP(i,b,n) for(int i=b;i<(int)n;i++)
#define rep(i,n)   REP(i,0,n)
#define ALL(C)     (C).begin(),(C).end()
#define FOR(it,o)  for(__typeof((o).begin()) it=(o).begin(); it!=(o).end(); ++it)
#define dbg(x) cerr << #x << " = " << (x) << endl


typedef long long ll;

using namespace std;

class Data{
public:
  static const long double INF = (1LL<<30);
  long double keep, enter;
  vector<long double> BS;
  Data(){
    BS.clear();
    keep = enter = 0;
  }
  Data(int pos){
    BS = vector<long double>(pos);
    keep = enter = 0;
  }
  //次合うべき場所、長さ、次打つべき場所
  Data(int cPos, int len, int pos, long double prob){
    //すべてあってる場合
    if(cPos == pos){
      keep = prob * (long double)(len - pos + 1);
    }
    else{
      keep = prob * (long double)(len + 1 + len - pos + 1);
    }
    //BS 連打
    REP(i, 1, pos+1){
      int newPos = pos - i;
      if(newPos <= cPos){
	BS.push_back(prob*(long double)(len - newPos + 1 + i));
      }
      else{
	BS.push_back(prob*(long double)(len+1+len-newPos+1 + i));
      }
    }
    enter = prob * (long double)(len+2);
  }
  Data operator+(const Data &d)const{
    Data ret = *this;
    ret.keep += d.keep;
    ret.enter += d.enter;
    rep(i, d.BS.size()){
      ret.BS[i] += d.BS[i];
    }
    return ret;
  }
  long double getMin(){
    long double ret = (1LL<<30);
    rep(i, BS.size()){
      ret = min(BS[i], ret);
    }
    ret = min(keep, ret);
    ret = min(enter, ret);
    return ret;
  }
};

int main(){

  int T;
  cin >> T;
  rep(tc, T){
    long double prob = 1;
    int pos, len;
    cin >> pos >> len;
    vector<long double> P(pos);
    rep(i, pos)cin >> P[i];
    Data res = Data(pos);
    rep(i, pos){
      //correct
      if(i+1 == pos)res = res + Data(i+1, len, pos, prob*(P[i]));
      //incorrect
      res = res + Data(i, len, pos, prob*(1.0 - P[i]));
      prob *= P[i];
    }
    printf("Case #%d: %.9Lf\n",tc+1, res.getMin());
  }
  
  
  return 0;
}
