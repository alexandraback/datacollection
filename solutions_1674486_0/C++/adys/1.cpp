#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <iomanip>
using namespace std;
typedef unsigned long ulong;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
typedef long long ll;

vector < vector <int> > E;

bool search(int v,int N){
  queue<int> q;
  q.push(v);
  vector<byte> vis(N+1);
  vis[v] = 1;
  while (!q.empty()){
    int cur = q.front();q.pop();
    for (int i = 0; i < E[cur].size(); ++i){
      if(vis[E[cur][i]] && E[cur][i] != v) return true;
      if (!vis[E[cur][i]]){
        q.push(E[cur][i]);
        vis[E[cur][i]] = 1;
      }
    }
  }
  return false;
}

int main()
{
  int T,N,M,e;
  cin >> T;
  for (int t = 1; t <= T; ++t){
    cin >> N;
    E.clear();
    E.resize(N+1);
    for (int i = 1 ; i <= N; ++i){
      cin >> M;
      for (int j = 0; j < M; ++j){
        cin >> e;
        E[i].push_back(e);
      }
    }
    bool cycle = false;
    for (int i = 1; i <= N; ++i){
      cycle = search (i,N);
      if (cycle){
        cout << "Case #" << t << ": Yes" << endl;
        break;
      }  
    }
    if (!cycle){
        cout << "Case #" << t << ": No" << endl;
    }
  }
  return 0;
}
