#include <iostream>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  int tests;
  cin >> tests;
  for(int t=1; t<=tests; t++) {
    int N, S, p;
    cin >> N >> S >> p;
    int min1 = p + 2*(max(0,p-1));
    int min2 = p + 2*(max(0,p-2));
    int ile1 = 0, ile2 = 0;
    while(N--) {
      int x;
      cin >> x;
      if(x >= min1)
        ile1++;
      else if(x>=min2)
        ile2++;
    }
    cout << "Case #" << t << ": " << ile1 + min(ile2, S) << '\n';
  }
  return 0;
}