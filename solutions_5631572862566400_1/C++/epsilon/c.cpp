#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1001;

int bff[MAXN];

bool visited[MAXN];

pair<int, int> dfs(int vert){
  pair<int, int> ans;
  if(visited[vert]){
    ans.first = vert;
    ans.second = 0;
    return ans;
  }
  visited[vert] = true;
  ans = dfs(bff[vert]);
  ans.second++;
  return ans;
}

vector<vector<int> > rGraph;

int maxPath(int vert){
  int mPath = 0;
  for(int nbh : rGraph[vert]){
    mPath = max(mPath, maxPath(nbh));
  }
  return mPath + 1;
}

int main(){
  int t;
  cin >> t;
  for(int cas = 1; cas <= t; cas++){
    cout << "Case #" << cas << ": ";
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
      cin >> bff[i];
      bff[i]--;
    }
    int mCycle = -1;
    /// find cycles
    for(int i = 0; i < n; i++){
      memset(visited, false, sizeof(visited));
      auto end = dfs(i);
      if(end.first == i && end.second > 2){
        mCycle = max(mCycle, end.second);
      }
    }

    rGraph.clear();
    rGraph.resize(n, vector<int>());
    for(int i = 0; i < n; i++){
      rGraph[bff[i]].push_back(i);
    }
    /// for all pair of vertices such that they are bffs
    int tot = 0;
//    cout << endl;
    for(int i = 0; i < n; i++){
      if(bff[bff[i]] == i){
        int mPath = 0;
        for(int nbh : rGraph[i]){
          if(nbh != bff[i]){
            mPath = max(mPath, maxPath(nbh));
          }
        }
//        cout << i << " " << mPath + 1 << endl;
        tot += mPath + 1;
      }
    }
    cout << max(mCycle, tot) << endl;
  }
}