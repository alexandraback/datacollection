#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <numeric>
#include <bitset>
#include <stack>
using namespace std;

const int INF = 1 << 30;

int main()
{
  int T;
  cin >> T;
  for (int Testcase = 1; Testcase <= T; ++Testcase) {
    int N;
    cin >> N;
    vector<int> n(N);
    for (int i = 0; i < N; ++i)
      cin >> n[i];

    vector<int> sum(1 << N, 0);
    for (int S = 0; S < (1 << N); ++S) {
      for (int j = 0; j < N; ++j) {
	if (S & (1 << j))
	  sum[S] += n[j];
      }
    }

    bool found = false;
    int S1 = -1, S2 = -1;
    for (int S = 0; S < (1 << N); ++S) {
      for (int T = (~S) & ((1 << N)-1); T > 0; T = (T-1)&(~S)) {
	if (sum[S] == sum[T]) {
	  S1 = S;
	  S2 = T;
	  found = true;
	  break;
	}
      }
      if (found)
	break;
    }

    cout << "Case #" << Testcase << ": ";
    if (!found) {
      cout << "Impossible" << endl;
    } else {
      cout << endl;
      vector<int> ans;
      for (int i = 0; i < N; ++i) {
	if (S1 & (1 << i))
	  ans.push_back(n[i]);
      }
      for (int i = 0; i < ans.size()-1; ++i)
	cout << ans[i] << " ";
      cout << ans.back() << endl;

      ans.clear();
      for (int i = 0; i < N; ++i) {
	if (S2 & (1 << i))
	  ans.push_back(n[i]);
      }
      for (int i = 0; i < ans.size()-1; ++i)
	cout << ans[i] << " ";
      cout << ans.back() << endl;

    }
   
  }
  return 0;
}
