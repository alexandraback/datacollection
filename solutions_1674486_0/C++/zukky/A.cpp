#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX_N = 1010;
int N;
vector<int> E[MAX_N];
bool isRoot[MAX_N];
bool vis[MAX_N];

void init() {
  for(int i = 0; i < MAX_N; ++i) {
    E[i].clear();
    isRoot[i] = true;
  }
}

bool dfs(int p) {
  vis[p] = true;
  for(int i = 0; i < E[p].size(); ++i) {
    if(vis[E[p][i]]) return true;
    if(dfs(E[p][i])) return true;
  }
  return false;
}

int main() {
  int Tc;
  cin >> Tc;
  for(int tc = 1; tc <= Tc; ++tc) {
    init();
    cin >> N;
    for(int i = 1; i <= N; ++i) {
      int k;
      cin >> k;
      while(k--) {
	int to;
	cin >> to;
	isRoot[to] = false;
	E[i].push_back(to);
      }
    }

    bool flag = false;
    for(int i = 1; i <= N; ++i) {
      if(!isRoot[i]) continue;
      fill(vis,vis+N+1,false);
      //cout << i << endl;
      if(dfs(i)) {
	flag = true;
	break;
      }
    }
    cout << "Case #" << tc << ": ";
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  return 0;
}
