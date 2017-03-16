// TEMPLATE {{{
#include <bits/stdc++.h>
using namespace std;
#ifndef LOCAL
#define OJ 1
#else
#define OJ 0
#endif

#define endl '\n'
#define TIMESTAMP merr << "Execution time: " << (double)clock()/CLOCKS_PER_SEC << " s.\n"
class C_ {}; template <typename T> C_& operator <<(C_& __m, const T& __s) { if (!OJ) cerr << "\E[91m" << __s << "\E[0m"; return __m; }
C_ merr;

struct __s { __s() { if (OJ) { ios_base::Init i; cin.sync_with_stdio(0); cin.tie(0); } } ~__s(){ TIMESTAMP; } } __S;
/// END OF TEMPLATE }}}

int k;

int obj(const vector<int> & V) {
  int cnt = 0;
  int C12[11][11] = {};
  int C13[11][11] = {};
  int C23[11][11] = {};
  for (int i = 0; i < (int)V.size(); i++) {
    int x = V[i];
    int i1,i2,i3;
    i3 = x%20; x /= 20;
    i2 = x%20; x /= 20;
    i1 = x;
    if (C12[i1][i2] >= k) continue;
    if (C13[i1][i3] >= k) continue;
    if (C23[i2][i3] >= k) continue;
    C12[i1][i2]++;
    C13[i1][i3]++;
    C23[i2][i3]++;
    cnt++;
  }
  return cnt;
}

void move(vector<int> & V, int & d, double t) {
  int a = rand()%(int)V.size();
  int b = rand()%(int)V.size();
  double p = (double)rand()*1.0/CLOCKS_PER_SEC;
  swap(V[a], V[b]);
  int dd = obj(V);
  if (dd > d || p < exp(V.size()-dd)/t) {
    d = dd;
    return;
  }
  swap(V[a], V[b]);
}

vector<int> restore(const vector<int> & V) {
  int C12[11][11] = {};
  int C13[11][11] = {};
  int C23[11][11] = {};
  vector<int> VV;
  for (int i = 0; i < (int)V.size(); i++) {
    int x = V[i];
    int i1,i2,i3;
    i3 = x%20; x /= 20;
    i2 = x%20; x /= 20;
    i1 = x;
    if (C12[i1][i2] >= k) continue;
    if (C13[i1][i3] >= k) continue;
    if (C23[i2][i3] >= k) continue;
    C12[i1][i2]++;
    C13[i1][i3]++;
    C23[i2][i3]++;
    VV.push_back(V[i]);
  }
  return VV;
}

vector<int> sa(vector<int> V) {
  random_shuffle(V.begin(), V.end());
  vector<int> VV = V;
  int d = obj(V);
  int dd = d;
  double initt = 1000;
  double t = initt;
  int lim = 7;
  int cnt = 0;
  while (1) {
    for (int i = 0; i < lim; i++) {
      move(V, d, t);
      if (d > dd) {
        dd = d;
        VV = V;
      }
    }
    t *= 0.99;
    if (t < 0.0001) {
      cnt++;
      t = initt;
      d = dd;
      V = VV;
      if (cnt > 60) break;
    }
  }
  return restore(V);
}

int main(void) {
  int T;
  srand((int)time(0));
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
  cin >> T;
  for (int tt = 0; tt < T; tt++) {
    int j,p,s;
    cin >> j >> p >> s >> k;
    cout << "Case #" << tt+1 << ": ";
    merr << "Case #" << tt+1 << ": ";
    vector<int> V;
    for (int i1 = 1; i1 <= j; i1++) {
      for (int i2 = 1; i2 <= p; i2++) {
        for (int i3 = 1; i3 <= s; i3++) {
          V.push_back(i1*400 + i2*20 + i3);
        }
      }
    }
    vector<int> VA = sa(V);
    cout << VA.size() << endl;
    merr << VA.size() << endl;
    for (int i = 0; i < (int)VA.size(); i++) {
      int x = VA[i];
      int i1,i2,i3;
      i3 = x%10; x /= 10;
      i2 = x%10; x /= 10;
      i1 = x;
      cout << i1 << " " << i2 << " " << i3 << endl;
    }
  }
  return 0;
}
