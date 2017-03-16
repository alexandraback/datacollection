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

const int N = 100;

int h[N][N];
int r_max[N];
int c_max[N];
int n, m;

void solve() {
  cin >> n >> m;
  
  for (int i = 0; i < n; ++i) {
    r_max[i] = 0;
  }
  
  for (int i = 0; i < m; ++i) {
    c_max[i] = 0;
  }
  
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> h[i][j];
      r_max[i] = max(r_max[i], h[i][j]);
      c_max[j] = max(c_max[j], h[i][j]);
    }
  }
  
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (r_max[i] > h[i][j] && c_max[j] > h[i][j]) {
        cout << "NO";
        return;
      }
    }
  }
  
  
  cout << "YES";
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