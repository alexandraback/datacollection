#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class com {
 public:
  int a;
  bool* b;
  com() {
    b = new bool[501];
    for (int i = 0; i < 501; ++i) {
      b[i] = false;
    }
  }
  ~com() {
    delete[] b;
  }
  bool operator < (const com& c) const {
    return a < c.a;
  }
  bool operator == (const com& c) const {
    bool t = true;
    for (int i = 0; i < 501; ++i) {
      if (c.b[i] != b[i]) {
        t = false;
        break;
      }
    }
    return t;
  }
  com(const com& c) {
    a = c.a;
    b = new bool[501];
    for (int i = 0; i < 501; ++i) {
      b[i] = c.b[i];
    }
  }
};

int main() {
  int total;
  cin >> total;
  for (int totalCount = 0; totalCount < total; ++totalCount) {
    vector<com> s;
    vector<int> used;
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
      int tmp;
      cin >> tmp;
      used.push_back(tmp);
      com c;
      c.a = tmp;
      c.b[i] = true;
      s.push_back(c);
    }
    //cerr << "test1" << endl;
    vector < vector <com> > r;
    bool done = false;
    int haha;
    r.push_back(s);
    //cerr << "test2" << endl;
    for (int i = 1; i < N; ++i) {
      vector<com> z;
      r.push_back(z);
      for (int j = 0; j < r[i-1].size(); ++j) {
        for (int k = 0; k < N; ++k) {
          //cerr << "i:" << i << " j:" << j << " k:" << k << endl;
          if (!r[i-1][j].b[k]) {
            //cerr << "in" << endl;
            com tmp(r[i-1][j]);
            tmp.a += s[k].a;
            tmp.b[k] = true;
            //cerr << "in1" << endl;
            bool same = false;
            for (int l = 0; l < r[i].size(); ++l) {
              if (tmp == r[i][l]) {
                same = true;
                break;
              }
            }
            if (same) {
              continue;
            }
            r[i].push_back(tmp);
            //cerr << "in2" << endl;
            for (int n = 0; n < used.size(); ++n) {
              if (tmp.a == used[n]) {
                done = true;
                haha = used[n];
                break;
              }
            }
            //cerr << "out" << endl;
            if (done) {
              break;
            } else {
              used.push_back(tmp.a);
            }
          }
        }
        if (done) {
          break;
        }
      }
      if (done) {
        break;
      }
    }
    cout << "Case #" << totalCount + 1<< ": ";
    if (done) {
      cout << endl;
      for (int i = 0; i < r.size(); ++i) {
        for (int j = 0; j < r[i].size(); ++j) {
          if (r[i][j].a == haha) {
            for (int k = 0; k < N; ++k) {
              if (r[i][j].b[k]) {
                cout << s[k].a << " ";
              }
            }
            cout << endl;
          }
        }
      }
    } else {
      cout << "Impossible" << endl;
    }
  }
}
