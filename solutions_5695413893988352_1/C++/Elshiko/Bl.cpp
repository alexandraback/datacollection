#include <iostream>

using namespace std;

bool eq(const string& a, const string& b, int len = 20) {
  //cout << "HERE  " << len << endl;
  //cout << a << " " << b << endl;
  for (int i = 0; i < min((int) a.length(), len); ++i)
    if (a[i] != '?' && b[i] != '?' && a[i] != b[i]) {
      //cout << "FALSE" << endl;
      return false;
    }
  //cout << "TRUE" << endl;
  return true;
}

long long mystoll(const string& s) {
  //cout << s << " : ";
  long long res = 0;
  for (int i = 0; i < (int) s.length(); ++i) {
    res *= 10;
    res += (s[i] - '0');
  }
  //cout << res << endl;
  return res;
}

void upd_ans(string a, string b, int common, long long& ans, string& ansa, string& ansb) {
  for (int i = 0; i < common; ++i)
    if (a[i] == '?' && b[i] == '?')
      a[i] = b[i] = '0';
    else if (a[i] == '?')
      a[i] = b[i];
    else if (b[i] == '?')
      b[i] = a[i];
  if (a[common] == '?' && b[common] == '?') {
    a[common] = '1';
    b[common] = '0';
  } else if (a[common] == '?') {
    if (b[common] == '9')
      return;
    a[common] = b[common] + 1;
  } else if (b[common] == '?') {
    if (a[common] == '0')
      return;
    b[common] = a[common] - 1;
  } else {
    if (b[common] >= a[common])
      return;
  }

  for (int i = common + 1; i < (int) a.length(); ++i)
    if (a[i] == '?')
      a[i] = '0';

  for (int i = common + 1; i < (int) b.length(); ++i)
    if (b[i] == '?')
      b[i] = '9';

  long long la = mystoll(a);
  long long lb = mystoll(b);
  long long ansn = abs(la - lb);

  if (ansn < ans ||
      (ansn == ans && a < ansa) ||
      (ansn == ans && a == ansa && b < ansb)) {
    ans = ansn;
    ansa = a;
    ansb = b;
  }
}

void upd_ans2(string a, string b, int common, long long& ans, string& ansa, string& ansb) {
  for (int i = 0; i < common; ++i)
    if (a[i] == '?' && b[i] == '?')
      a[i] = b[i] = '0';
    else if (a[i] == '?')
      a[i] = b[i];
    else if (b[i] == '?')
      b[i] = a[i];
  if (a[common] == '?' && b[common] == '?') {
    a[common] = '0';
    b[common] = '1';
  } else if (a[common] == '?') {
    if (b[common] == '0')
      return;
    a[common] = b[common] - 1;
  } else if (b[common] == '?') {
    if (a[common] == '9')
      return;
    b[common] = a[common] + 1;
  } else {
    if (b[common] <= a[common])
      return;
  }

  for (int i = common + 1; i < (int) a.length(); ++i)
    if (a[i] == '?')
      a[i] = '9';

  for (int i = common + 1; i < (int) b.length(); ++i)
    if (b[i] == '?')
      b[i] = '0';
  //cout << a << " " << b << endl;

  long long la = mystoll(a);
  long long lb = mystoll(b);
  long long ansn = abs(la - lb);

  //cout << "OLD = " << ansa << " " << ansb << endl;
  //cout << "NEW = " << a << " " << b << endl;

  //cout << (ansn == ans) << " " << (a == ansa) << " " << (b < ansb) << endl;

  if (ansn < ans ||
      (ansn == ans && a < ansa) ||
      (ansn == ans && a == ansa && b < ansb)) {
    ans = ansn;
    ansa = a;
    ansb = b;
  }
}

void set_eq(string& a, string& b) {
  for (int i = 0; i < (int) a.length(); ++i)
    if (a[i] == '?' && b[i] == '?')
      a[i] = b[i] = '0';
    else if (a[i] == '?')
      a[i] = b[i];
    else if (b[i] == '?')
      b[i] = a[i];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tests;
  cin >> tests;
  for (int test = 0; test < tests; ++test) {
    string a, b;
    cin >> a >> b;

    if (eq(a, b)) {
      set_eq(a, b);
      cout << "Case #" << test + 1 << ": " << a << " " << b << endl;
      continue;
    }
    //a > b
    long long ans = 1e+18 + 100;
    string ansa, ansb;
    for (int i = 0; i < (int) a.length(); ++i)
      if (eq(a, b, i))
        upd_ans(a, b, i, ans, ansa, ansb);
    //a < b
    for (int i = 0; i < (int) a.length(); ++i)
      if (eq(a, b, i))
        upd_ans2(a, b, i, ans, ansa, ansb);

    cout << "Case #" << test + 1 << ": " << ansa << " " << ansb << endl;

  }
  return 0;
}
