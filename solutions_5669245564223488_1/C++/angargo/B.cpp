#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<ll> VLL;

int n;
int mod = 1000000007;
VLL fact;

bool correct(VS& v, VI& p) {
  VI ch(256);
  int k = 0, pos = 0;
  while (k < n) {
    char current = v[p[k]][pos];
    if (ch[current]) return false;
    while (k < n and v[p[k]][pos] == current) {
      int size = v[p[k]].size();
      while (pos < size and v[p[k]][pos] == current) ++pos;
      if (pos == size) {
        ++k;
        pos = 0;
      }
    }
    ch[current] = true;
  }
  return true;
}

bool has_character(string& s, char c) {
  int size = s.size();
  for (int i = 0; i < size; ++i) if (s[i] == c) return true;
  return false;
}

bool middle(string& s, char c) {
  int size = s.size();
  for (int i = 1; i < size - 1; ++i) if (s[i] == c) return true;
  return false;
}

int compute(VS& v) {
  ll res = 1;
  for (char c = 'a'; c <= 'z'; ++c) {
    VS next, has;
    int size = v.size();
    for (int i = 0; i < size; ++i) {
      if (has_character(v[i], c)) has.push_back(v[i]);
      else next.push_back(v[i]);
    }
    int k = has.size();
    if (k) {
      int l1 = 0, ini = -1, end = -1, mid = -1;
      for (int i = 0; i < k; ++i) {
        if (has[i].size() == 1) ++l1;
        else {
          if (has[i][0] == c) {
            if (ini == -1) ini = i;
            else return 0;
          }
          if (has[i][has[i].size() - 1] == c) {
            if (end == -1) end = i;
            else return 0;
          }
          if (middle(has[i], c)) {
            if (mid == -1) mid = i;
            else return 0;
          }
        }
      }
      if (mid == -1) {
        res = (res * fact[l1]) % mod;
        string s = "";
        if (end != -1) {
          int size = has[end].size();
          for (int i = 0; i < size - 1; ++i) s += has[end][i];
        }
        s += c;
        if (ini != -1) {
          int size = has[ini].size();
          for (int i = 1; i < size; ++i) s += has[ini][i];
        }
        next.push_back(s);
      }
      else {
        if (l1 > 0 or ini != -1 or end != -1) return 0;
        next.push_back(has[mid]);
      }
    }
    v = next;
  }
  res = (res * fact[v.size()]) % mod;
  return res;
}

void solve() {
  cin >> n;
  VS v(n);
  for (int i = 0; i < n; ++i) {
    string tmp;
    cin >> tmp;
    int size = tmp.size();
    v[i] = "";
    v[i] += tmp[0];
    for (int j = 1; j < size; ++j) if (tmp[j] != v[i][v[i].size() - 1]) v[i] += tmp[j];
    // cerr << tmp << " -> " << v[i] << endl;
  }
  
  cout << compute(v) << endl;
  return;
  
  VI p(n);
  for (int i = 0; i < n; ++i) p[i] = i;
  
  int res = 0;
  do {
    if (correct(v, p)) ++res;
  } while (next_permutation(p.begin(), p.end()));
  
  cout << res << " " << compute(v) << endl;
}

int main() {
  fact = VLL(1000);
  fact[0] = 1;
  for (int f = 1; f < 1000; ++f) fact[f] = (fact[f - 1] * f) % mod;
  
  int t;
  cin >> t;
  for (int z = 0; z < t; ++z) {
    cout << "Case #" << z + 1 << ": ";
    solve();
  }
}