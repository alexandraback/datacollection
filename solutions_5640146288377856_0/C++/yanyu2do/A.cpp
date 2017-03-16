#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <cstring>
#include <cstddef>
#define _USE_MATH_DEFINES // for C++
#include <cmath>

using namespace std;

int main(){
  FILE *fin = freopen("A.in", "r", stdin);
  assert(fin != NULL);
  FILE *fout = freopen("A.ans", "w", stdout);

  ios :: sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;

  for(int t = 1; t <= T; t++){
    int R, C, W;
    cin >> R >> C >> W;
    int ans = (C / W - 1) + W + (C % W != 0);
    cout << "Case #" << t << ": " << ans << endl;
  }
}

