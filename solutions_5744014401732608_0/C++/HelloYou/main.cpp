/**
 * Problem: A
 */
#include <algorithm>
#include <assert.h>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <math.h>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>
#include <stdexcept>
#include <typeinfo>

#define SZ(x) (int)(x.size())
#define F0(i,n) for(int i=0;i<n;i++)
#define F1(i,n) for(int i=1;i<=n;i++)

using namespace std;

template<typename T>
string to_string(const T &n) {
  ostringstream s;
  s << n;
  return s.str();
}

typedef vector<string> vs;
typedef long long ll;
typedef long long int lli;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;

int number [10];

int main(int argc, const char **argv) {
  int cases;
  cin >> cases;
  int N, tmp;
  int matrix [10][10];
  int B, M;

  auto print = [&]() {
    F0(i, B) {
      F0(j, B) {
        if (matrix[i][j]) {
          cout << "1";
        } else {
          cout << "0";
        }
      }
      cout << endl;
    }
  };

  auto calc = [&]() {
    int total = 0;
    memset(number, 0, sizeof(number));
    for (int i = B-1; i >=0; --i) {
      F1(j, B) {
        if (matrix[i][j]) {
          number[i] += number[j];
        }
      }
      if (matrix[i][B-1]) {
        number[i]++;
      }
    }
    return number[0];
  };

  F1(caseI, cases) {
    cin >> B >> M;
    memset(matrix, 0, sizeof(matrix));
    int total = 1;
    F0(i, B-2) {
      total = total << 1;
    }

    if (M > total) {
      cout << "Case #" << caseI << ": " << "IMPOSSIBLE" << endl;
    } else {
      // F0(i, B) {
      //   for (int j = i + 1; j < B; j++) {
      //     matrix[i][j] = 1;
      //   }
      // }

      int m = 0;
      int r1, r2;
      while (m != M) {
        while (1) {
          r1 = rand() % B;
          r2 = r1 + rand() % (B-r1) + 1;
          if (m < M) {
            if (matrix[r1][r2] == 0) {
              matrix[r1][r2] = 1;
              // cout << "r1:" << r1 << endl;
              // cout << "r2:" << r2 << endl;
              break;
            }
          } else {
            if (matrix[r1][r2] == 1) {
              matrix[r1][r2] = 0;
              break;
            }
          }
        }
        m = calc();
        // cout << "m:" << m << endl;
        // cout << "M:" << M << endl;
        // print();
      }

      // cout << "B:" << B << endl;
      cout << "Case #" << caseI << ": " << "POSSIBLE" << endl;
      print();
      // cout << "random: " << rand() % (B-1) + 1 << endl;
      // cout << "calc():" << calc() << endl;
      // cout << "total:" << total << endl;
    }
  }

  return 0;
}
