#include <iostream>
#include <map>
#include <vector>
using namespace std;

typedef struct {
  bool neg;
  string rep;
} val;

val times(val left, val right) {
  val ret;
  ret.neg = left.neg ^ right.neg;
  if (left.rep == "1") {
    ret.rep = right.rep;
  } else if (right.rep == "1") {
    ret.rep = left.rep;
  } else if (left.rep == right.rep) {
    ret.rep = "1";
    ret.neg = !ret.neg;
  } else if (left.rep == "i" && right.rep == "j") {
    ret.rep = "k";
  } else if (left.rep == "i" && right.rep == "k") {
    ret.rep = "j";
    ret.neg = !ret.neg;
  } else if (left.rep == "j" && right.rep == "i") {
    ret.rep = "k";
    ret.neg = !ret.neg;
  } else if (left.rep == "j" && right.rep == "k") {
    ret.rep = "i";
  } else if (left.rep == "k" && right.rep == "i") {
    ret.rep = "j";
  } else {
    ret.rep = "i";
    ret.neg = !ret.neg;
  }
  return ret;
}

int main() {
  int T; cin >> T;
  long long L, X; string inp;
  for (int caseNum = 1; caseNum <= T; caseNum++) {
    cin >> L >> X >> inp;
    X = min(X%4 + 8, X);
    vector<val> vals;
    for (int i = 0; i < L; i++) {
      val next; next.rep.push_back(inp[i]); next.neg = false; vals.push_back(next);
    }
    val s1, s2, s3; s1.neg = s2.neg = s3.neg = false; s1.rep = s2.rep = s3.rep = "1";
    for (int i = 0; i < X; i++) {
      for (int j = 0; j < L; j++) {
        val next = vals[j];
        if (s1.rep != "i" || s1.neg) {
          s1 = times(s1, next);
        } else if (s2.rep != "j" || s2.neg) {
          s2 = times(s2, next);
        } else {
          s3 = times(s3, next);
        }
      }
    }
    if (!s1.neg && !s2.neg && !s3.neg && s1.rep == "i" && s2.rep == "j" && s3.rep == "k") {
      cout << "Case #" << caseNum << ": " << "YES" << endl;
    } else {
      cout << "Case #" << caseNum << ": " << "NO" << endl;
    }
  }
}
