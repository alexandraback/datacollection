#include <iostream>
#include <map>
#include <utility>
#include <string>
#include <vector>
using namespace std;

class Quaternion {
public:
  Quaternion(char v = '1', int s = 1) : value(v), sign(s) {}
  char value;
  int sign;
  bool operator==(const Quaternion& that) {
    return this->value == that.value && this->sign == that.sign;
  }
  bool operator!=(const Quaternion& that) {
    return !this->operator==(that);
  }
  string str() {
    string x;
    if (sign == -1) {
      x += '-';
    }
    x += value;
    return x;
  }
};

Quaternion operator*(const Quaternion& l, const Quaternion& r) {
  static map<char, map<char, pair<char, int>>> matrix = {
    {'1', {{'1', {'1', 1}}, {'i', {'i',  1}}, {'j', {'j',  1}}, {'k', {'k',  1}}}},
    {'i', {{'1', {'i', 1}}, {'i', {'1', -1}}, {'j', {'k',  1}}, {'k', {'j', -1}}}},
    {'j', {{'1', {'j', 1}}, {'i', {'k', -1}}, {'j', {'1', -1}}, {'k', {'i',  1}}}},
    {'k', {{'1', {'k', 1}}, {'i', {'j',  1}}, {'j', {'i', -1}}, {'k', {'1', -1}}}},
  };
  auto res = matrix[l.value][r.value];
  return Quaternion(res.first, l.sign * r.sign * res.second);
}

string run() {
  long long L, X;
  cin >> L >> X;
  string l;
  cin >> l;
  Quaternion q;
  long long i, j, k;
  // for (i = 0; i < min(4LL, X) * L; i++) {
  for (i = 0; i < X * L; i++) {
    if (q == Quaternion('i')) {
      break;
    }
    q = q * Quaternion(l[i % L]);
  }
  if (q != Quaternion('i')) {
    return "NO";
  }
  for (j = i; j < X * L /* && j - i < 4 * L */; j++) {
    if (q == Quaternion('k')) {
      break;
    }
    q = q * Quaternion(l[j % L]);
  }
  if (q != Quaternion('k')) {
    return "NO";
  }
  long long K = (X * L - j) / L / 4;
  K = 0;
  for (k = j; k < (X - K) * L; k++) {
    q = q * Quaternion(l[k % L]);
  }
  return q == Quaternion('1', -1) ? "YES" : "NO";
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": " << run() << endl;
  }
  return 0;
}
