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

const int N = 20;

vector<int> start;
vector<int> keys[N];
int need[N];

vector<int> from[1 << N];

void solve() {
  int k, n;
  cin >> k >> n;
  
  start.resize(k);
  for (int i = 0; i < k; ++i) {
    cin >> start[i];
  }
  for (int i = 0, sz; i < n; ++i) {
    cin >> need[i] >> sz;
    keys[i].resize(sz);
    for (int j = 0; j < sz; ++j) {
      cin >> keys[i][j];
    }    
  }

  int m = (1 << n);
    
  fill(from, from + m, vector<int>());
  from[0] = vector<int>(1, 0);
 
  for (int i = 0; i < m; ++i) {
    if (sz(from[i]) == 0) {
      continue;
    }
    
    map<int, int> cur_count;
    for (int j = 0; j < k; ++j) {
      ++cur_count[start[j]];
    }
    for (int j = 0; j < n; ++j) {
      if (i & (1 << j)) {
        --cur_count[need[j]];
        for (int l = 0; l < keys[j].size(); ++l) {
          ++cur_count[keys[j][l]];
        }
      }
    }
    
    
    
    for (int j = 0; j < n; ++j) {
      from[i].push_back(j + 1);
      if (!(i & (1 << j)) && 
          cur_count[need[j]] > 0 && 
          (sz(from[i | (1 << j)]) == 0 ||
          from[i | (1 << j)] > from[i])) {
        from[i | (1 << j)] = from[i];
      }
      from[i].pop_back();
    }
    
  }
 

  if (sz(from[m - 1]) == 0) {
    cout << "IMPOSSIBLE";
    return;
  }  
  
  vector<int> ans = from[m - 1];
  for (int i = 0; i < n; ++i) {
    cout << ans[i + 1] << ' ';
  }
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