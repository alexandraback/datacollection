#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>

using namespace std;

#define FOR(i,k,n) for(int i=(k); i<(int)n; ++i)
#define REP(i,n) FOR(i,0,n)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

template<class T> void debug(T begin, T end){ for(T i = begin; i != end; ++i) cout<<*i<<" "; cout<<endl; }

typedef long long ll;
const int INF = 100000000;
const double EPS = 1e-8;
const int MOD = 1000000007;

int main(){
  int T; cin>>T;
  REP(testcase, T){
    int N; cin>>N;
    vector<int> v(N);
    REP(i,N)cin>>v[i];
    vector<int> checker;
    map<int, vector<int> > cnt;
    REP(s, 1<<N){
      int sum = 0;
      REP(j, N) if(s >> j & 1) sum += v[j];
      cnt[sum].push_back(s);
      if(cnt[sum].size() == 2) checker.push_back(sum);
    }
    int ans1 = -1, ans2 = -1;
    REP(i, checker.size()){
      vector<int> chk = cnt[checker[i]];
      REP(j, chk.size()){ 
        FOR(k, j + 1, chk.size()){ 
          if((chk[j] & chk[k]) == 0){
            ans1 = chk[j];
            ans2 = chk[k];
            goto OUTPUT;
          }
        }
      }
    }
    OUTPUT:
    printf("Case #%d:\n", testcase + 1);
    if(ans1 == -1) cout<<"Impossible"<<endl;
    else{
      bool f;
      f = false;
      REP(i,N)if(ans1 >> i & 1){
        if(f) putchar(' ');
        else f = true;
        printf("%d", v[i]);
      }
      putchar('\n');
      f = false;
      REP(i,N)if(ans2 >> i & 1){
        if(f) putchar(' ');
        else f = true;
        printf("%d", v[i]);
      }
      putchar('\n');
    }
  }
  return 0;
}

