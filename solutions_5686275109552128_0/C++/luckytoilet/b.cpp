#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <climits>
#include <queue>
#define LL long long
#define ULL unsigned long long
#define ABS(a) (((a) > 0) ? (a) : (-(a)))
#define MAX(a,b) (((a)>(b)) ? (a) : (b))
#define MIN(a,b) (((a)<(b)) ? (a) : (b))
using namespace std;
template<typename T> ostream& operator<<(ostream& s, vector<T>& v) {
  s << '{';
  for (int i = 0 ; i < v.size(); ++i)
    s << (i ? "," : "") << v[i];
  return s << '}';
}
template<typename S, typename T> ostream& operator<<(ostream &s, pair<S,T>& p){
  return s << "(" << p.first << "," << p.second << ")";
}

int D;
vector<int> ps;
map< vector<int>, int > dp;

int ceil2(int n){
  int m = n/2;
  if(m*2 == n) return m;
  return m+1;
}

int vec_max(vector<int> &v){
  int m=0;
  for(int i=0;i<v.size();i++)
    if(v[i]>m) m=v[i];
  return m;
}

int bruteforce(vector<int> pv){
  if(pv.size() == 0) return 0;

  sort(pv.begin(), pv.end());
  reverse(pv.begin(), pv.end());

  if(dp.find(pv) != dp.end())
    return dp[pv];

  int big = pv[0];

  int m = vec_max(pv);
  if(m <= 1) return m;

  int best_score = m;
  for(int small1 = 1; ; small1++){
    int small2 = big - small1;
    if(small2 < small1) break;
    vector<int> p2 = pv;
    p2.erase(p2.begin());
    p2.push_back(small1);
    p2.push_back(small2);
    int cur_score = 1 + bruteforce(p2);
    if(cur_score < best_score)
      best_score = cur_score;
  }
  dp[pv] = best_score;
  return best_score;
}

int main(){

  int TC;cin>>TC;
  for(int tc=1; tc<=TC; tc++){
    cin>>D;
    ps.clear();
    for(int i=0; i<D; i++){
      int t; cin>>t;
      ps.push_back(t);
    }

    /*
    // incrementally split the max to increase score until we can't
    int minscore = 999999999;
    int splitcost = 0;
    while(true){
      int sc_nosplit = splitcost + ps.top();

      // split biggest into two
      int big = ps.top();
      ps.pop();
      int small1 = ceil2(big);
      int small2 = big - small1;
      ps.push(small1);
      ps.push(small2);

      splitcost++;
      int sc_split = splitcost + ps.top();

      minscore = MIN(MIN(minscore,sc_split), sc_nosplit);
      if(big <= 1) break;
    }
    */

    printf("Case #%d: %d\n", tc, bruteforce(ps));
  }
}

