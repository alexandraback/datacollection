#include <algorithm>
#include <cassert>
#include <cstdio>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define ASSERT_ for (;;) {}
#define PII pair<long long, long long>

#define REP(i,n)    for(long long i=0; i<(n); ++i)
#define FOR(i,p,k)  for(long long i=(p); i<=(k); ++i)
#define FORD(i,p,k) for(long long i=(p); i>=(k); --i)
using namespace std;
long long n, m;
vector< PII > first,second;
  vector< PII > dodatkowy;

long long solve_1(){
  long long sum = 0;
  REP(i, second.size()){
    if (second[i].first == first[0].first)
      sum += second[i].second;
  }
  return min(sum, first[0].second);
}

long long solve_1_dodatek(){
  long long sum = 0;
  REP(i, second.size()){
    if (second[i].first == dodatkowy[0].first)
      sum += second[i].second;
  }
  return min(sum, dodatkowy[0].second);
}


long long solve_2(){
  long long max_res;
  max_res = -1;
  REP(i,second.size()){
    long long sum_left, sum_right;
    sum_left = 0; sum_right = 0;
    
    REP(j, i){
      if (second[j].first == first[0].first)
        sum_left += second[j].second;
    }
    FOR(j, i, second.size() - 1){
      if (second[j].first == first[1].first)
        sum_right += second[j].second;
    }
    sum_left = min(sum_left, first[0].second);
    sum_right = min(sum_right, first[1].second);
    max_res = max(max_res, sum_left + sum_right);
  }
  return max_res;
}

long long solve_2_with_jump(){
  dodatkowy.clear();
  dodatkowy.push_back(first[0]);
  if (first[0].first == first[2].first)
    dodatkowy[0].second += first[2].second;
  else
    dodatkowy.push_back(first[2]);


  if (dodatkowy.size() > 1){
  long long max_res;
  max_res = -1;
  REP(i,second.size()){
    long long sum_left, sum_right;
    sum_left = 0; sum_right = 0;
    
    REP(j, i){
      if (second[j].first == dodatkowy[0].first)
        sum_left += second[j].second;
    }
    FOR(j, i, second.size() - 1){
      if (second[j].first == dodatkowy[1].first)
        sum_right += second[j].second;
    }
    sum_left = min(sum_left, dodatkowy[0].second);
    sum_right = min(sum_right, dodatkowy[1].second);
    max_res = max(max_res, sum_left + sum_right);
  }
  return max_res;}
  else
    return solve_1_dodatek();
}

long long solve_3(){
  long long max_res;
  max_res = -1;
  REP(i,second.size()){
    FOR(j,i,second.size() - 1){
      long long sum_left, sum_right, sum_middle;
      sum_left = 0; sum_right = 0; sum_middle = 0;
      REP(k, i){
        if (second[k].first == first[0].first)
          sum_left += second[k].second;
      }
      FOR(k, i, j-1){
        if (second[k].first == first[1].first)
          sum_middle += second[k].second;
      }
      FOR(k, j, second.size() - 1){
        if (second[k].first == first[2].first)
          sum_right += second[k].second;
      }
      sum_left = min(sum_left, first[0].second);
      sum_middle = min(sum_middle, first[1].second);
      sum_right = min(sum_right, first[2].second);
      //printf("%lld %lld:%lld %lld %lld\n", i,j, sum_left, sum_middle, sum_right);

      max_res = max(max_res, sum_left + sum_middle + sum_right);
      //printf("max_res: %lld\n", max_res);
    }
  }
  return max(max_res, solve_2_with_jump());
}

long long solve(){
  switch(n){
    case 1:
      return solve_1();
    case 2:
      return solve_2();
    case 3:
      return solve_3();
  }

  return -1;
}

int main() {
  ios_base::sync_with_stdio(0);
  long long ntestcase;
  cin >> ntestcase;
  for (long long test_id = 1; test_id <= ntestcase; test_id++) {
    cin >> n >> m;
    first.clear(); second.clear();
    long long a,b, iter;
    iter = 0;
    REP(i,n){
      
      cin >> a >> b;
      /*if (i>0 && first[iter-1].first == b)
        first[iter-1].second += a;
      else{*/
        first.push_back(make_pair(b,a));
        /*iter += 1;
      }*/
    }
    iter = 0;
    REP(i,m){
      cin >> a >> b;
      second.push_back(make_pair(b,a));
    }
      

    printf("Case #%lld: %lld\n", test_id, solve());

  }

  return 0;
}
