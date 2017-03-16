#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<set>
#include<complex>
#include<map>
#include<list>
#include<deque>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>

#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int k,n;
vector<int> ans,path;
int memo[1<<20];
int c[300],kn[300],gk[300][500];

int rec(int state,vector<int> keys){
  if(state == (1<<n)-1){
    ans = path;
    return 1;
  }

  if(memo[state]>=0)return memo[state];
  
  rep(i,n){
    if( (state>>i)&1 )continue;
    if(keys[c[i]]){
      keys[c[i]]--;
      path.push_back(i+1);
      rep(j,kn[i])keys[gk[i][j]]++;

      if(rec(state|(1<<i),keys) == 1)return memo[state] = 1;

      rep(j,kn[i])keys[gk[i][j]]--;
      path.pop_back();
      keys[c[i]]++;
    }
  }
  return memo[state] = 0;
}

int main(){
  int testcase;
  int tmp;

  cin >> testcase;
  for(int casenum=1;casenum<=testcase;casenum++){
    vector<int> keys(201);
    for(int i=0;i<=200;i++)keys[i] = 0;

    cin >> k >> n;
    rep(i,k){ cin >> tmp; keys[tmp]++; }
    rep(i,n){
      cin >> c[i] >> kn[i];
      rep(j,kn[i])cin >> gk[i][j];
    }

    path.clear(); ans.clear();
    rep(i,1<<n)memo[i] = -1;

    rec(0,keys);

    cout << "Case #" << casenum << ": ";
    if(ans.empty())cout << "IMPOSSIBLE" << endl;
    else rep(i,n)cout << ans[i] << ((i==n-1)?"\n":" ");
  }
}
