#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;

int N, M;
map<string, int> m;
vector<int> v;
map<int, int> s;
vector<pair<int, int> > p;

void input() {
  cin >> N;
  m.clear();
  p.clear();
  int id = 0;
  for (int i = 0; i < N; ++i) {
    string r, q;
    cin >> r >> q;
    if (m.find(r) == m.end()) {
      m[r] = id;
      ++id;
    }
    if (m.find(q) == m.end()) {
      m[q] = id;
      ++id;
    }
    p.push_back(pair<int, int>(m[r], m[q]));
  }
  M = id;
}

void prepare() {
  v.clear();
  s.clear();
  v.resize(M);
  for (int i = 0; i < M; ++i) {
    v[i] = 0;
  }
  for (int i = 0; i < N; ++i) {
    pair<int, int> pp = p[i];
    ++v[pp.first];
    ++v[pp.second];
    s[pp.first * M + pp.second]++;
  }
}

int solve() {
  int ans = 0;
  for (int i = 0; i < N; ++i) {
    pair<int, int> pp = p[i];
    if (v[pp.first] == 1 || v[pp.second] == 1) {
      continue;
    }
    if (v[pp.first] == 2 && v[pp.second] == 2 && s[pp.first * M + pp.second] + s[pp.first + pp.second * M] == 2) {
      continue;
    }
    ++ans;
  }
  return ans;
}

int main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; ++i) {
    cout << "Case #" << i + 1 << ": ";
    input();
    prepare();
    cout << solve() << endl;
  }
  return 0;
}
