#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <bitset>

using namespace std;

#define debug(x) // cout << #x << ": " << x << endl;

template <typename A, typename B>
ostream& operator<<(ostream& ost, const pair<A,B> &m) {
  ost << "[";
  cout << m.first << "," << m.second;
  ost << "]";
  return ost;
};

template <typename T>
ostream& operator<<(ostream& ost, const vector<T> &vec) {
  ost << "[";
  for (auto&& a : vec) cout << a << ", ";
  ost << "]";
  return ost;
};

template <typename K, typename V>
ostream& operator<<(ostream& ost, const map<K,V> &m) {
  ost << "{";
  for (auto&& a : m) cout << a.first << " => " << a.second << ", ";
  ost << "}";
  return ost;
};

vector<vector<int>> paths;

unsigned long long count(int start, int end, vector<int> path) {

  if (start >= end)
  {
    paths.push_back(path);
    return 1;
  }

  unsigned long long result = 0;
  for (int i = start+1; i <= end; i++) {
    auto t = path;
    t.push_back(i);
    result += count(i, end, t);
  }
  return result;
}

unsigned long long countPaths(vector<vector<bool>> &graph, int cur = 0) {
  if (cur == graph.size()-1) return 1;
  int result = 0;
  for (int i = 0; i < graph.size(); ++i) {
    if (graph.at(cur).at(i) == true) {
      result += countPaths(graph, i);
    }
  }
  return result;
}

void solve2() {
}

void solve() {
  paths.clear();
  int b,m;
  cin >> b >> m;
  unsigned long long max = count(1,b, {1});
  debug(max);
  debug(m);
  if (max < m) cout << "IMPOSSIBLE"<<endl;
  else {
    cout << "POSSIBLE" << endl;
    vector<vector<bool>> res(b, vector<bool>(b,0));

    for (int i = 0; i < max; ++i) {
      const auto& p = paths.at(i);
      auto copy = res;
      for (int j = 0; j < p.size() - 1; ++j) {
        copy[p.at(j)-1][p.at(j+1)-1] = 1;
      }

      const int cnt = countPaths(copy);
      if (countPaths(copy) < m) {
        res = copy;
      } else if (cnt == m) {
        for (int y = 0; y < b; ++y) {
          for (int x = 0; x < b; ++x) {
            cout << copy[y][x] ;
          }
          cout << endl;
        }
          debug(cnt);
        break;
      }
    }
  }
}

int main()
{
  int t;
  cin >> t;
  for (int i = 1; i <= t; ++i)
  {
    cout << "Case #"<<i<<": ";solve();
  }
}
