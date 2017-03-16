#include <cstring>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <queue>
#define MAX 1001

using namespace std;

vector<unsigned int> edges[MAX];
char visited[MAX];
queue<unsigned int> Q;

bool solve(unsigned int N) {
  for (unsigned int x=0; x<N; ++x) {
    memset(visited, 0, sizeof(char)*MAX);
    while(!Q.empty()) Q.pop();
    Q.push(x);
    visited[x] = -1;
    while(!Q.empty()) {
      unsigned int u = Q.front();
      Q.pop();
      for (unsigned int i=0; i<edges[u].size(); ++i) {
	unsigned int v = edges[u][i];
	//cout << u << " " << v << " " << static_cast<int>(visited[v]) << endl;
	if (visited[v] > 0) return true;
	Q.push(v);
	if (visited[v] != -1) visited[v]++;
      }
    }
  }
  return false;
}

int main() {
  unsigned int T;
  unsigned int N=0;
  cin >> T;
  for (unsigned int i=0; i<T; ++i) {
    for (unsigned int j=0; j<N; ++j) edges[j].clear();
    cin >> N;
    for (unsigned int u=0; u<N; ++u) {
      unsigned int M;
      cin >> M;
      for (unsigned int k=0; k<M; ++k) {
	unsigned int v;
	cin >> v;
	edges[u].push_back(v-1);
      }
    }
    if (solve(N)) cout << "Case #" << (i+1) << ": Yes" << endl;
    else cout << "Case #" << (i+1) << ": No" << endl;
  }
}
