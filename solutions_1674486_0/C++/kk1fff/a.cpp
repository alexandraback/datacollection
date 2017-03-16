#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int PATH[1001][1001];
int ROOT[1001];
int VISITED[1001];
int N;

bool DFS(int from) { // true if cycled
  VISITED[from] = 1;
  for (int i = 1; i <= N; i++) {
    if (PATH[from][i] != 0) {
      if (VISITED[i] == 1) {
        // cout << "Visited: " << i << endl;
        return true;
      } else if (DFS(i)) {
        return true;
      }
    }
  }
}

void cleanVisited() {
  memset(VISITED, 0, sizeof(VISITED));
}

bool testRoot() {
  for (int i = 1; i <= N; i++) {
    if (ROOT[i] != 0) {
      cleanVisited();
      //     cout << "Root: " << i;
      if (DFS(i)) {
        return true;
      }
    }
  }
  return false;
}

void run(istream& in, ostream& ou, int c) {
  for (int i = 0; i <= 1000; i++) {
    ROOT[i] = 0;
    for (int j = 0; j < 1001; j++) {
      PATH[i][j] = 0;
    }
  }
  in >> N;
  for (int i = 1; i <= N; i++) {
    int M;
    in >> M;
    for (int j = 0; j < M; j++) {
      int p;
      in >> p;
      PATH[p][i] = 1;
    }
    if (M == 0) {
      ROOT[i] = 1;
    }
  }
  ou << "Case #"<<c<<": ";
  if (testRoot()) {
    ou << "Yes";
  } else {
    ou << "No";
  }
  ou<<endl;
}

int main(int c, char** v) {
  ifstream in(v[1]);
  int T;
  in >> T;
  for (int i = 0; i < T; i++) {
    run(in, cout, i+1);
  }
}
