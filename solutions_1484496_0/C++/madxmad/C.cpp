#include <cstdio>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef pair<int,int> pii;
typedef vector<int> vi;

int getsum(int n,int mask,vi &V){
  int sum = 0;
  for(int i=0;i<n;i++){
    if(mask & (1<<i)) sum += V[i];
  }
  return sum;
}

pii solve(int n,vi &V){
  map<int,int> M;

  int limit = 1<<n;
  for(int mask=1;mask<limit;mask++){
    //if(mask != 11264 && mask!=66112) continue;
    int sum = getsum(n,mask,V);
    if(M.count(sum)!=0)
      return make_pair(M[sum],mask);
    else
      M[sum] = mask;
  }
  return make_pair(0,0);
}

int show(int n,vi &V,int mask){
  bool first = true;
  //cout << "mask: " << mask << endl;
  for(int i=0;i<n;i++){
    if(mask & (1<<i)){
      if(first) first = false;
      else cout << " ";
      cout << V[i];
    }
  }
  cout << endl;
}

int main(){
  freopen("C.in","r",stdin);
  freopen("C.out","w",stdout);

  int T;
  cin >> T;
  for(int i=1;i<=T;i++){
    int N;
    vi V;
    cin >> N;
    for(int j=0;j<N;j++){
      int ni; cin >> ni;
      V.push_back(ni);
    }
    pii sol = solve(N,V);
    cout << "Case #" << i << ":" << endl;
    //cout << sol.first << " " << sol.second << endl;
    if(sol.first != 0){
      show(N,V,sol.first);
      show(N,V,sol.second);
    }
    else
      cout << "Impossible" << endl;
  }

}
