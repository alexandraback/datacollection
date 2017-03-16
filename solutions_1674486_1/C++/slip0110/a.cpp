#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
#include<deque>
#include<queue>
#include<complex>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<cstdlib>

using namespace std;

#define REP(i,a,n) for(int i = a ; i < n ; i++)
#define rep(i,n) REP(i,0,n)

typedef long long ll;

vector<int> G[1010];
vector<int> start;
int n;
bool use[1010];
bool res;

void solve(int cur){
  //cout<<cur<<endl;
  if(use[cur]){
    res = true;
    return;
  }
  use[cur] = true;
  rep(i,G[cur].size()){
    solve(G[cur][i]);
  }
}

int main(){
  int T;
  cin>>T;
  for(int t  = 1;  t <= T ; t++){
    rep(i,1010){
      G[i].clear();
    }
    start.clear();

    cin>>n;
    rep(i,n){
      int m;
      cin>>m;
      rep(j,m){
        int a;
        cin>>a;
        a--;
        G[a].push_back(i);
      }
      if(m == 0)start.push_back(i);
    }

    res = false;
    rep(i,start.size()){
      memset(use , 0 , sizeof(use));
      solve(start[i]);
    }
    printf("Case #%d: ",t);
    if(res){
      cout<<"Yes\n";
    }
    else{
      cout<<"No\n";
    }
  }
}
