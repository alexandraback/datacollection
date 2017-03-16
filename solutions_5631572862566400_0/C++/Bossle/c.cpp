#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long int lli;

// Copying from wikipedia, a bit too tired today
// returns (first_on_cycle, length_of_cycle, length_before_cycle)
pair<int,pair<int,int> > getCycle(int n, const vector<int>& bff) {
  int t = bff[n];
  int h = bff[t];
  while (t!=h) {
    t = bff[t];
    h = bff[bff[h]];
  }
  int mu = 0;
  t = n;
  while (t != h) {
    t = bff[t];
    h = bff[h];
    mu++;
  }
  int first_on_cycle = t;
  int lam=1;
  h = bff[t];
  while (t != h) {
    h = bff[h];
    lam++;
  }
  return pair<int,pair<int,int> >(first_on_cycle, pair<int,int>(lam, mu));
}

int main() {
  int t;
  cin >> t;
  for (int ta=1; ta<=t; ++ta) {
    cout << "Case #" << ta << ": ";
    int n;
    cin >> n;
    vector<int> bff(n);
    for (int i=0; i<n; ++i) {
      cin >> bff[i];
      bff[i]--;
    }
    
    vector<pair<int,pair<int,int> > > cycles(n);
    for (int i=0; i<n; ++i)
      cycles[i] = getCycle(i, bff);
    
    int best=0;
    // case all bff's to the right
    for (int i=0; i<n; ++i)
      best = max(best, cycles[i].second.first);
    vector<int> bestmu(n,0);
    for (int i=0; i<n; ++i) {
      if (cycles[i].second.first == 2) {
        int b = cycles[i].first;
        bestmu[b] = max(bestmu[b], cycles[i].second.second);
      }
    }
    int ans=0;
    for (int i=0; i<n; ++i) {
      if (cycles[i].second == pair<int,int>(2, 0)) {
        ans += 1+bestmu[i];
      }
    }
    cout << max(ans, best) << endl;
  }
}