#include<bits/stdc++.h>
using namespace std;



int main() {
  int t;
  cin >> t;
  for(int i = 0; i < t; ++i) {
    int r, c, w;
    cin >> r >> c >> w;
    //int search = r * ((c + (w - 1)) / w);
    //int kill = w - 1;
    int ans;
    if(w == 1) {
      ans = r * c;
    } else {
      int search = r * ((c - (w - 1) + (w - 1)) / w);
      int kill = (w - 1) + (((c - (w - 1)) % w == 1) ? 0 : 1);
      ans = search + kill;
    }
    printf("Case #%d: %d\n", i + 1, ans);
  }
}
