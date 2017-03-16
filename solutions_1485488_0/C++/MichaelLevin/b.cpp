#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <limits>
#include <numeric>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define MP make_pair
#define all(v) (v).begin(), (v).end()
#define PROBLEM_ID "B"

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<bool> vb;
typedef long long ll;
typedef pair<int, int> pii;

bool CanGo(int W, int f_from, int c_from, int f_to, int c_to) {
  return W <= c_to - 50 && f_from <= c_to - 50 && f_to <= c_to - 50 && f_to <= c_from - 50;
}

/*void BuildGraph(int H, const vvi& c, const vvi& f, vector< pair<pii, int> >& vertices, vector< vector<pii> >& G) {
  vertices.clear();
  map<pair<pii, int>, int > vertex_to_index;
  int rows = c.size();
  int cols = c[0].size();
  for (int row = 0; row < rows; ++row) {
    for (int col = 0; col < cols; ++col) {
      if (f[row][col] <= c[row][col] - 50) {
        pair<pii, int> vertex = MP(MP(row, col), 0);
        vertex_to_index[vertex] = vertices.size();
        vertices.push_back(vertex);
      }
    }
  }
  vector< vector< set<int> > > times(rows, vector< set<int> >(cols));
  for (int row = 0; row < rows; ++row) {
    for (int col = 0; col < cols; ++col) {
      if (f[row][col] <= c[row][col] - 50) {
        pair<pii, int> vertex = MP(MP(row, col), H);
        if (!vertex_to_index.count(vertex)) {
          vertex_to_index[vertex] = vertices.size();
          vertices.push_back(vertex);
        }
        times[row][col].insert(H);
      }
      if (vertex_to_index.count(MP(MP(row, col), 0))) {
        times[row][col].insert(0);
      }
    }
  }
  for (int row = 0; row < rows; ++row) {
    for (int col = 0; col < cols; ++col) {
      pair<pii, int> vertex = MP(MP(row, col), 0);
      if (f[row][col] > c[row][col] - 50) {
        continue;
      }
      for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
          if (abs(dx) + abs(dy) == 1) {
            int nrow = row + dx;
            int ncol = col + dy;
            if (nrow < 0 || nrow >= rows || ncol < 0 || ncol >= cols) {
              continue;
            }
            pair<pii, int> other_vertex = MP(MP(nrow, ncol), 0);
            if (CanGo(H, f[row][col], c[row][col], f[nrow][ncol], c[nrow][ncol])) {
              if (!vertex_to_index.count(vertex)) {
                cerr << "no vertex, but must be!" << endl;
                exit(1);
              }
              int from_index = vertex_to_index[vertex];
              if (!vertex_to_index.count(other_vertex)) {
                cerr << "no other_vertex, but must be!" << endl;
                exit(1);
              }
              int to_index = vertex_to_index[other_vertex];
              if (from_index >= G.size()) {
                G.resize(from_index + 1);
              }
              G[from_index].push_back(MP(to_index, 0));
            } else if (CanGo(0, f[row][col], c[row][col], f[nrow][ncol], c[nrow][ncol])) {
              int time_to_go = H - (c[nrow][ncol] - 50);
              pair<pii, int> new_from = MP(MP(row, col), time_to_go);
              if (!vertex_to_index.count(new_from)) {
                vertex_to_index[new_from] = vertices.size();
                vertices.push_back(new_from);
                times[row][col].insert(time_to_go);
              }
              int water_height_to_go = c[nrow][ncol] - 50;
              int time_delta;
              if (water_height_to_go >= f[row][col] + 20) {
                time_delta = 10;
              } else {
                time_delta = 100;
              }
              int time_in_destination = time_to_go + time_delta;
              pair<pii, int> new_to = MP(MP(nrow, ncol), time_in_destination);
              if (!vertex_to_index.count(new_to)) {
                vertex_to_index[new_to] = vertices.size();
                vertices.push_back(new_to);
                times[nrow][ncol].insert(time_in_destination);
              }
              int index_from = vertex_to_index[new_from];
              int index_to = vertex_to_index[new_to];
              if (index_from >= G.size()) {
                G.resize(index_from + 1);
              }
              G[index_from].push_back(MP(index_to, time_delta));
            }
          }
        }
      }
    }
  }
  for (int row = 0; row < rows; ++row) {
    for (int col = 0; col < cols; ++col) {
      vector<int> all_times(times[row][col].begin(), times[row][col].end());
      if (all_times.size() > 10) {
        cerr << "times vector of size " << all_times.size() << " at " << row << " , " << col << "!" << endl;
        exit(1);
      }
      for (int i = 0; i + 1 < all_times.size(); ++i) {
        pair<pii, int> from = MP(MP(row, col), all_times[i]);
        if (!vertex_to_index.count(from)) {
          cerr << "there is no vertex for time " << all_times[i] << " at " << row << ", " << col << "!" << endl;
          exit(1);
        }
        int index_from = vertex_to_index[from];
        pair<pii, int> to = MP(MP(row, col), all_times[i + 1]);
        if (!vertex_to_index.count(to)) {
          cerr << "there is no vertex for time " << all_times[i + 1] << " at " << row << ", " << col << "!" << endl;
          exit(1);
        }
        int index_to = vertex_to_index[to];
        if (index_from >= G.size()) {
          G.resize(index_from + 1);
        }
        G[index_from].push_back(MP(index_to, all_times[i + 1] - all_times[i]));
      }
    }
  }
  for (int row = 0; row < rows; ++row) {
    for (int col = 0; col < cols; ++col) {
      for (int time_index = 0; time_index < times[row][col].size(); ++time_index) {
        int time = times[row][col][time_index];
        if (!vertex_to_index.count(MP(MP(row, col), time))) {
          cerr << "vertex disappeared!" << endl;
          exit(1);
        }
        int vertex_index = vertex_to_index[MP(MP(row, col), time)];
        for (int other_index = 0; other_index < G[vertex_index].size(); ++other_index) {
          int other_vertex_index = G[vertex_index][other_index].first;

        }
      }
    }
  }
}*/

int main() {
  freopen(PROBLEM_ID".in", "r", stdin);
  freopen(PROBLEM_ID".out", "w", stdout);
  int test_count;
  cin >> test_count;
  for (int test_index = 0; test_index < test_count; ++test_index) {
    cout << "Case #" << test_index + 1 << ": ";
    cerr << "Case #" << test_index + 1 << ": ";
    int H, rows, cols;
    cin >> H >> rows >> cols;
    vector< vector<int> > c(rows, vi(cols)), f(rows, vi(cols));
    for (int row = 0; row < rows; ++row) {
      for (int col = 0; col < cols; ++col) {
        scanf("%d", &c[row][col]);
      }
    }
    for (int row = 0; row < rows; ++row) {
      for (int col = 0; col < cols; ++col) {
        scanf("%d", &f[row][col]);
      }
    }
    //vector< vector<pii> > G;
    //vector< pair<pii, int> > vertices;
    //BuildGraph(H, c, f, vertices, G);
    //vector<int> distances(vertices.size(), numeric_limits<int>::max());
    typedef pair<int, pii> Vertex;
    map<pii, int> distance;
    set<Vertex> q;
    Vertex start = MP(0, MP(0, 0));
    q.insert(start);
    distance[MP(0, 0)] = 0;
    int result = -1;
    while (!q.empty()) {
      Vertex cur = *q.begin();
      q.erase(cur);
      int dist = cur.first;
      pii pos = cur.second;
      if (pos.first == rows - 1 && pos.second == cols - 1) {
        result = dist;
        break;
      }
      int row = pos.first;
      int col = pos.second;
      for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
          if (abs(dx) + abs(dy) == 1) {
            int nrow = row + dx;
            int ncol = col + dy;
            if (nrow < 0 || nrow >= rows || ncol < 0 || ncol >= cols) {
              continue;
            }
            if (dist == 0 && CanGo(H, f[row][col], c[row][col], f[nrow][ncol], c[nrow][ncol])) {
              Vertex other = MP(0, MP(nrow, ncol));
              if (!distance.count(MP(nrow, ncol))) {
                distance[MP(nrow, ncol)] = 0;
                q.insert(other);
              }
            } else {
              if (CanGo(0, f[row][col], c[row][col], f[nrow][ncol], c[nrow][ncol])) {
                int time_to_go = max(H - (c[nrow][ncol] - 50), dist);
                if (time_to_go < 0) {
                  time_to_go = 0;
                }
                int time_delta;
                if (H - time_to_go >= f[row][col] + 20) {
                  time_delta = 10;
                } else {
                  time_delta = 100;
                }
                int time_in_destination = time_to_go + time_delta;
                if (!distance.count(MP(nrow, ncol))) {
                  distance[MP(nrow, ncol)] = time_in_destination;
                  q.insert(MP(distance[MP(nrow, ncol)], MP(nrow, ncol)));
                } else if (distance[MP(nrow, ncol)] > time_in_destination) {
                  q.erase(MP(distance[MP(nrow, ncol)], MP(nrow, ncol)));
                  distance[MP(nrow, ncol)] = time_in_destination;
                  q.insert(MP(distance[MP(nrow, ncol)], MP(nrow, ncol)));
                }
              }
            }
          }
        }
      }
    }
    if (result == -1) {
      cerr << "result = -1!" << endl;
      exit(1);
    }
    printf("%.1lf\n", static_cast<double>(result) / 10.0);
    //fprintf(stderr, "%.1lf\n", static_cast<double>(result) / 10.0);
  }
  return 0;
}
