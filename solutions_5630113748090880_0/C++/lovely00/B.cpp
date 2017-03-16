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

const int N = 3000;
int d[N];

void solve(){
	// exact implementation appears here
  
  for(int i=0;i<N;++i) d[i] = 0;
  

  int n;
  cin >> n;
  
  for(int i=0;i < 2 * n-1; ++i){
    for(int j = 0; j < n; ++j) {
      int x;
      cin >> x;
      d[x]++; 
    }
  }

  vector<int> v;
  for(int i=0;i<N;++i){
    if(d[i]%2) {
      v.PB(i);
    }
  }

  sort(v.begin(), v.end());

  if(v.size() != n){
    cerr << "error: v.size=" << v.size() << ", n="<<n<<endl;
  }
  
  for(int i=0;i<v.size(); ++i){
    cout <<" "<<v[i];
  }
  cout<<endl;

}

int main()
{
  int cs = 0, T;
  scanf("%d",&T);
  while(++cs <= T){
    printf("Case #%d:", cs);
    solve();
  }
  return 0;
}
