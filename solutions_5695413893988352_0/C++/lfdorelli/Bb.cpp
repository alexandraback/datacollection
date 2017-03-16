#include <bits/stdc++.h>

using namespace std;

int dp[20][20];


int main (void) {
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		cout << "Case #" << i << ": ";
		string a, b;
		cin >> a >> b;
		int aa = 0;
		int bb = 0;
		for (int i = 0; i < a.size(); ++i) {
			aa = aa*10 + (a[i] - '0');
			bb = bb*10 + (b[i] - '0');
		}
		char sa[9], sb[9];
		int ma, mb;
		int bdif = 1000000;
		for (int A = 0; A <= 999; ++A) {
			for (int B = 0; B <= 999; ++B) {
				int aa = A, bb = B;
				for (int i = a.size()-1; i >= 0; --i) {
					sa[i] = ('0' + aa%10);
					sb[i] = ('0' + bb%10);
					aa /= 10;	
					bb /= 10;
				}
				if (aa != 0 or bb != 0) continue;
				bool good = true;
				for (int i = 0; i < a.size(); ++i) {
					if (a[i] != '?' and a[i] != sa[i]) good = false;
					if (b[i] != '?' and b[i] != sb[i]) good = false;
				}
				if (good and abs (A - B) <= bdif) {
					if ( abs (A - B) == bdif) {
						if (A < ma or (A == ma and B < mb)) {
 							bdif = abs (A - B), ma = A, mb = B;
						}
					} else {
 						bdif = abs (A - B), ma = A, mb = B;
					}
				}	
			}
		}
		aa = ma, bb = mb;
		for (int i = a.size()-1; i >= 0; --i) {
			sa[i] = ('0' + aa%10);
			sb[i] = ('0' + bb%10);
			aa /= 10;	
			bb /= 10;
		}
		sa[a.size()] = '\0';		
		sb[b.size()] = '\0';
		cout << sa << " " << sb << endl;
	}
}


