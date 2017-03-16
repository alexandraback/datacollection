#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

const int NIL = -1;

int pairUp(const vector<vector<int>> &graph, const int x, vector<bool> &used, vector<int> &pairs) {
  if (used[x])
    return false;
  used[x] = true;
  for (const auto &y: graph[x]) {
    if (pairs[y] == NIL || pairUp(graph, pairs[y], used, pairs)) {
      pairs[x] = y;
      pairs[y] = x;
      return 1;
    }
  }
  return 0;
}

int getMaximumMatching(const int leftSize, const int rightSize, const vector<pair<int, int>> &edges) {
  auto graph = vector<vector<int>>(leftSize);
  for (int i = 0; i < int(edges.size()); ++i)
    graph[edges[i].first].push_back(edges[i].second);
  auto pairs = vector<int>(leftSize + rightSize, NIL);
  for (int change = 1; change > 0; ) {
    change = 0;
    auto used = vector<bool>(leftSize, false);
    for (int x = 0; x < leftSize; ++x)
      if (pairs[x] == NIL)
        change |= pairUp(graph, x, used, pairs);
  }
  int matchSize = 0;
  for (int x = 0; x < leftSize; ++x)
    if (pairs[x] != NIL)
      ++matchSize;
  return matchSize;
}

int getMinimumEdgeCover(const int leftSize, const int rightSize, const vector<pair<int, int>> &edges) {
  return leftSize + rightSize - getMaximumMatching(leftSize, rightSize, edges);
}

int main() {
  ifstream in("input.txt");
  ofstream out("output.txt");
  int testCount;
  in >> testCount;
  for (int test = 1; test <= testCount; ++test) {
    int n;
    in >> n;
    int left = 0, right = 0;
    vector<pair<int, int>> edges;
    map<string, int> leftIndex, rightIndex;
    for (int i = 0; i < n; ++i) {
      string first, second;
      in >> first >> second;
      if (leftIndex.find(first) == leftIndex.end())
        leftIndex[first] = left++;
      if (rightIndex.find(second) == rightIndex.end())
        rightIndex[second] = right++;
      edges.push_back(make_pair(leftIndex[first], rightIndex[second]));
    }
    for (int i = 0; i < int(edges.size()); ++i)
      edges[i].second += left;
    out << "Case #" << test << ": " << int(edges.size()) - getMinimumEdgeCover(left, right, edges) << "\n";
  }
  in.close();
  out.close();
  return 0;
}
