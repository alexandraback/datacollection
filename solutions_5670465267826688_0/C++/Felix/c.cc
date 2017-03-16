#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

// i -> 2; j -> 3; k ->4 
int m[][4] = {{ 1,  2,  3,  4},
             { 2, -1,  4, -3},
             { 3, -4, -1,  2},
             { 4,  3, -2, -1}};

int sign(int x) {
  if (x >= 0) return 1;
  return -1;
}

int mult(int a, int b) {
  return sign(a) * sign(b) * m[abs(a) - 1][abs(b) - 1];  
}

int i_prefix(const vector<int>& seq, ll x) {
  ll l = ll(seq.size());
  int acc = 1;
  for (ll i = 0; i < min(8LL, x) * l; ++i) {
    acc = mult(acc, seq[i % l]);
    if (acc == 2) return i;
  }
  return l * x;
}

int k_suffix(const vector<int>& seq, ll x) {
  ll l = ll(seq.size());
  int acc = 1;
  for (ll i = l * x - 1; i >= l * x - min(8LL, x) * l; --i) {
    acc = mult(seq[i % l], acc);
    if (acc == 4) return i;
  }
  return -1;
}

int reduce(const vector<int>& seq, ll x, ll left, ll right) {
  ll l = ll(seq.size());
  int acc = 1;
  ll ind = left;
  // Steps of size 1.
  for (; ind < right && (ind % l != 0); ++ind) {
    acc = mult(acc, seq[ind % l]);
  }
  // Steps of size L.
  int reduced_seq = 1;
  for (int i = 0; i < int(seq.size()); ++i) {
    reduced_seq = mult(reduced_seq, seq[i]);
  }
  for (; ind + l <= right; ind += l) {
    acc = mult(acc, reduced_seq);
  }
  // Steps of size 1.
  for (; ind < right; ++ind) {
    acc = mult(acc, seq[ind % l]);
  }
  return acc;
}

int main() {
  int T;
  cin >> T;
  for (int ca = 1; ca <= T; ++ca) {
    ll l, x;
    cin >> l >> x;
    vector<int> seq(l);
    for (int i = 0; i < l; ++i) {
      char c;
      cin >> c;
      seq[i] = 2 + int(c - 'i');
    }
    int left = i_prefix(seq, x) + 1;
    if (left >= l * x) {
      cout << "Case #" << ca << ": NO" << endl;
      continue;
    }
    int right = k_suffix(seq, x);
    if (right <= left) {
      cout << "Case #" << ca << ": NO" << endl;
      continue;
    }
    int middle_reduced = reduce(seq, x, left, right);
    cout << "Case #" << ca << ": ";
    if (middle_reduced == 3) {
      cout << "YES" << endl;
    }
    else {
      cout << "NO" << endl;
    }
  }
}

