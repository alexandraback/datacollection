#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int T;
  cin >> T;
  for (int testcase = 1; testcase <= T; ++testcase) {
    int N, S, P;
    cin >> N >> S >> P;
    vector<int> t(N);
    for (int i = 0; i < N; ++i)
      cin >> t[i];

    int ans = 0;
    vector<int> used(N, 0);
    for (int i = 0; i < N; ++i) {
      int tri = t[i]/3, sur = t[i]%3;
      if (tri >= P || sur > 0 && tri+1 >= P) {
	++ans;
      } else if (S > 0 && sur != 1) {
	if (sur == 0) {
	  if (tri-1 >= 0 && tri+1 >= P) {
	    ++ans;
	    --S;
	    used[i] = 1;
	  }
	} else {
	  if (tri+2 >= P) {
	    ++ans;
	    --S;
	    used[i] = 1;
	  }
	}
      }
    }

    for (int i = 0; i < N && S > 0; ++i) {
      if (used[i] || t[i]%3 == 1)
	continue;
      --S;
    }

    cout << "Case #" << testcase << ": " << ans << endl;
  }
  return 0;
}
