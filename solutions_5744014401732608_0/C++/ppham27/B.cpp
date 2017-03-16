#include <algorithm>
#include <exception>
#include <iostream>
#include <iterator>
#include <utility>
#include <vector>

using namespace std;

int countPaths(int from, int to, 
               const vector<vector<int>> &edgeMatrix) {
  if (from == to) return 1;
  int paths = 0;
  for (int j = 0; j < edgeMatrix.size(); ++j) {
    if (edgeMatrix[from][j] == 1) {
      paths += countPaths(j, to, edgeMatrix);
    }
  }
  return paths;
}

vector<vector<int>> buildSlides(int B, long long M) {
  /* make directed acyclic graph from 0 to B - 1
   * with M such paths
   */   
  vector<pair<int, int>> idxToEdge;
  for (int i = 0; i < B - 1; ++i) {
    for (int j = i + 1; j < B; ++j) idxToEdge.emplace_back(i, j);
  }
  int N = idxToEdge.size();
  vector<vector<int>> edgeMatrix(B, vector<int>(B));
  for (int bitmask = 0; bitmask < (1 << N); ++bitmask) {
    for (int i = 0; i < B; ++i) fill(edgeMatrix[i].begin(), edgeMatrix[i].end(), 0);
    for (int i = 0, b = bitmask; b > 0; ++i, b >>= 1) {
      if ((b & 1) == 1) edgeMatrix[idxToEdge[i].first][idxToEdge[i].second] = 1;
    }
    int paths = countPaths(0, B - 1, edgeMatrix);
    if (paths == M) return edgeMatrix;
  }
  throw logic_error("there does not exist such a set of edges");
  return edgeMatrix;
}

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false); cin.tie(NULL);
  int T; cin >> T;
  for (int t = 1; t <= T; ++t) {
    int B;
    long long M; 
    cin >> B >> M; // number of buildings and slides    
    cout << "Case #" << t << ": ";
    try {
      vector<vector<int>> edgeMatrix = buildSlides(B, M);
      cout << "POSSIBLE" << '\n';
      for (int i = 0; i < B; ++i) {
        copy(edgeMatrix[i].begin(), edgeMatrix[i].end() - 1, ostream_iterator<int>(cout, ""));
        cout << edgeMatrix[i].back() << '\n';
      }      
    } catch (const logic_error &e) {
      cout << "IMPOSSIBLE" << '\n';
    }
  }
  cout << flush;
  return 0;
}
