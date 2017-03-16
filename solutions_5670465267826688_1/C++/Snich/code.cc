#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>

using namespace std;

#define dbg(x) cout << #x << " = " << x << endl; 

int table[5][5] = {{0, 0, 0, 0, 0},
                   {0, 1, 2, 3, 4},
                   {0, 2, -1, 4, -3},
                   {0, 3, -4, -1, 2},
                   {0, 4, 3, -2, -1}};

int convert(char c) {
  switch (c) {
    case 'i':
      return 2;
    case 'j':
      return 3;
    case 'k':
      return 4;
    default:
      cerr << "Wrong character: " << c << endl;
      exit(1);
  }
}

int multiply(int a, int b) {
  int sign = a * b < 0 ? -1 : 1;
  return sign * table[abs(a)][abs(b)];
}

vector<int> get_products(const string &s) {
  vector<int> products(s.length());
  products[0] = convert(s[0]);
  for (size_t i = 1; i < products.size(); ++i) {
    products[i] = multiply(products[i - 1], convert(s[i]));
  }
  return products;
}

bool is_good(const vector<int> &products) {
  size_t i = 0;
  while (i < products.size() && products[i] != 2) ++i;
  //dbg(i)
  while (i < products.size() && products[i] != 4) ++i;
  //dbg(i)
  return (i + 1 < products.size() && products.back() == -1);
}

int main()
{
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        cout << "Case #" << tc << ": ";

        int len;
        long long num_repeats;
        string s;
        cin >> len >> num_repeats;
        cin >> s;
        bool ok = false;
        vector<int> products = get_products(s);
        if (products.back() != 1) {
          if (products.back() == -1 && num_repeats % 2 == 1) {
            string t = "";
            for (int i = 1; i <= min(num_repeats, (long long)12); i += 2) {
              t += s;
              if (is_good(get_products(t))) {
                ok = true;
                break;
              }
            }
          } else if (num_repeats % 2 == 0 && products.back() != -1) {
            string t = s;
            for (int i = 2; i <= min(num_repeats, (long long)12); ++i) {
              t += s;
              if (num_repeats % 4 != 0 && is_good(get_products(t))) {
                ok = true;
                break;
              }
            }
          }
        }
        cout << (ok ? "YES" : "NO");

        cout << endl;
    }
    return 0;
}
