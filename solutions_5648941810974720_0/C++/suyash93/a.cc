#include <bits/stdc++.h>


const int maxn = 100;

std::string s;

std::string strings[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

std::map<char, int> stringsmaps[10];
// std::vector<std::pair<int, char>> freqs(15);
std::map<char, int> mp;
std::set<std::pair<int, int>> ans;

void ginit () {
  for (int i = 0 ; i < 10 ; i += 1) {
    for (char c: strings[i]) {
      stringsmaps[i][c] += 1;
    }
  }

  // std::map<char, int> mp2;
  // for (int i = 0 ; i < 10 ; i += 1) {
  //   for (auto p: stringsmaps[i]) {
  //     mp2[p.first] += p.second;
  //   }
  // }
  //
  // int i = 0;
  // for (auto p: mp2) {
  //   // std::cout << p.first << " " << p.second << '\n';
  //   freqs[i] = {p.second, p.first};
  //   i += 1;
  // }
  //
  // std::sort(freqs.begin(), freqs.end());
  //
  // for (auto x: freqs) {
  //   std::cout << x.first << " " << x.second << '\n';
  // }
}

void init () {
  mp.clear();
  ans.clear();
}

void solution () {
  std::getline(std::cin, s);

  init();

  for (char c: s) {
    mp[c] += 1;
  }

  std::pair<char, int> uniq[] = {
    {'G', 8},
    {'U', 4},
    {'W', 2},
    {'X', 6},
    {'Z', 0},
    {'F', 5},
    {'H', 3},
    {'S', 7},
    {'I', 9},
    {'N', 1}
  };

  for (auto c: uniq) {
    if (mp.count(c.first)) {
      int f = mp[c.first];
      ans.insert({c.second, f});
      for (auto p: stringsmaps[c.second]) {
        mp[p.first] -= f * p.second;
        if (mp[p.first] == 0) mp.erase(p.first);
      }
    }
  }

  for (auto p: ans) {
    int v = p.first;
    int f = p.second;
    for (int j = 0 ; j < f ; j += 1) {
      std::cout << v;
    }
  }
  std::cout << '\n';
}

int main () {
  // std::ios_base::sync_with_stdio(false);

  // std::freopen("x.in", "r", stdin);
  std::freopen("A-small-attempt0.in", "r", stdin);
  // std::freopen("A-large.in", "r", stdin);

  std::freopen("A.out", "w", stdout);

  ginit();

  int T = 0;
  std::cin >> T;
  std::cin.ignore(10000, '\n');
  for (int i = 1 ; i <= T ; i += 1) {
    std::cout << "Case #" << i << ": ";
    solution();
  }

  return 0;
}
