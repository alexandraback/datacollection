#include <bits/stdc++.h>

using namespace std;

int main()
{
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  cin.tie(0);
  int T;
  cin >> T;
  for(int cas=0;cas<T;++cas){
    cout << "Case #"<<cas+1<<": ";
    int N;
    cin >> N;
    vector<int> bf(N);
    vector<vector<int> > from(N);
    int a;
    for(int i=0;i<N;++i){
      cin >> a;
      --a;
      bf[i]=a;
      from[a].emplace_back(i);
    }
    vector<char> done(N, false);
    int maxcycle=0;
    for(int i=0;i<N;++i){
      if(done[i])continue;
      vector<int> depth(N, 0);
      depth[i]=1;
      for(int j=i;;j=bf[j]){
          done[j]=true;
        if(depth[bf[j]]!=0){
            //cerr << "cycle at: " << i << ": " << (depth[j] - depth[bf[j]]+1) << "\n";
          maxcycle = max(maxcycle, depth[j] - depth[bf[j]]+1);
          break;
        }
        depth[bf[j]] = depth[j]+1;
      }
    }
    vector<int> stable;//length-2-cycles
    for(int i=0;i<N;++i){
      if(bf[bf[i]] == i) stable.emplace_back(i);
    }
    int lines = 0;
    for(auto &e:stable){
        //cerr << "line at: " << e;
      int maxDepth=1;
      stack<pair<int, int> > dfs;
      for(auto &f:from[e]){
        if(f!=bf[e])dfs.emplace(f, 2);
      }
      int a, dist;
      while(!dfs.empty()){
        tie(a, dist) = dfs.top();
        dfs.pop();
        maxDepth = max(maxDepth, dist);
        for(auto &f:from[a]){
          dfs.emplace(f, dist+1);
        }
      }
    //cerr << "-> " << maxDepth << "\n";
      lines+=maxDepth;
    }
    cout << max(maxcycle, lines) << "\n";
    //cerr << "\n";
  }

  return 0;
}
