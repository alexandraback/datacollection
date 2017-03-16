#include <bits/stdc++.h>

#define debug(x) cout << #x << " = " << x << endl
#define fori(i, ini, lim) for(int i = int(ini); i < int(lim); i++)
#define ford(i, ini, lim) for(int i = int(ini); i >= int(lim); i--)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

int main() {
	ios_base::sync_with_stdio(false);

	int kase = 1;
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;

		string ss;
		ss += s[0];
		fori(i, 1, s.size()) {
			if(s[i] >= ss[0]) {
				ss = s[i] + ss;
			}
			else {
				ss = ss + s[i];
			}
		}
		
		cout << "Case #" << kase++ << ": ";
		cout << ss << '\n';
	}

	return 0;
}
