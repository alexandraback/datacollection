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

map<int,vector<int> > memo;

void solve(int N, vector<int> v){
  sort(ALLOF(v));
  memo.clear();
  
  for(int S=0; S<(1<<N); S++){
    vector<int> tmp;
    int sum = 0;
    rep(i,N) if(S>>i&1){
      tmp.push_back(v[i]);
      sum += v[i];
    }

    if(memo.count(sum)>0){
      vector<int> ret1 = memo[sum];
      rep(i,ret1.size()){
        printf("%d", ret1[i]);
        if(i!=ret1.size()-1) printf(" ");
      }
      printf("\n");
      rep(i,tmp.size()){
        printf("%d", tmp[i]);
        if(i!=tmp.size()-1) printf(" ");
      }
      printf("\n");
      return;
    }
    memo[sum] = tmp;
  }
  printf("Impossible\n");
}

int main(){
  int T;
  cin >> T;
  
  rep(t,T){
    vector<int> v;
    int N;
    int tmp;
    cin >> N;
    rep(i,N){
      cin >> tmp;
      v.push_back(tmp);
    }
    printf("Case #%d: \n", t+1);
    solve(N, v);
  }
  
  return 0;
}
