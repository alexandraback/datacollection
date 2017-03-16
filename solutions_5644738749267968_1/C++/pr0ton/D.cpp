#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

#define ld long double

int deceitfulWarOptimal(const vector<ld> a, const vector<ld> b, int n) {
    vector<bool> used( n );
    for (int i=0; i < n; i++) used[i] = 0;
    int res = 0;
    for (int i=0; i < n; i++) {
      for (int j=0; j < n; j++)
        if (!used[j] && a[j] > b[i]) {
          used[j] = 1;
          res ++;
          break;
        } 
    }
    return res;
}

int warOptimal(const vector<ld> a, const vector<ld> b, int n) {
  vector<bool> used( n );
    for (int i=0; i < n; i++) used[i] = 0;
    int res = n;
    for (int i=0; i < n; i++) {
      for (int j=0; j < n; j++)
        if (!used[j] && b[j] > a[i]) {
          used[j] = 1;
          res --;
          break;
        }
    }
    return res;
}

int main() {
  int T; cin>>T;
  for (int t=1; t <= T; t++) {
    printf("Case #%d: ", t);
    int n; cin>>n;
    vector<ld> a( n ), b ( n );
    for (int i=0; i < n; i++) {
      cin>>a[i];
    }
    for (int i=0; i < n; i++) {
      cin>>b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    printf("%d %d\n", deceitfulWarOptimal(a, b, n), warOptimal(a, b, n));
    
  }
}
