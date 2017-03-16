#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <list>
#include <set>
#include <algorithm>
#include <climits>
#include <cmath>
#include <string>
#include <stack>
using namespace std;

int n, m;
int used[51];
int ord[51];
stack<int> visit;

void rec(int curr, int pos, vector<set<int> >& graph, vector<int>& labels, vector<int>& best) {
  int i;
  
  ord[pos] = curr;
  used[curr] = 1;
  
  if(pos == n-1) {
    // check previsit
    int ok = 1;
    while(!visit.empty()) visit.pop();
    visit.push(ord[0]);
    for(i=1; i<n; i++) {
      while(!visit.empty() && graph[ord[i]].find(visit.top()) == graph[ord[i]].end())
        visit.pop();
        
      if(visit.empty()) {
        ok = 0;
        break;
      }
      
      visit.push(ord[i]);
    }
    
    if(ok) {
      /*
      for(i=0; i<n; i++) cout << ord[i] << " ";
      cout << endl;
      */
      int better = 0;
      for(i=0; i<n; i++) {
        if(labels[ord[i]] < best[i]) {
          better = 1;
          break;
        }
        if(labels[ord[i]] > best[i]) {
          break;
        }
      }
      
      if(better) {
        for(i=0; i<n; i++) {
          best[i] = labels[ord[i]];
        }
      }
    }
  
  }
  else {
    for(i=0; i<n; i++)
      if(!used[i]) {
        rec(i, pos+1, graph, labels, best);
      }
  }
  
  used[curr] = 0;
}

void solve(int test) {
  int i, j;
  int x, y;
  
  cin >> n >> m;
  
  vector<int> labels(n);
  vector<int> best(n);
  vector<set<int> > graph(n);
  
  for(i=0; i<n; i++) {
    cin >> labels[i];
  }
  
  for(i=0; i<m; i++) {
    cin >> x >> y;
    x--; y--;
    graph[x].insert(y);
    graph[y].insert(x);
  }
  
  for(i=0; i<n; i++) best[i] = labels[i];
  sort(best.begin(), best.end());
  reverse(best.begin(), best.end());
  
  for(i=0; i<n; i++) used[i] = 0;
  for(i=0; i<n; i++) {
    rec(i, 0, graph, labels, best);
  }

  cout << "Case #" << (test+1) << ": ";
  for(i=0; i<n; i++) cout << best[i];
  cout << endl;
}


int main() {
  int t, T;
  cin >> T;
  for(t=0; t<T; t++) solve(t);
  return 0;
}

