#include <bits/stdc++.h>

using namespace std;

int L;
int64_t X;
string S;

struct Quarternion {
  char c;
  int sign;

  Quarternion() : c(' '), sign(1) {}
  Quarternion(char c_) : c(c_), sign(1) {}
  Quarternion(char c_, int s_) : c(c_), sign(s_) {}

  Quarternion operator*(const Quarternion& r) const {
    int s = sign * r.sign;
    if (c == ' ') {
      return Quarternion(r.c, s);
    } else if (r.c == ' ') {
      return Quarternion(c, s);
    }

    if (c == r.c) {
      return Quarternion(' ', -s);
    } else if (c == 'i' && r.c == 'j') {
      return Quarternion('k', s);
    } else if (c == 'j' && r.c == 'k') {
      return Quarternion('i', s);
    } else if (c == 'k' && r.c == 'i') {
      return Quarternion('j', s);
    } else if (c == 'j' && r.c == 'i') {
      return Quarternion('k', -s);
    } else if (c == 'k' && r.c == 'j') {
      return Quarternion('i', -s);
    } else if (c == 'i' && r.c == 'k') {
      return Quarternion('j', -s);
    }

    assert(0);
  }

  void operator*=(const Quarternion& r) {
    Quarternion q = *this * r;
    c = q.c;
    sign = q.sign;
  }

  bool Is(char x) const {
    return c == x && sign == 1;
  }

  bool IsIJK() const {
    return c == ' ' && sign == -1;
  }

  bool operator==(const Quarternion& r) const {
    return c == r.c && sign == r.sign;
  }
};

ostream& operator<<(ostream& os, const Quarternion& q) {
  if (q.c == ' ') {
    os << q.sign;
  } else {
    if (q.sign == 1) {
      os << q.c;
    } else {
      os << '-' << q.c;
    }
  }
  return os;
}

namespace std {
template <>
struct hash<Quarternion> {
  size_t operator () (const Quarternion& q) const {
    return q.c * q.sign;
  }
};
}  // namespace std

Quarternion modpow(Quarternion a, int64_t x) {
  if (x == 0) {
    return Quarternion(' ', 1);
  } else if (x == 1) {
    return a;
  }

  Quarternion res = modpow(a * a, x / 2);
  if (x % 2 == 1) {
    res *= a;
  }
  return res;
}

void Input() {
  cin >> L >> X;
  cin >> S;
}

void Solve() {
  Quarternion s;
  for (char c : S) s *= Quarternion(c);

  Quarternion t = modpow(s, X);
  if (!t.IsIJK()) {
    printf("NO");
    return;
  }

  string T;
  for (int i = 0; i < 6 && i < X; i++) T += S;

  int firstI = -1;
  Quarternion left;
  for (int i = 0; i < T.size(); i++) {
    left *= Quarternion(T[i]);
    if (left.Is('i')) {
      firstI = i;
      break;
    }
  }

  int lastK = -1;
  for (int i = T.size() - 1; i >= 0; i--) {
    Quarternion right;
    for (int j = i; j < T.size(); j++) {
      right *= Quarternion(T[j]);
    }
    if (right.Is('k')) {
      lastK = i;
      break;
    }
  }

  if (firstI == -1 || lastK == -1) {
    printf("NO");
    return;
  }

  if (firstI + 1 >= lastK) {
    printf("NO");
    return;
  }

  printf("YES");
}

int main(int argc, char **argv) {
  (void)argc;
  (void)argv;
  //  string inputFile  = "./data/C-practice.in";
  //  string outputFile = "./data/C-practice.out";
  //  string inputFile  = "./data/C-small-attempt1.in";
  //  string outputFile = "./data/C-small-attempt1.out";
  string inputFile  = "./data/C-large.in";
  string outputFile = "./data/C-large.out";

  freopen(inputFile.c_str(), "r", stdin);
  freopen(outputFile.c_str(), "w", stdout);

  fprintf(stderr, "Read from input: %s\n", inputFile.c_str());
  fprintf(stderr, "Write to output: %s\n", outputFile.c_str());

  int T;
  string line;
  {
    getline(cin, line);
    istringstream is(line);
    is >> T;
  }

  for (int test_case = 1; test_case <= T; ++test_case) {
    Input();
    printf("Case #%d: ", test_case);
    Solve();
    printf("\n");
  }

  return 0;
}
