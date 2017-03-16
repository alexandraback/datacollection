#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;

int cal_(int *bff, int *ar2, int sz) {
  if(sz < 2) return 0;

  for(int i = 1; i < sz - 1; ++i) {
    const int bf = bff[ ar2[i] ];
	if(ar2[i-1] != bf && ar2[i+1] != bf) return 0;
  }

  int bf = bff[ar2[0]];
  if(ar2[1] != bf && ar2[sz-1] != bf) return 0;
  bf = bff[ar2[sz-1]];
  if(ar2[0] != bf && ar2[sz-2] != bf) return 0;
  return sz;
}

int main() {
  int T;
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  for(int cn = 1; cn <= T; ++cn) {
cerr << cn << " of " << T << '\n';

    int N;
	cin >> N;
    int bff[1005];
	for(int i = 0; i < N; ++i) {
	  cin >> bff[i];
	  --bff[i];
	}
	int ans = 0;

    int ar[15];
	for(int i = 0; i < N; ++i) ar[i] = i;

    for(unsigned int UI = (1U << N) - 1U; UI > 0; --UI) {
	    int ar2[15], sz = 0;
		for(int i = 0; i < N; ++i) {
		  if(UI & (1U << i)) ar2[sz++] = i;
		}
		do {
			ans = max(ans, cal_(bff, ar2, sz));
		} while( next_permutation(ar2, ar2+sz) );
	}

	cout << "Case #" << cn << ": " << ans;
	cout << "\n";
  }
}
