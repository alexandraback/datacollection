#include<stdio.h>
#include<iostream>
#include<vector>
#include<bitset>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<sstream>
#include<cstring>
#include<cassert>

#define input freopen("input.txt","r",stdin);
#define output freopen("output.txt","w",stdout);

using namespace std;

const int MAXN = (int) 5e5 + 10;

int n;
long long m;

int main() {
  #ifndef ONLINE_JUDGE
        input;
        output;
    #endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T, tc = 1;;
  cin >> T;
  while (T--) {
    cin >> n >> m;
    long long mx = 1LL << (n - 2);
    int ok = true;
    vector<vector<int> > a(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        a[i].push_back(0);
      }
    }
    if (m > mx) {
      ok = false;
    } else {
      for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n - 1; j++) {
          //cout << "edge " << i + 1 << " " << j + 1 << endl;
          a[i][j] = 1;
        }
      }
      for (int i = n - 2; i >= 0; i--) {
        long long ways = 1;
        if (i >= 1) {
          ways = 1LL << (i - 1);
        }
        if (m >= ways) {
          m -= ways;
          //cout << "edge " << i + 1 << " " << n << endl;
          a[i][n - 1] = 1;
        }
      }
      assert(m == 0);
    }
    if (ok) {
      cout << "Case #" << tc++ << ": " << "POSSIBLE" << endl;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          cout << a[i][j];
        }
        cout << endl;
      }
    } else {
      cout << "Case #" << tc++ << ": " << "IMPOSSIBLE" << endl;
    }
  }
  return 0;
}	
