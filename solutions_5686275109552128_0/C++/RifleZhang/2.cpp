#include <iostream>
#include <string.h>
#include <stdio.h>
#include <iomanip>
#include <algorithm>
#include <math.h>
using namespace std;
int n, a[2000000];
int getans (int *a, int si) {
  int ma = 0, p;
  for (int i=1; i<=si; i++)
    if (a[i] > ma) {
      ma = a[i];
      p = i;
    }
  if (ma == 1) return 1;
 
  a[p] = ma / 2;
  a[si+1] = ma%2? (ma/2 + 1) : ma/2;
  /*
  for (int i=1; i<=si+1; i++)
    cout << a[i] << " ";
    cout << ma << " " << endl;*/
  return  min (ma, 1 + getans(a, si+1));
    
}
void solve (int tmp) {
  cin >> n;
  for (int i=1; i<=200; i++) a[i] = 0;
  for (int i=1; i<=n; i++) cin >> a[i];
  int ans = getans (a, n);
  
  cout << "Case #" << tmp << ": " << ans  << endl; 
}
int main () {
  int t, tmp = 0;
  cin >> t;
  while (t) {
    t--;
    tmp++;
    solve (tmp);
    // cout << "next ---------------------------------" << endl;
  }
}
