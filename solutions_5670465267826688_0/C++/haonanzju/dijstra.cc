#include <iostream>
#include <fstream>
#include <string>

using std::istream; using std::ostream;
using std::ifstream; using std::ofstream;
using std::string;

struct Quaternion {
  int a;
  int b;
  int c;
  int d;
  Quaternion() = default;
  Quaternion(int a0, int b0, int c0, int d0) : a(a0), b(b0), c(c0), d(d0) {}
  Quaternion& operator*=(const Quaternion &rhs) {
    Quaternion lhs = *this;
    a = lhs.a * rhs.a - lhs.b * rhs.b - lhs.c *rhs.c - lhs.d * rhs.d;
    b = lhs.a * rhs.b + lhs.b * rhs.a + lhs.c *rhs.d - lhs.d * rhs.c;
    c = lhs.a * rhs.c - lhs.b * rhs.d + lhs.c *rhs.a + lhs.d * rhs.b;
    d = lhs.a * rhs.d + lhs.b * rhs.c - lhs.c *rhs.b + lhs.d * rhs.a;
    return *this;
  }
};

inline Quaternion getQuat(char c) {
  Quaternion res;
  switch (c) {
  case 'i':
    res = {0, 1, 0, 0};
    break;
  case 'j':
    res = {0, 0, 1, 0};
    break;
  case 'k':
    res = {0, 0, 0, 1};
    break;
  default:
    res = {0, 0, 0, 0};
    break;
  }
  return res;
}

inline Quaternion operator*(const Quaternion &lhs, const Quaternion &rhs) {
  Quaternion res = lhs;
  res *= rhs;
  return res;
}

inline bool operator==(const Quaternion &lhs, const Quaternion &rhs) {
  return lhs.a == rhs.a && lhs.b == rhs.b && lhs.c == rhs.c && lhs.d == rhs.d;
}

inline bool isCase1(const Quaternion &quat) {
  if (quat == Quaternion(1, 0, 0, 0))
      return true;
  return false;
}

inline bool isCase2(const Quaternion &quat) {
  if (quat == Quaternion(-1, 0, 0, 0))
      return true;
  return false;
}

inline bool isCase3(const Quaternion &quat) {
  if (quat == Quaternion(0, 1, 0, 0) ||
      quat == Quaternion(0, 0, 1, 0) || 
      quat == Quaternion(0, 0, 0, 1) ||
      quat == Quaternion(0, -1, 0, 0) ||
      quat == Quaternion(0, 0, -1, 0) ||
      quat == Quaternion(0, 0, 0, -1))
      return true;
  return false;
}

Quaternion eval(const string &str) {
  int sign = 1, val = 1;
  size_t len = str.length();
  Quaternion res = {1, 0, 0, 0};
  for (size_t i = 0; i < len; i++) {
    Quaternion rhs = getQuat(str[i]);
    res *= rhs;
  }
  return res;
}

inline bool isOdd(long long num) {
  return num & 0x1;
}

inline bool isEven(long long num) {
  return !isOdd(num);
}

long long getIPos(long long L, long long X, const string &str) {
  Quaternion quat = {1, 0, 0, 0};
  long long pos = 0;
  bool flag = false;
  while (pos < L * X) {
    quat *= getQuat(str[pos % L]);
    if (quat == Quaternion(0, 1, 0, 0)) {
      flag = true;
      break;
    }
    pos++;
  }
  if (flag)
    return pos + 1;
  else
    return -1;
}

long long getKPos(long long L, long long X, const string &str) {
  Quaternion quat = {1, 0, 0, 0};
  long long pos = 0;
  bool flag = false;
  while (pos < L * X) {
    quat = getQuat(str[L - 1 - pos % L]) * quat;
    if (quat == Quaternion(0, 0, 0, 1)) {
      flag = true;
      break;
    }
    pos++;
  }
  if (flag)
    return pos + 1;
  else
    return -1;
}

void Test(int caseNum, istream &is, ostream &os) {
  long long L, X;
  is >> L >> X;
  string str;
  is >> str;
  bool flag = true;
  if (L * X < 3)
    flag = false;
  Quaternion res;
  if (flag) {
    res = eval(str);
    if (isCase1(res)) {
      flag = false;
    } else if (isCase2(res)) {
      if (isEven(X))
        flag = false;
    } else if (isCase3(res)) {
      if (!(isEven(X) && isOdd(X >> 1)))
        flag = false;
    } else {
      std::cerr << "error" << std::endl;
    }
  }
  if (flag) {
    long long len0 = getIPos(L, X, str),
              len1 = getKPos(L, X, str);
    if (len0 <= 0 || len1 <= 0 || len0 + len1 >= L * X)
      flag = false;
  }
  if (flag)
    os << "Case #" << caseNum << ": YES\n";
  else
    os << "Case #" << caseNum << ": NO\n";
}

int main() {
  ifstream is("C-small-attempt2.in");
  ofstream os("output.txt");
  int T;
  is >> T;
  for (int i = 1; i <= T; i++)
    Test(i, is, os);
  is.close();
  os.close();
  return 0;
}