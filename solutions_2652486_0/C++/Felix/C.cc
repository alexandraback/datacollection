#include <algorithm>
#include <iomanip>
#include <iostream>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

#define FR first
#define SC second

#define debug(x) cerr << #x << " = " << x << endl

using namespace std;

typedef long long ll;

template <class Ta, class Tb> inline Tb cast(Ta a) {
  stringstream ss;
  ss << a;
  Tb b;
  ss >> b;
  return b;
}

const ll LINF = 1000000000000000000LL;
const int INF = 1000000000;

int main() {
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T; // 1
  for (int ca = 1; T--; ++ca) {
    int r, n, m, k;
    cin >> r >> n >> m >> k; // 100, 3, 5, 7 in first small
    
    // first small
    vector<vector<int> > numbers;
    vector<map<int, int> > prod_cnt;
    for (int a0 = 2; a0 <= m; ++a0) {
      for (int a1 = 2; a1 <= m; ++a1) {
        for (int a2 = 2; a2 <= m; ++a2) {
          vector<int> num;
          num.push_back(a0);
          num.push_back(a1);
          num.push_back(a2);
          map<int, int> cnt;
          for (int bm = 0; bm < (1<<int(num.size())); ++bm) {
            int prod = 1;
            for (int i = 0; i < int(num.size()); ++i) {
              if (((bm>>i)&1) == 1) {
                prod *= num[i];
              }
            }
            ++cnt[prod];
          }
          numbers.push_back(num);
          prod_cnt.push_back(cnt);
        }
      }
    }
    cout << "Case #" << ca << ":" << endl;
    for (int s = 0; s < r; ++s) {
      vector<int> votes(numbers.size(), 0);
      for (int i = 0; i < k; ++i) {
        int p;
        cin >> p;
        for (int j = 0; j < int(numbers.size()); ++j) if (votes[j] >= 0) {
          if (prod_cnt[j].count(p) == 1) {
            votes[j] += prod_cnt[j][p];
          }
          else {
            votes[j] = -1;
          }
        }
      }
      int best = -1;
      for (int i = 0; i < int(numbers.size()); ++i) {
        if (best == -1 || votes[i] > votes[best]) {
          best = i;
        }
      }
      for (int i = 0; i < int(numbers[best].size()); ++i) {
        cout << numbers[best][i];
      }
      cout << endl;
    }
  }
}
