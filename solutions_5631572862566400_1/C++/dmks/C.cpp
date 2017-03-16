#include <vector>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <set>

using namespace std;

int N;

vector<int> bff;
vector<vector<int> > rbff;
vector<int> visited;
int color;

int best;

int find_longest_path(int k, int loop_one) {
  int level = 1;
  vector<int> nodes;
  int color = visited[k];
  nodes.push_back(k);
  vector<int> next;
  while (true) {
    for (int i = 0; i < nodes.size(); i++) {
      int cur = nodes[i];
      for (int j = 0; j < rbff[cur].size(); j++) {
        int r = rbff[cur][j];
        if (r == loop_one) continue;
        visited[r] = color;
        next.push_back(r);
      }
    }
    if (next.size() > 0) {
      level++;
      nodes = next;
      next.clear();
    } else {
      break;
    }
  }
  return level;
}

void solve() {
  cin >> N;
  bff.clear();
  rbff = vector<vector<int> >(N, vector<int>());

  for (int i = 0; i < N; i++) {
    int k;
    cin >> k;
    bff.push_back(k-1);
    rbff[k-1].push_back(i);
  }
  best = 0;
  visited = vector<int>(N, 0);
  color = 0;

  vector<int> good_loops;
  for (int i = 0; i < N; i++) if (!visited[i]) {
    color++;
    visited[i] = color;

    vector<int> path;
    path.push_back(i);
    while (true) {
      int next = bff[path.back()];
      int loop_start = -1;
      for (int j = 0; j < path.size(); j++) if (path[j] == next) {
        loop_start = j;
        break;
      }
      if (loop_start != -1) {
        //cerr << "loop_start=" << loop_start << endl;
        if (loop_start == path.size() - 2) {
          // Good loop
          int len = find_longest_path(path[loop_start], path.back()) +
            find_longest_path(path.back(), path[loop_start]);
          good_loops.push_back(len);
        } else {
          int cur_best = path.size()  - loop_start;
          if (cur_best > best) best = cur_best;
          for (int j = loop_start; j < path.size(); j++) {
            int k = j - 1;
            if (k < loop_start) k = path.size() - 1;
            find_longest_path(path[j], path[k]);
          }
        }
        break;
      }

      if (visited[next]) {
        cerr << "Error: " << path.back() << ' ' << next << endl;
        exit(1);
      }
      visited[next] = color;
      path.push_back(next);
    }
  } // end for
  int sum = 0;
  for (int i = 0; i < good_loops.size(); i++) {
    sum += good_loops[i];
  }
  if (sum > best) {
    best = sum;
  }
  cout << best;
}

int main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; i++) {
    cout << "Case #" << (i+1) << ": ";
    solve();
    cout << endl;
  }
  return 0;
}
