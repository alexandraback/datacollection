#include <cstdio>
#include <string>
#include <algorithm>
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

bool is_pali (long long x) {
  char buf[100];
  int len = 0;
  while (x) {
    buf[len++] = x % 10;
    x /= 10;
  }
  for (int i = 0; i + i < len; i++) {
    if (buf[i] != buf[len - i - 1]) {
      return false;
    }
  }
  return true;
}


bool is_pali (const string &s) {
  string revs(s.rbegin(), s.rend()); 
  return s == revs;
}
bool check (const string &s, string *sq) {
  if (!is_pali (s)) {
    return false;
  }
  int n = (int)s.size();
  assert (n >= 1);
  vector <int> v (n * 2 + 2);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int add = (s[i] - '0') * (s[j] - '0');
      v[i + j] += add;
    }
  }
  for (int i = 0, carry = 0; i < n * 2; i++) {
    v[i] += carry;
    carry = v[i] / 10;
    v[i] %= 10;
  }
  int nn = n * 2 + 1;
  while (nn && !v[nn]) {
    nn--;
  }
  nn++;
  string res;
  for (int i = 0; i < nn; i++) {
    res += v[i] + '0';
  }
  bool ok = is_pali (res);
  if (sq != NULL) {
    *sq = res;
  }
  return ok;
}

void test (vector <string> *p, vector <string> *p2, const string &old, const string &add) {
  string tmp = old + add;
  reverse (tmp.begin(), tmp.end());
  tmp += add;
  assert (is_pali (tmp));

  string x2;
  if (check (tmp, &x2)) {
    p->push_back (tmp);
    p2->push_back (x2);
  }
}

bool cmp (const string &a, const string &b) {
  if (a.size() != b.size()) {
    return a.size() < b.size();
  }
  return a < b;
}

void gen_stupid (int len, vector <string> *res_p, vector <string> *res_p2) {
  vector <string> p, p2;
  p.push_back ("");
  p2.push_back ("");
  long long mx = 1;
  while (len--) {
    mx *= 10;
  }
  for (long long i = 0; i < mx; i++) {
    char buf[1000];
    char buf2[1000];
    sprintf (buf, "%lld", i); 
    bool ok1 = is_pali (i) && is_pali (i * i);
    
    sprintf (buf2, "%lld", i * i); 
    if (ok1) {
      p.push_back (buf);
      p2.push_back (buf2);
    }
  }
  *res_p = p;
  *res_p2 = p2;
}
void gen (int mx, vector <string> *res_p, vector <string> *res_p2) {
  vector <string> p, p2;
  gen_stupid (4, &p, &p2);

  for (int len = 5; len <= mx; len++) {
    int pn = (int)p.size();
    for (int i = 0; i < pn; i++) {
      string old = p[i];
      if (old.size() % 2 != len % 2) {
        continue;
      }
      int add = (len - (int)old.size()) / 2;
      test (&p, &p2, old, string (add - 1, '0') + "1");
      test (&p, &p2, old, string (add - 1, '0') + "2");
    }
  }
  sort (p.begin(), p.end(), cmp);
  sort (p2.begin(), p2.end(), cmp);
  *res_p = p;
  *res_p2 = p2;
}

int main (void) {
  {
    vector <string> a, b, c, d;
    gen (7, &a, &b);
    gen_stupid (7, &c, &d);
    assert (a.size() == c.size());
    assert (b.size() == d.size());
    for (int i = 0; i < (int)a.size(); i++) {
      if (b[i] != d[i]) {
        cout << "[" << a[i] << " " << b[i] << "] [" << c[i] << " " << d[i] << "]\n";
      }
    }
    assert (a == c);
    assert (b == d);
  }
  vector <string> p1, p2;
  gen (52, &p1, &p2);
  fprintf (stderr, "READY\n");

  int tn;
  scanf ("%d", &tn);
  for (int ti = 1; ti <= tn; ti++) {
    string A, B;
    cin >> A >> B;
    int res = upper_bound (p2.begin(), p2.end(), B, cmp) - lower_bound (p2.begin(), p2.end(), A, cmp);
    printf ("Case #%d: %d\n", ti, res);
  }

  return 0;
}
