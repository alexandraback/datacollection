#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <tuple>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

void reverse(vector<bool> &x, int n) {
  vector<bool> t(n);
  for (int i = 0; i < n; ++i)
    t[i] = !x[n - i - 1];
  for (int i = 0; i < n; ++i)
    x[i] = t[i];
}

int main() {
  int T;
  cin >> T;

  string empty;
  getline(cin, empty);

  for (int testCase=0; testCase < T; ++testCase)
  {
    int revs = 0; 
    string str;
    getline(cin, str);
    int n = str.size();
    vector<bool> x(n);

    for (int i = 0; i < n; ++i)
      x[i] = str[i] == '+' ? true : false;

    while(n != 0) {
      if (x[n-1]) {
        n--;
      } else {
        if (x[0]) {
          int k = n - 1;
          while (x[k-1] != true) 
            k--;
          reverse(x, k);
          reverse(x, n);
          revs += 2;
        } else {
          reverse(x, n);
          revs++;
        }
      }
    }

    cout << "Case #" << testCase + 1 << ": ";

    cout << revs << endl;
  }

  return 0;
}