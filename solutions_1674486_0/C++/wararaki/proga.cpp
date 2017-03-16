#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n;
bool a[1001][1001], vis[1001];

bool bfs(int p)
{
  int t;
  queue<int> que;
  fill(vis, vis+1001, true);
  que.push(p);

  while(!que.empty()){
    t = que.front();
    que.pop();

    if(!vis[t]) return true;
    vis[t] = false;

    for(int i = 1; i <= n; ++i)
      if(a[t][i]) que.push(i);
  }

  return false;
}

bool solve()
{
  for(int i = 1; i <= n; ++i)
    if(bfs(i)) return true;

  return false;
}

int main()
{
  int cs, m, t;

  while(cin>>cs && cs)
    for(int csi = 1; csi <= cs; ++csi){
      cin >> n;
      fill(&a[0][0], &a[n+1][0], false);
      for(int i = 1; i <= n; ++i){
	cin >> m;
	while(m--){
	  cin >> t;
	  a[i][t] = true;
	}
      }

      cout << "Case #" << csi << ": " << (solve()? "Yes": "No") << endl;
    }

  return 0;
}
