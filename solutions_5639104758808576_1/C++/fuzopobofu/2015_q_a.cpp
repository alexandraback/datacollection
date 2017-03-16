#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <iterator>
#include <utility>
#include <iomanip>
#include <cmath>
#include <climits>
#include <stdio.h>
#include <string.h>

using namespace std;

void solve() {
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    int n;
    cin >> n;
    std::vector<int> vv(n+1);    for (int i = 0; i < n+1; i++) { char c; cin >> c; vv[i] = c-'0'; }
    
    int clap_num = 0;
    int result = 0;
    for (int i = 0; i < n+1; i++) {
      int extra = max(i - clap_num, 0);
      result += extra;
      clap_num += vv[i] + extra;
    }

    std::cout << "Case #" << (t+1) << ": " << result << std::endl;
  }
}

int main(int argc, char *argv[])
{
  solve();
  return 0;
}
