#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>

using namespace std;

int main () {
  freopen ("input.txt", "rt", stdin);
  freopen ("out.txt", "wt", stdout);

  int t ;
  cin >> t ;
  for (int tt = 0 ; tt < t ; tt++) {
    cout << "Case #" << tt+1 << ": ";
    int a,b,k;
    cin >> a >> b >> k;
    
    int result = 0;
    for (int i=0 ; i < a ; i++)
      for (int j=0 ; j < b ; j++)
        result += ((i & j) < k) ;
    
    cout << result << endl;
  }
  return 0;
}
