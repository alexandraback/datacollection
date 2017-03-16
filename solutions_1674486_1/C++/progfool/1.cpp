#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;
void print(vector<bool> t) {
  for(int i=0;i<t.size();i++) cout << t [i] << " " ;
  cout << "\n";
}
vector<vector<int> > deps;
int N;
bool doDfs(int i, vector<bool>& visited) {
  for(int j=0;j<deps[i].size();j++) {
    if (visited[deps[i][j]]) return true;
    visited[deps[i][j]] = true;
    if (doDfs(deps[i][j], visited)) return true;
  }
  return false;
}
int main() {
  int T;
  scanf("%d",&T);
  for (int kase = 0 ; kase < T ; kase ++ ) {
    scanf("%d",&N);
    deps.clear();
    deps.resize(N+1);
    for(int i=0;i<N;i++) {
      int K;
      scanf("%d",&K);
      vector<int> me(K);
      for(int k=0;k<K;k++) {
        scanf("%d",&me[k]);
      }
      deps[i+1] = me;
    }
    bool done = false;
    for(int i=1;i<=N;i++) {
      vector<bool> visited(N+1, 0);
      visited[i] = true;
      if(doDfs(i, visited)) {
          done = true;
          break;
      }
    }
    printf("Case #%d: ", kase+1);
    if (done) printf("Yes");
    else printf("No");
    printf("\n");
  }
}
