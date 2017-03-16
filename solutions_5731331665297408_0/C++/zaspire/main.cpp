#include <gmpxx.h>
//#include <gtk/gtk.h>
//#include <cairo.h>

#include <functional>
#include "shelly.hpp"

using namespace std;
using namespace shelly;

string TryCity(const vector<vector<bool>> &m, const vector<string> &cities, vector<bool> &visited, int n, const string &t, const vector<int> &path) {
  string r = t;
  if (r.size() == cities[0].size() * cities.size())
    return r;
  string rr;
  vector<int> tpath = path;
  for (int i = 0; i < cities.size(); i++) {
    if (visited[i])
      continue;
    if (!m[n][i])
      continue;
    visited[i] = true;
    tpath.push_back(n);
    string t = TryCity(m, cities, visited, i, r + cities[i], tpath);
    tpath.pop_back();
    if (t.size() == cities[0].size() * cities.size()) {
      if (rr.size() != cities[0].size() * cities.size() || rr > t)
        rr = t;
    }
    visited[i] = false;
  }
  if (path.size()) {
    tpath = path;
    tpath.pop_back();
    int i = path[path.size() - 1];

    string t = TryCity(m, cities, visited, i, r, tpath);
    tpath.pop_back();
    if (t.size() == cities[0].size() * cities.size()) {
      if (rr.size() != cities[0].size() * cities.size() || rr > t)
        rr = t;
    }
  }
  return rr;
}

int main(int argc, char **argv) {
  freopen("input.txt", "r", stdin);
//  gtk_init(&argc, &argv);

  int T;
  cin >> T;
  for (int TT = 1; TT <= T; TT++) {
    int N, M;
    cin >> N >> M;
    vector<string> cities;
    while (N--) {
      string s;
      cin >> s;
      cities.push_back(s);
    }
    vector<vector<bool>> m(cities.size(), vector<bool>(cities.size(), false));
    while (M--) {
      int x, y;
      cin >> x >> y;
      m[--x][--y] = true;
      m[y][x] = true;
    }
    string res;
    for (int i = 0; i < cities.size(); i++) {
      vector<bool> visited(cities.size(), false);
      visited[i] = true;
      string t = TryCity(m, cities, visited, i, cities[i], vector<int>());

      if (t.size() != cities[0].size() * cities.size())
        continue;
      if (t < res || res.size() != cities[0].size() * cities.size())
        res = t;
    }
    cout << Format("Case #%0: %1", TT, res) << endl;
  }
  return 0;
}
