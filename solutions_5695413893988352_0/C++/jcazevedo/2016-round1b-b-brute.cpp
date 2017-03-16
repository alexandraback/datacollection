#include <cstdio>
#include <string>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int T;
string sc, sj;

vector<string> gen(int L) {
  if (L == 0) {
    string r = "";
    vector<string> res;
    res.push_back(r);
    return res;
  }
  vector<string> res;
  for (char a = '0'; a <= '9'; a++) {
    vector<string> next = gen(L - 1);
    for (auto i = 0; i < next.size(); i++) {
      res.push_back(a + next[i]);
    }
  }
  return res;
}

bool valid(string gen, string r) {
  int N = gen.size();
  for (int i = 0; i < N; i++) {
    if (r[i] != '?' && gen[i] != r[i])
      return false;
  }
  return true;
}

int main() {
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    cin >> sc >> sj;
    int N = sc.size();
    vector<string> g = gen(N);
    int G = g.size();
    int minDiff = 1000;
    string b1 = "", b2 = "";
    for (int i = 0; i < G; i++) {
      if (!valid(g[i], sc))
        continue;
      for (int j = 0; j < G; j++) {
        if (!valid(g[j], sj))
          continue;
        int d = abs(atoi(g[i].c_str()) - atoi(g[j].c_str()));
        if (d < minDiff) {
          minDiff = d;
          b1 = g[i];
          b2 = g[j];
        } else if (d == minDiff && atoi(g[i].c_str()) < atoi(b1.c_str())) {
          b1 = g[i];
          b2 = g[j];
        } else if (d == minDiff && atoi(g[i].c_str()) == atoi(b1.c_str()) && atoi(g[j].c_str()) < atoi(b2.c_str())) {
          b1 = g[i];
          b2 = g[j];
        }
      }
    }
    cout << "Case #" << t << ": " << b1 << " " << b2 << endl;
  }
  return 0;
}
