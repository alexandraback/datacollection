#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <string>
using namespace std;

int main() {
  int T;
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  for(int cn = 1; cn <= T; ++cn) {
cerr << cn << " of " << T << '\n';
    int N;
	cin >> N;
	vector<string> s1(N), s2(N);

    for(int i = 0; i < N; ++i) {
	  cin >> s1[i] >> s2[i];
	}

    int ans = 0;
    for(unsigned int i = 1U; i < (1U << N); ++i) {
	  set<string> st1, st2, st3, st4;
	  for(unsigned int j = 1U, k = 0; k < N; ++k, j = j << 1) {
	    if(i & j) {
		  // fake
		  st3.insert(s1[k]);
		  st4.insert(s2[k]);
		} else {
		  // genuine
		  st1.insert(s1[k]);
		  st2.insert(s2[k]);
		}
	  }
	  bool ok = true;
	  for(const string &ss : st3) {
	    if(st1.find(ss) == st1.end()) {
		  ok = false;
		  break;
		}
	  }
	  if(ok) for(const string &ss : st4) {
	    if(st2.find(ss) == st2.end()) {
		  ok = false;
		  break;
		}
	  }
	  if(ok) {
	    ans = max(__builtin_popcount(i), ans);
	  }
	}

	cout << "Case #" << cn << ": " << ans << '\n';
  }
}

