#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <sstream>
#include <cmath>
#include <vector>
#include <algorithm>
#include "gmpxx.h"

using namespace std;

int len(int n) {
  return (int)(log(n) / log(10)) + 1;
}
  
bool pal(string s) {
  int n = s.length();
  int k = n % 2 == 0 ? n / 2 + 1 : n / 2;
  for (int i = 0; i < k; ++i)
    if (s[i] != s[n - i - 1])
      return false;
  return true;
}

// preprocessing
// requires ~10 minutes

int n;
string c;
vector<string> pals;
mpz_t tester;
char* test_str = new char[120];

void dfs(int i) {
  if (i == n) {
    char tmp1 = c[0], tmp2 = c[n - 1];
    string s00(c);
    c[0] = '2';
    string s01(c);
    c[0] = tmp1;
    c[n - 1] = '2';
    string s02(c);
    c[0] = '2';
    string s03(c);
    string s10(n * 2, '0');
    string s11(n * 2, '0');
    string s12(n * 2, '0');
    string s13(n * 2, '0');
    string s20(n * 2 - 1, '0');
    string s21(n * 2 - 1, '0');
    string s22(n * 2 - 1, '0');
    string s23(n * 2 - 1, '0');

    for (int i = 0; i < n; ++i) {
      s10[i] = s00[i]; s10[n + i] = s00[n - 1 - i];
      s11[i] = s01[i]; s11[n + i] = s01[n - 1 - i];
      s12[i] = s02[i]; s12[n + i] = s02[n - 1 - i];
      s13[i] = s03[i]; s13[n + i] = s03[n - 1 - i];
      s20[i] = s00[i]; 
      s21[i] = s01[i]; 
      s22[i] = s02[i]; 
      s23[i] = s03[i]; 
    }
    for (int i = n - 2; i >= 0; --i) {
      s20[n * 2 - 2 - i] = s00[i];
      s21[n * 2 - 2 - i] = s01[i];
      s22[n * 2 - 2 - i] = s02[i];
      s23[n * 2 - 2 - i] = s03[i];
    }

    mpz_set_str(tester, s10.c_str(), 10);
    mpz_pow_ui(tester, tester, 2);
    mpz_get_str(test_str, 10, tester);
    if (pal(string(test_str))) pals.push_back(s10);

    mpz_set_str(tester, s11.c_str(), 10);
    mpz_pow_ui(tester, tester, 2);
    mpz_get_str(test_str, 10, tester);
    if (pal(string(test_str))) pals.push_back(s11);

    mpz_set_str(tester, s12.c_str(), 10);
    mpz_pow_ui(tester, tester, 2);
    mpz_get_str(test_str, 10, tester);
    if (pal(string(test_str))) pals.push_back(s12);

    mpz_set_str(tester, s13.c_str(), 10);
    mpz_pow_ui(tester, tester, 2);
    mpz_get_str(test_str, 10, tester);
    if (pal(string(test_str))) pals.push_back(s13);

    mpz_set_str(tester, s20.c_str(), 10);
    mpz_pow_ui(tester, tester, 2);
    mpz_get_str(test_str, 10, tester);
    if (pal(string(test_str))) pals.push_back(s20);

    mpz_set_str(tester, s21.c_str(), 10);
    mpz_pow_ui(tester, tester, 2);
    mpz_get_str(test_str, 10, tester);
    if (pal(string(test_str))) pals.push_back(s21);

    mpz_set_str(tester, s22.c_str(), 10);
    mpz_pow_ui(tester, tester, 2);
    mpz_get_str(test_str, 10, tester);
    if (pal(string(test_str))) pals.push_back(s22);


    mpz_set_str(tester, s23.c_str(), 10);
    mpz_pow_ui(tester, tester, 2);
    mpz_get_str(test_str, 10, tester);
    if (pal(string(test_str))) pals.push_back(s23);

    c[0] = tmp1;
    c[n - 1] = tmp2;

  } else {
    if (i == 0) {
      c[i] = '1';
      dfs(i + 1);
    } else {
      c[i] = '0'; dfs(i + 1);
      c[i] = '1'; dfs(i + 1);
    }
  }
}



void preprocessing() {
  freopen("output.txt", "w", stdout);
  mpz_init_set_str(tester, "123", 10);
  for (n = 1; n <= 26; ++n) {
    cerr << n << '\n';
    c = string(n, '0');
    dfs(0);
  }

  for (vector<string>::iterator it = pals.begin(), e = pals.end(); it != e; ++it)
    cout << *it << '\n';
}

vector<string> pals2;

string square(string s) {
  mpz_set_str(tester, s.c_str(), 10); 
  mpz_pow_ui(tester, tester, 2);
  mpz_get_str(test_str, 10, tester);
  string ss(test_str);
  return ss;
}

bool stringCompare( const string &s1, const string &s2 ){
  int l1 = s1.length(), l2 = s2.length();
  if (l1 != l2)
    return l1 < l2;
  else
    for (int i = 0; i < l1; ++i)
      if (s1[i] != s2[i])
        return s1[i] < s2[i];
  return false;
}

void preprocessing2() {
  freopen("preprocessing.txt", "w", stdout);
  string s;
  freopen("output.txt", "r", stdin);
  while (cin >> s)
    pals2.push_back(s);
  // freopen("output2.txt", "r", stdin);
  // while (cin >> s)
    // pals2.push_back(s);
  // freopen("output3.txt", "r", stdin);
  // while (cin >> s)
    // pals2.push_back(s);
  sort(pals2.begin(), pals2.end(), stringCompare);  
  vector<string>::iterator it;
  it = std::unique(pals2.begin(), pals2.end());
  pals2.resize(std::distance(pals2.begin(), it));
  for (int i = 0; i < (int)pals2.size(); ++i)
    cout << pals2[i] << '\n';
}

//preprocessing ends. sorry guys for lots of thrash code and third-party libs :(

vector<string> pals3;
bool stringCompare2( const string &s1, const string &s2 ){
  //s2 - our string; s1 - from pals3
  string ss = square(s1);
  return stringCompare(ss, s2);
}

int main() {
  ios_base::sync_with_stdio(0);
  ifstream prepr("preprocessing.txt", ifstream::in);
  string s;
  while (prepr >> s) pals3.push_back(s);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int t;
  mpz_init_set_str(tester, "123", 10);
  // int j = lower_bound(pals3.begin(), pals3.end(), "45647826578657823657823681", stringCompare2) - pals3.begin();
  // cout << j << '\n';
  cin >> t;
  // cerr << t;
  string a, b;
  for (int i = 0; i < 20; ++i) cerr << pals3[i] << '\n';
  for (int i = 1; i <= t; ++i) {
    cin >> a >> b;
    // cout << t << ' ' << a << ' ' << b << '\n';
    int l = lower_bound(pals3.begin(), pals3.end(), a, stringCompare2) - pals3.begin();
    int r = upper_bound(pals3.begin(), pals3.end(), b, stringCompare2) - pals3.begin();
    cout << pals3[l] << ' ' << pals3[r] << ' ' << (r - l) << '\n';

  }
  // preprocessing2();
  return 0;

}
