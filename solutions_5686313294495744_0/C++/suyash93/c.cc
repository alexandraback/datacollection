#include <bits/stdc++.h>


const int maxn = 16;

int n = 0;
std::pair<std::string, std::string> topics[maxn];
std::map<std::string, std::set<int>> m1, m2;
std::pair<int, std::string> sizes1[maxn], sizes2[maxn];
std::set<std::string> done1, done2;

void init () {
  m1.clear();
  m2.clear();
  done1.clear();
  done2.clear();
}

void solution () {
  std::cin >> n;
  std::cin.ignore(10000, '\n');
  for (int i = 0 ; i < n ; i += 1) {
    std::string fw, sw;
    std::cin >> fw, sw;
    std::cin.ignore(10000, '\n');
    topics[i] = {fw, sw};
  }

  init();

  for (int i = 0 ; i < n ; i += 1) {
    m1[topics[i].first].insert(i);
    m2[topics[i].second].insert(i);
  }

  int i = 0;
  for (auto p: m1) {
    sizes1[i] = {p.second.size(), p.first};
    i += 1;
  }

  std::sort(sizes1, sizes1 + i);

  i = 0;
  for (auto p: m2) {
    sizes2[i] = {p.second.size(), p.first};
    i += 1;
  }

  std::sort(sizes2, sizes2 + i);

  int f = 1;
  int a = 0, b = 0;
  int originals = 0;
  while (!m1.empty()) {
    while (sizes1[a].first == f) {
      for (auto i: m1[sizes1[a].second]) {
        if (done1.count(topics[i].first) && done2.count(topics[i].second)) {
          continue;
        }
        done1.insert(topics[i].first);
        done2.insert(topics[i].second);
        originals += 1;
      }
      m1.erase(sizes1[a].second);
      a += 1;
    }

    while (sizes2[b].first == f) {
      for (auto i: m2[sizes2[b].second]) {
        if (done1.count(topics[i].first) && done2.count(topics[i].second)) {
          continue;
        }
        done1.insert(topics[i].first);
        done2.insert(topics[i].second);
        originals += 1;
      }
      m2.erase(sizes2[b].second);
      b += 1;
    }

    f += 1;
  }

  std::cout << (n - originals) << '\n';
}

int main () {
  // std::ios_base::sync_with_stdio(false);

  // std::freopen("x.in", "r", stdin);
  std::freopen("C-small-attempt0.in", "r", stdin);
  // std::freopen("C-large.in", "r", stdin);

  std::freopen("C.out", "w", stdout);

  int T = 0;
  std::cin >> T;
  std::cin.ignore(10000, '\n');
  for (int i = 1 ; i <= T ; i += 1) {
    std::cout << "Case #" << i << ": ";
    solution();
  }

  return 0;
}
