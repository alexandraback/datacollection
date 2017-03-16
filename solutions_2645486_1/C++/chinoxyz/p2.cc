#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
#include <iostream>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
using namespace std;

class par{
  public:
  int i;
  int val;
  bool operator<(const par &s) const {
    return (val < s.val);
  }
};
int T;
int E, R, N, val;
par p;
vector<int> v;
vector<par> v2;
vector<long long> r;
long long res;
int main(){
  
  scanf("%d", &T);
  for(int t  = 0; t < T; t++){
    scanf("%d %d %d", &E, &R, &N);
    v.clear();
    v2.clear();
    r.clear();
    r.push_back(E);
    for(int i = 0; i < N; i++){
      scanf("%d", &val);
      v.push_back(val);
      p.i = i;
      p.val = val;
      v2.push_back(p);
      r.push_back(R);
    }
    sort(v2.begin(), v2.end());
    reverse(v2.begin(), v2.end());
    res = 0;
    for(int i = 0; i < N; i++){
      long long sum = E;
      int j = v2[i].i;
      
      while(sum > 0 && j >= 0){
        int minimo = min(r[j], sum); 
        sum = sum - minimo;
        r[j] = r[j] - minimo;
        j--;
        
      }
      res += (E - sum)*v2[i].val ;
      //printf("%lld %d %d\n", res,v2[i].val, (E - sum));
    }
    
    
    /*long long res = 0;
    int e = E;
    for(int i = 0; i < N; i++){
      res += e*v[i];
      e = min(R, E);
      //printf("%d %d %lld)\n", e, v[i], res);
    }*/
    printf("Case #%d: %lld\n", t+1, res);
    //break;
  }
}
