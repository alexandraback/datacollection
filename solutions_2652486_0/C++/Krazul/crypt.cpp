#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct s {
  vector<int> contents;
  map<int, double> freq;
  double weight;
  double likelihood;
};

int main() {
  int t; cin >> t; // t = 1
  for (int test = 1; test <= t; ++test) {
    cout << "Case #" << test << ":" << endl;
    // r = 100, n = 3, m = 5, k = 7
    int r, n, m, k; cin >> r >> n >> m >> k;

    vector<s> possibilities;
    for (int i = 2; i <= m; ++i) {
      for (int j = 2; j <= m; ++j) {
        for (int k = 2; k <= m; ++k) {
          vector<int> tmp;
          tmp.push_back(i);
          tmp.push_back(j);
          tmp.push_back(k);
          sort(tmp.begin(), tmp.end());
          bool found = false;
          for (int ii = 0; ii < possibilities.size(); ++ii) {
            if (possibilities[ii].contents == tmp) {
              possibilities[ii].weight += double(1)/(m-1)/(m-1)/(m-1);
              found = true;
            }
          }
          if (!found) {
            s ss;
            ss.contents = tmp;
            ss.freq[1] += 0.125;
            ss.freq[tmp[0]] += 0.125;
            ss.freq[tmp[1]] += 0.125;
            ss.freq[tmp[2]] += 0.125;
            ss.freq[tmp[0] * tmp[1]] += 0.125;
            ss.freq[tmp[0] * tmp[2]] += 0.125;
            ss.freq[tmp[1] * tmp[2]] += 0.125;
            ss.freq[tmp[0] * tmp[1] * tmp[2]] += 0.125;
            ss.weight = double(1)/(m-1)/(m-1)/(m-1);
            possibilities.push_back(ss);
          }
        }
      }
    }
    for (int ii = 0; ii < r; ++ii) {
      for (int i = 0; i < possibilities.size(); ++i)
        possibilities[i].likelihood = 1;
      for (int i = 0; i < k; ++i) {
        int next; cin >> next;
        for (int j = 0; j < possibilities.size(); ++j) {
          if (possibilities[j].freq.count(next)) {
            possibilities[j].likelihood *= possibilities[j].freq[next];
          } else {
            possibilities[j].likelihood = 0;
          }
        }
      }
      double best = -1;
      int idx = -1;
      for (int i = 0; i < possibilities.size(); ++i) {
        if (possibilities[i].likelihood > best) {
          best = possibilities[i].likelihood;
          idx = i;
        }
      }
      for (int i = 0; i < possibilities[idx].contents.size(); ++i) {
        cout << possibilities[idx].contents[i];
      }
      cout << endl;
    }
  }
  return 0;
}