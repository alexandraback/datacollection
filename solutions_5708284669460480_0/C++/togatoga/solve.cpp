#include <iostream>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <numeric>
#include <sstream>
#include <algorithm>
#include <functional>
#include <limits.h>
#include <bitset>

#include <tuple>
#include <unordered_map>

#define mp make_pair
#define mt make_tuple
#define pb push_back
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int INF = 1 << 29;
const double EPS = 1e-9;

const int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};
int T;
int K, L, S;
string src, tar;

int main() {
  int Test = 1;
  cin >> T;
  while (T--) {
    cin >> K >> L >> S; // key, target, typed
    cin >> src;         // keyboard
    cin >> tar;         // target
    // S monkey typed
    set<char> s1;
    s1.clear();
    for (int i = 0; i < K; i++) {
      s1.insert(src[i]);
    }
    bool ok = true;
    double answer = 0;
    for (int i = 0; i < L; i++) {
      if (s1.count(tar[i]) == 0) {
        ok = false;
      }
    }

    if (ok) {
      map<char, int> pro;
      pro.clear();
      set<char> alphakey;
      alphakey.clear();
      for (int i = 0; i < K; i++) { // key
        pro[src[i]]++;
        alphakey.insert(src[i]);
      }

      // cout << banana << endl;
      queue<string> que;
      // cout << "que.size() = " << que.size() << endl;
      que.push("");
      set<string> cand;
      set<string> res;
      while (!que.empty()) {
        string tmp = que.front();
        cand.insert(tmp);
        que.pop();
        if (tmp.length() == S) {
          res.insert(tmp);
          continue;
        }

        for (const auto &val : alphakey) {
          if (cand.count(tmp + val))
            continue;
          que.push(tmp + val);
        }
      }
      double banana = 0;
      double b = 0;
      for (const auto val : res) {
        double tmp = 0;
        for (int i = 0; i + L <= val.length(); i++) {
          if (val.substr(i, L) == tar) {
            tmp++;
          }
        }
        b = max(b, tmp);
      }
      // cout << banana << endl;
      for (const auto val : res) {
        double tmp = 0;
        banana = b;
        // cout << "val = " << val << endl;
        for (int i = 0; i + L <= val.length(); i++) {
          if (val.substr(i, L) == tar) {
            tmp++;
          }
        }
        // if (tmp <= 0)
        // continue;
        banana -= tmp;
        for (int i = 0; i < val.length(); i++) {
          banana *= (double)pro[val[i]] / K;
        }
        answer += banana;
      }
    } else {
      answer = 0;
    }
    printf("Case #%d: %.10lf\n", Test++, answer);
  }

  return 0;
}