#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

//*******************
int R, C, W;
//*******************

void read() {
   cin >> R >> C >> W;
}

int solve() {
   if(W == 1)
      return R * C;
   if(W > C / 2)
      return R - 1 + min(C, W + 1);
   return R * (C / W) + (W - 1) + (C % W == 0 ? 0 : 1);
}

void clean() {
}

int main() {
   ios::sync_with_stdio(false);
   int z;
   cin >> z;
   for(int i = 1; i <= z; ++i) {
      read();
      cout << "Case #" << i << ": " << solve() << endl;
      clean();
   }
   return 0;
}