#include <algorithm>
#include <iostream>
#include <set>
#include <string>
using namespace std;

string QuatStr = "1ijk";
string QuatTable[4][4] = {
  { "1",  "i",  "j",  "k"},
  { "i", "-1",  "k", "-j"},
  { "j", "-k", "-1",  "i"},
  { "k",  "j", "-i", "-1"}
};

string QuatMult(const string& a, const string& b) {
  bool neg = (a[0] == '-') ^ (b[0] == '-');
  string ret = QuatTable[QuatStr.find(a[a.size()-1])]
                        [QuatStr.find(b[b.size()-1])];
  if (neg) {
    if (ret[0] == '-') return ret.substr(1);
    return "-" + ret;
  }
  return ret;
}

main() {
  long long T, L, X, prob=1;
  for (cin >> T; T--;) {
    string s;
    cin >> L >> X >> s;
    long long lv = 0, rv = X*L;
    set<string> seen[L];
    set<string> seen2[L];

    string pw = "1";
    for (long long i = 0; i < L; i++) pw = QuatMult(pw, string(1, s[i]));
    string cur = "1";
    for (long long x = X; x; x >>= 1) {
      if (x&1) cur = QuatMult(cur, pw);
      pw = QuatMult(pw, pw);
    }
    if (cur != QuatMult("i", QuatMult("j", "k"))) goto fail;

    cur = "1";
    for (long long x = 0; x < X; x++)
    for (long long i = 0; i < L; i++, lv++) {
      if (seen[i].count(cur)) goto fail;
      seen[i].insert(cur);
      cur = QuatMult(cur, string(1, s[i]));
      if (cur == "i") goto pass1;
    }
    goto fail;
pass1:

    cur = "1";
    for (long long x = X-1; x >= 0; x--)
    for (long long i = L-1; i >= 0; i--, rv--) {
      if (cur == "k") goto pass2;
      if (seen2[i].count(cur)) goto fail;
      seen2[i].insert(cur);
      cur = QuatMult(string(1, s[i]), cur);
    }
    goto fail;
pass2:

    if (rv <= lv) goto fail;
    cout << "Case #" << prob++ << ": YES" << endl;
    continue;
fail:
    cout << "Case #" << prob++ << ": NO" << endl;
  }
}
