#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <iterator>
#include <utility>
#include <iomanip>
#include <cmath>
#include <climits>
#include <stdio.h>
#include <string.h>

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef pair<int, int> pii;

void solve() {
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    int A, B, K;
    cin >> A >> B >> K;
    
    int n = 0;
    for (int i = 0; i < A; i++) {
      for (int j = 0; j < B; j++) {
	if ((i&j) < K) n++;
      }
    }

    std::cout << "Case #" << (t+1) << ": " << n << std::endl;
  }
}

int main(int argc, char *argv[])
{
  solve();
  return 0;
}
