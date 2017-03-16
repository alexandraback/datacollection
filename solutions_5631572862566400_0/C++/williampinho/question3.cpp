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
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <climits>

using namespace std;

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define rep(i,n) for(auto i=0; i<(n); i++)
#define all(x) x.begin(),x.end()
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int num_max;
vector<int> bff;                                                        
vector<bool> visited;
vector<bool> cycle;
vector<int> num;
int depth;

int dfs(int j) {
  if(cycle[j]) return -1;
  visited[j] = true;
  num[j] = depth;
  depth++;
  if(visited[bff[j]]) return j;
  return dfs(bff[j]);
}

void mark_cycle(int u) {
  if(cycle[u]) return;
  cycle[u] = true;
  mark_cycle(bff[u]);
}

int main() {
  int T, N, f;                                                                    
  cin >> T;
  rep(i,T) {
    cin >> N;                                                                  
    bff.assign(N, 0);                                                        
    visited.assign(N,false);
    cycle.assign(N,false);
    num.assign(N,0);
    num_max = 0;
    rep(j,N) {
      cin >> bff[j];
      bff[j]--;
    }
    int bffs = 0;
    rep(j,N) {
      depth = 0;
      if(!visited[j]) {
	int u = dfs(j);
	if(u == -1) {
	  mark_cycle(j);
	}
	else { 
	  if(num[u] - num[bff[u]] > 1) {
	    num_max = max(num[u] - num[bff[u]]+1, num_max);
	    mark_cycle(u);
	  }
	  if(u == bff[bff[u]]) bffs+=depth-1;
	  else if(!cycle[bff[u]]) bffs += depth;
	}
	num.assign(N,0);
      }
    }
    cout << "Case #" << i+1 << ": " << max(num_max,bffs) << endl;
  }
  return 0;
}
