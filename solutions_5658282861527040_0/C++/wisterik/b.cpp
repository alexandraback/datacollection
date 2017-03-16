#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>

#define rep(i, n) for(int i = 0; i < n; i++)

using namespace std;

typedef long long ll;

template<class T> ostream& operator<<(ostream& os, vector<T> v) {
  for(T x : v) os << x << ", ";
  return os;
}

int main() {

  int T;
  cin >> T;

  rep(t, T) {

    cout << "Case #" << (t+1) << ": ";
    int A, B, K;
    cin >> A >> B >> K;

    int ans = 0;
    rep(i, A) {
      rep(j, B) {
	if((i & j) < K) {
	  ans++;
	}
      }
    }

    cout << ans << endl;

  }

  return 0;
}
