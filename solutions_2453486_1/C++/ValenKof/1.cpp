#include <cstdio>
#include <cctype>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <string>

#include <vector>
#include <map>
#include <set> 

#include <algorithm>
#include <cmath>

#include <ctime>
#include <cstdlib>

using namespace std;

#define PATH "C:\\Users\\Malkav\\Desktop\\"
#define debug(x) cerr << fixed << setprecision(3) << "DEBUG: " << #x << " = " << x << endl
#define forn (i, n) for (int i = 0; i < n; ++i)
#define sz(x) ((int)(x.size()))
#define mp make_pair
#define pb push_back

vector<string> a(4);

bool check(int i, int j, int di, int dj, char c) {
  for (int k = 0; k < 4; ++k) {
    if (a[i][j] != c && a[i][j] != 'T') {
      return false;  
    }
    i += di;
    j += dj;
  }
  return true;
}

bool full_check(char c) {
  bool result = check(0, 0, 1, 1, c) || check(3, 0, -1, 1, c);
  for (int i = 0; i < 4; ++i) {
    result = result || check(i, 0, 0, 1, c);
    result = result || check(0, i, 1, 0, c);
  }
  return result;
}


void solve() {
  for (int i = 0; i < 4; ++i) {
    cin >> a[i];
  }
  
  if (full_check('X')) {
    cout << "X won";
    return;
  }  
  
  if (full_check('O')) {
    cout << "O won";
    return;
  }
  
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      if (a[i][j] == '.') {
        cout << "Game has not completed";
        return;
      }
    }
  }
  
  cout << "Draw";
  
}

int main() {
  freopen(PATH"in.txt", "r", stdin);
  freopen(PATH"out.txt", "w", stdout);
  //ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    cout << "Case  #" << i + 1 << ": ";
    solve();
    cout << endl;
  }
  return 0;   
}