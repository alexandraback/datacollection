#include <iostream>
#include <algorithm>
using namespace std;

typedef long long lli;
const int MAXN = 105;
lli A, N;
lli mote[MAXN];

int main() {
  int Tc;
  cin >> Tc;
  for(int tc = 0; tc < Tc; ++tc) {
    cin >> A >> N;
    for(int i = 0; i < N; ++i) cin >> mote[i];
    sort(mote, mote+N);
    lli ans = N;
    lli num_op = 0;
    if(A != 1) {
      for(int i = 0; i < N; ++i) {
	while(A <= mote[i]) {
	  ++num_op;
	  A += A-1;
	}
	A += mote[i];
	ans = min(ans, num_op + N-i-1);
      }
    }
    cout << "Case #" << tc+1 << ": " << ans << endl;
  }
  return 0;
}
