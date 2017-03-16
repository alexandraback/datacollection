#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> dict;
int INF = 100;

int main() {
  //ifstream in("dict1.txt");
  ifstream in("garbled_email_dictionary.txt");
  int n = 0;
  string s;
  while (in >> s) {
    dict.push_back(s);
    ++n;
  }
  in.close();
  int n_tests;
  scanf("%d", &n_tests);
  for (int test = 1; test <= n_tests; ++test) {
    cerr << "test " << test << endl;
    char s[100];
    scanf(" %s", s);
    int len = strlen(s);
    //cout << "a" << endl;
    vector<vector<bool> > legal(len, vector<bool>(n));
    ;
    vector<vector<int> > first(len, vector<int>(n));
    vector<vector<int> > last(len, vector<int>(n));
    vector<vector<int> > cnt(len, vector<int>(n));
    for (int pos = 0; pos < len; ++pos) {
      for (int t = 0; t < n; ++t) {
        if (pos + dict[t].size() - 1 >= len) {
          legal[pos][t] = false;
        } else {
          cnt[pos][t] = 0;
          legal[pos][t] = true;
          for (int i = pos; i < pos + dict[t].size() && legal[pos][t]; ++i) {
            if (s[i] != dict[t][i - pos]) {
              if (cnt[pos][t] == 0) {
                first[pos][t] = last[pos][t] = i;
              } else {
                if (i - last[pos][t] < 5) {
                  legal[pos][t] = false;
                }
                last[pos][t] = i;
              }
              ++cnt[pos][t];
            }
          }
        }
      }
    }
    int T[len + 1][5];
    for (int pos = len; pos >= 0; --pos) {
      for (int lst = 0; lst <= 4; ++lst) {
        if (pos == len) {
          T[pos][lst] = 0;
        } else {
          T[pos][lst] = -1;
          for (int t = 0; t < n; ++t) {
            if (legal[pos][t]) {
              int last_error = pos - lst - 1;
              if (cnt[pos][t] > 0 && first[pos][t] - last_error < 5) {
                continue;
              }
              if (cnt[pos][t] > 0) {
                last_error = last[pos][t];
              }
              int w = T[pos + dict[t].size()][min((long unsigned int) 4,
                  (pos + dict[t].size() - 1) - last_error)];
              if (w != -1) {
                int tmp = cnt[pos][t] + w;
                if (T[pos][lst] == -1 || T[pos][lst] > tmp) {
                  T[pos][lst] = tmp;
                }
              }
            }
          }
        }
      }
    }
    printf("Case #%d: %d\n", test, T[0][4]);
    //exit(1);
  }
  return 0;
}
