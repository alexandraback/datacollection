#include <map>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cassert>
#include <cstring>

using namespace std;

int N;
string L[100];
int S[100];
int P[100];
int vis[100];

bool cn[100][100];

long long gcd(long long a, long long b) {
  return a ? gcd(b % a, a) : b;
}

struct rat {
  rat() : n(0), d(1) {}
  rat(long long x) : n(x), d(1) {}

  rat(long long a, long long b) {
    long long g = gcd(abs(a), abs(b));
    if(b < 0) g *= -1;
    n = a / g;
    d = b / g;
  }

  rat operator+(const rat& x) const {
    return rat(n * x.d + x.n * d, d * x.d);
  }

  rat operator*(const rat& x) const {
    return rat(n * x.n, d * x.d);
  }

  bool operator<(const rat& x) const {
    return n * x.d < x.n * d;
  }

  bool operator==(const rat& x) const {
    return n == x.n && d == x.d;
  }

  long long n, d;
};

const rat EPS(1, 5000);

void diff(int i, int j) {
  cn[i][j] = cn[j][i] = true;
}

void clear(int i) {
  for(int j = 0; j < N; j++) {
    cn[i][j] = cn[j][i] = false;
  }
}

bool dfs(int x, int c) {
  if(vis[x] != -1) return vis[x] == c;
  vis[x] = c;
  for(int i = 0; i < N; i++) {
    if(cn[x][i] && !dfs(i, !c)) {
      return false;
    }
  }
  return true;
}

bool consistent() {
  memset(vis, -1, sizeof(vis));
  for(int i = 0; i < N; i++) {
    if(vis[i] != -1) continue;
    if(!dfs(i, 0)) return false;
  }
  return true;
}

void update(rat tm) {
  vector<rat> X;
  for(int i = 0; i < N; i++) {
    X.push_back(tm * S[i] + P[i]);
  }
  for(int i = 0; i < N; i++) {
    bool ok = true;
    for(int j = 0; j < N; j++) {
      if(i == j) continue;
      if(X[i] < X[j] + 5 && X[j] < X[i] + 5) {
        ok = false;
        diff(i, j);
      }
    }
    if(ok) clear(i);
  }
}

int main() {
  int T; cin >> T;
  for(int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": ";

    cin >> N;
    for(int i = 0; i < N; i++) {
      clear(i);
      cin >> L[i] >> S[i] >> P[i];
    }
    for(int i = 0; i < N; i++) {
      for(int j = 0; j < N; j++) {
        if(i != j && L[i] != L[j]) {
          diff(i, j);
        }
      }
    }
    assert(consistent());
    update(0);
    assert(consistent());
    update(EPS + 0);
    if(!consistent()) {
      cout << "0" << endl;
      continue;
    }

    vector<rat> tms;
    for(int i = 0; i < N; i++) {
      for(int j = 0; j < N; j++) {
        if(S[i] == S[j]) continue;
        rat tm = rat(5 + P[i] - P[j], S[j] - S[i]);
        if(S[i] > S[j] && tm.n > 0) tms.push_back(tm);
      }
    }
    sort(tms.begin(), tms.end());
    tms.resize(unique(tms.begin(), tms.end()) - tms.begin());

    int ii;
    for(ii = 0; ii < tms.size(); ii++) {
      update(tms[ii]);
      assert(consistent());
      update(tms[ii] + EPS);
      if(!consistent()) break;
    }
    if(ii == tms.size()) {
      cout << "Possible" << endl;
    } else {
      printf("%.9f\n", 1. * tms[ii].n / tms[ii].d);
    }
  }
}
