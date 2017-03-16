#define DEBUG 0
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int last[1000];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cerr << fixed << setprecision(0);

	if (!DEBUG) {
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	}

	int _c, _start = static_cast<int>(clock());
	cin >> _c;

	for(int _cc = 1; _cc <= _c; ++_cc) {
		int _t = static_cast<int>(clock());
		cout << "Case #" << _cc << ": ";

		string s;
		cin >> s;

		last[0] = 0;
		for (int i = 1; i < s.size(); ++i) {
			last[i] = last[i - 1];
			if (s[i] >= s[last[i]]) {
				last[i] = i;
			}
			//cout << i << "  :  " << last[i] << endl;
		}

		string t;
		t = s[0];
		for (int i = 1; i < s.size(); ++i) {
			int tmp = last[i - 1];
			while (i < s.size() && last[i] == tmp) {
				t += s[i];
				//cout << t << endl;
				++i;
			}
			if (i < s.size()) { t = s[i] + t; //cout << "extra " << t << endl; 
			}
		}

		cout << t << '\n';

		cerr << "[Case #" << _cc << " complete, " << static_cast<int>(clock() - _t) << " ms, " << 100. * _cc / _c << "%]" << endl;
	}

	cerr << "Total time: " << static_cast<int>(clock() - _start) << " ms" << endl;

	return 0;
}

