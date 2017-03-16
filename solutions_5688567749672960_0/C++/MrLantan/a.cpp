#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main () {
	int t;
	freopen ("input1.in", "r", stdin);
	freopen ("output1.out", "w", stdout);
	scanf ("%d", &t);
	//t = 100;
	for (int tt = 0; tt < t; tt++) {
//		ostringstream ss;
//		ss << tt + 1;
		string x;// = ss.str();
		cin >> x;
		long long ans = 0;
		while (x.length() != 0) {
			int len = x.length();
			int step = 1;
			ll cur1 = 0, cur2 = 0;	
			for (int i = 0; i < len / 2; i++) {
				cur2 += step * (x[i] - '0');
				cur1 += step * (x[len - i - 1] - '0');
				step *= 10;
			}
			if (len % 2 != 0)
				cur1 += step * (x[len/2] - '0');

			if (cur1 == 0) { 
				ans++;
				if (cur2 == 1) {
					x = "";
					for (int i = 0; i < len - 1; i++)
						x += '9';
				}
				else {
					int cur = len - 1;
					while  (x[cur] == '0') {
						x[cur] = '9';
						cur--;
					}
					x[cur] = char (int (x[cur]) - 1);
				}
				continue;
			}
						if (cur2 == 0) {
				ans += x[0] - '0';
				x = x.substr (0, 0);
				continue;
			}
			if (cur2 == 1) {
				 ans += cur1 + 1;
			} else {
				ans += cur1 + cur2 + 1;
			}
			for (int i = 0; i < len; i++)
				x[i] = '9';
			x = x.substr (0, len - 1);
		}	
		printf ("Case #%d: %lld\n", tt + 1, ans);
	}
}

