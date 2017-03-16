
#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <map>
#include <cstring>

using namespace std;


int N, M;

std::string zips[100];
int flights[100][100];

std::string composed(const int v[], int n) {
  std::string c;
  for (int i = 0; i < n; ++i)
    c += zips[v[i]];

  return c;
}

struct state {
  int visited[100];
  int valid[100];
  int depth;

  bool operator<(const state& o) const {
    std::string s1 = composed(visited, depth);
    std::string s2 = composed(o.visited, o.depth);

    if (s1 == s2) return false;
    else return s1 > s2;
  }

  bool seen(int s) const {
    for (int i = 0; i < depth; ++i) if (visited[i] == s) return true;
    return false;
  }
};


int solve(int CASE) {
  memset(flights, 0, sizeof(flights));

  cin >> N >> M;

  for (int i = 0; i < N; ++i) { cin >> zips[i]; }
  for (int i = 0; i < M; ++i){
    int a, b;
    cin >> a >> b;
    flights[a-1][b-1] = 1;
    flights[b-1][a-1] = 1;
  }

  int smallest = 0;
  for (int i = 1; i < N; ++i) {
    if (zips[i] < zips[smallest]) smallest = i;
  }

  priority_queue<state> q;

  state s;
  s.visited[0] = smallest;
  s.valid[0] = true;
  s.depth = 1;

  q.push(s);

  while (!q.empty()) {
    state s = q.top(); q.pop();

    //printf("currently at: %s\n", composed(s.visited, s.depth).c_str());

    if (s.depth == N) {
  printf("Case #%d: %s\n", CASE, composed(s.visited, s.depth).c_str());
      //printf("WINNER\n");
      return 0;
    }

    for (int i = 0; i < s.depth; ++i) {
      if (s.valid[i]) {
        int f = s.visited[i];
        for (int j = 0; j < N; ++j) {
          if (flights[f][j] && !s.seen(j)) {
            state w = s;
            w.depth = s.depth + 1;

            w.visited[s.depth] = j;
            if (i < s.depth-1)
            for (int k = i+1; k < s.depth; ++k) w.valid[k] = false;

            w.valid[s.depth] = true;

            q.push(w);
          }
        }
      }
    }

  }


  //printf("Case #%d: %s\n", CASE, composed(s.visited, s.depth).c_str());
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i)
    solve(i+1);

  return 0;
}

