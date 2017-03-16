#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct p
{
  int sum;
  int set;
};

bool operator<(const p& x, const p& y)
{
  return x.sum < y.sum;
}

int main()
{
  int T;
  cin >> T;
  for (int cas = 1; cas <= T; cas++) {
    int N;
    vector<int> s;
    cin >> N;
    for (int i = 0; i < N; i++) {
      int si;
      cin >> si;
      s.push_back(si);
    }

    cout << "Case #" << cas << ":" << endl;

    vector<p> ps;
    for (int i = 0; i < (1 << N); i++) {
      int sum = 0;
      for (int j = 0; j < N; j++) {
        if (i & (1 << j)) {
          sum += s[j];
        }
      }
      p x = {sum, i};
      ps.push_back(x);
    }
    sort(ps.begin(), ps.end());

    for (size_t i = 0; i < ps.size(); i++) {
      for (size_t j = i + 1; j < ps.size(); j++) {
        if (ps[i].sum != ps[j].sum) break;
        if (ps[i].set & ps[j].set) continue;
        
        const char *sp = "";
        for (int k = 0; k < N; k++) {
          if (ps[i].set & (1 << k)) {
            cout << sp << s[k];
            sp = " ";
          }
        }
        cout << endl;
        sp = "";
        for (int k = 0; k < N; k++) {
          if (ps[j].set & (1 << k)) {
            cout << sp << s[k];
            sp = " ";
          }
        }
        cout << endl;
        goto found;
      }
    }
    cout << "Impossible" << endl;
  found:;
  }

  return 0;
}
