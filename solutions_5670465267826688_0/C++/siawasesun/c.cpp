#include <bits/stdc++.h>

using namespace std;

int L, X;
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

void Input() {
  cin >> L >> X;
  cin >> S;
}

void Solve() {
  L *= X;
  string T = "";
  for (int i = 0; i < X; i++) T += S;

  Quarternion t;
  for (char c : T) t *= Quarternion(c);
  if (!t.IsIJK()) {
    printf("NO");
    return;
  }

  Quarternion left;
  for (int a = 0; a + 1 < L; a++) {
    left *= Quarternion(T[a]);
    if (!left.Is('i')) continue;

    Quarternion middle;
    for (int b = a + 1; b + 1 < L; b++) {
      middle *= Quarternion(T[b]);
      if (middle.Is('j')) {
        printf("YES");
        return;
      }
    }
  }

  printf("NO");
}

int main(int argc, char **argv) {
  (void)argc;
  (void)argv;
  //  string inputFile  = "./data/C-practice.in";
  //  string outputFile = "./data/C-practice.out";
  string inputFile  = "./data/C-small-attempt1.in";
  string outputFile = "./data/C-small-attempt1.out";
  //  string inputFile  = "./data/C-large.in";
  //  string outputFile = "./data/C-large.out";

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
