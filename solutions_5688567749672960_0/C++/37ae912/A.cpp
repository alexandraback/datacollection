// Author: Xujie Si
// Email: six@gatech.edu
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

#define FOR(i,X) for(int i=0;i<(X);++i)
#define PB(X) push_back( (X) )

typedef long long LL;
typedef vector<int> VI;

priority_queue<int> maxQ; // largest on the top
priority_queue<int, VI, greater<int> > minQ; // smallest on the top

auto cmp1 = [](int& a, int& b) -> bool {return a>b;};
auto dbg = ostream_iterator<int>(cerr, ",");


const int N = 1<<22;
int dp[N];

void init(){
  dp[1]=1;
  for(int i=2;i<=N;++i){
    int res = dp[i-1];
    

    if(i%10){
      int j = i;
      int k = 0;
      while(j){
	k = (j%10) + 10*k;
	j/=10;
      }

      if(k<i && dp[k] < res) res = dp[k];
    }

    dp[i] = res+1;
  }
}

void solve(){
	// exact implementation appears here
  int n;
  cin>>n;
  cout<<dp[n]<<endl;
}

int main()
{
  init();
  int cs = 0, T;
  scanf("%d",&T);
  while(++cs <= T){
    printf("Case #%d: ", cs);
    solve();
  }
  return 0;
}
