#include <cstdio>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

const int MX = (1<<20) +20;
stack<int> sol;

int n,k,a,b;
bool V[MX];

int keys[300];

int chest_lock[30];
vector<int> chest_keys[30];

bool dp(int s) {
  if(V[s]) return false;
  V[s] = true;
  if(s==0) return true;
  for(int i=0; i<n; ++i) {
    if((s&(1<<i)) > 0 && keys[chest_lock[i]] > 0) {
      keys[chest_lock[i]]--;
      for(int j=0; j<chest_keys[i].size(); ++j) keys[chest_keys[i][j]]++;
      if (dp(s&(~(1<<i)))) {
        sol.push(i);
        return true;
      }
      for(int j=0; j<chest_keys[i].size(); ++j) keys[chest_keys[i][j]]--;
      keys[chest_lock[i]]++;

    }
  }
  return false;
}


void solve(int c) {
  scanf("%d%d", &k, &n);
  for(int i=0; i<300; ++i) keys[i] = 0;
  for(int i=0; i<(1<<n); ++i) V[i] = false;
  for(int i=0; i<k; ++i) {
    scanf("%d", &a);
    keys[a]++;
  }
  for(int i=0; i<n; ++i) {
    chest_keys[i].clear();
    scanf("%d", chest_lock + i);
    scanf("%d", &a);
    while(a--) {
      scanf("%d", &b);
      chest_keys[i].push_back(b);
    }
  }
  int s = 0;
  for(int i=0; i<n; ++i) s+=(1<<i);
  if(dp(s)) {
    printf("Case #%d: ", c);
    bool first = true;
    while(!sol.empty()) {
      if(first) first = false;
      else printf(" ");
      printf("%d", sol.top() + 1);
      sol.pop();
    }
    printf("\n");
  } else {
    printf("Case #%d: IMPOSSIBLE\n", c);
  } 
}

int main() {
  int ntc;
  scanf("%d", &ntc);
  for(int i=1; i<=ntc; ++i) {
    solve(i);
  }  
}
