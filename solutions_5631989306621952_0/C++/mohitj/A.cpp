#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
  int T;
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  for(int cn = 1; cn <= T; ++cn) {
cerr << cn << " of " << T << '\n';
	string s;
	cin >> s;

	string ans;
	char first = s[0];
	const int len = (int)s.size();
	ans += s[0];
	for(int ii = 1; ii < len; ++ii) {
	  if(first <= s[ii]) {
	    string ss;
		ss += s[ii];
		ss += ans;
		ss.swap(ans);
		first = s[ii];
	  } else ans += s[ii];
	}


	cout << "Case #" << cn << ": ";
	cout << ans << "\n";
  }
}
