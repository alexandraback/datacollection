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

int vec_max(vector<int> &v){
  int m=0;
  for(int i=0;i<v.size();i++)
    if(v[i]>m) m=v[i];
  return m;
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

    int M = vec_max(ps);
    int best = 999999999;
    for(int m=1; m<=M; m++){
      int tot = 0;
      for(int i=0; i<ps.size(); i++){
        int q = ps[i] / m;
        if(q*m == ps[i]){
          tot += q-1;
        }
        else{
          tot += q;
        }
      }
      tot = tot + m;
      if(tot < best){
        best = tot;
      }
    }

    printf("Case #%d: %d\n", tc, best);
  }
}

