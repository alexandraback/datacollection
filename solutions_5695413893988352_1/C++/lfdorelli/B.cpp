#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll getv (string &a) {
	ll res = 0;
	for (int i = 0; i < a.size(); ++i) res = res*10 + (a[i]-'0');
	return res;
}

void fill (string &a, string &b, int pos, ll &dif, string &aa, string &bb) {
	// Faço A o menor possível e B o maior possível
	aa = a, bb = b;
	for (int i = pos; i < a.size(); ++i) {
		if (aa[i] == '?') aa[i] = '0';
		if (bb[i] == '?') bb[i] = '9';
	}
	dif = abs ( getv(aa) - getv(bb) );
	string a2 = a, b2 = b;
	for (int i = pos; i < a.size(); ++i) {
		if (a2[i] == '?') a2[i] = '9';
		if (b2[i] == '?') b2[i] = '0';
	}	
	ll d2 = abs ( getv(a2) - getv(b2) );
	if (d2 < dif) dif = d2, aa = a2, bb = b2;
}

int main (void) {
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		cout << "Case #" << i << ": ";
		string a, b;
		cin >> a >> b;
		int j = -1;
		long long int cdif = 2e18;
		string ma, mb;

		for (int i = 0; i < a.size(); ++i) {
			if (a[i] == '?' and b[i] == '?') {
				for (a[i] = '0'; a[i] <= '9'; ++a[i]) {
					for (b[i] = '0'; b[i] <= '9'; ++b[i]) {
						ll dif;	
						string v1, v2;
						fill (a, b, i+1, dif, v1, v2);
						if (dif < cdif) {
							cdif = dif;
							ma = v1; mb = v2;
						} else if (dif == cdif) {
							if (v1 < ma or (v1 == ma and v2 < mb)) {
								cdif = dif;
								ma = v1; mb = v2;
							}
						}
					}
				}
				a[i] = b[i] = '0';
			} else if (a[i] == '?' and b[i] != '?') {	
					for (a[i] = '0'; a[i] <= '9'; ++a[i]) {
						ll dif;	
						string v1, v2;
						fill (a, b, i+1, dif, v1, v2);
						if (dif < cdif) {
							cdif = dif;
							ma = v1; mb = v2;
						} else if (dif == cdif) {
							if (v1 < ma or (v1 == ma and v2 < mb)) {
								cdif = dif;
								ma = v1; mb = v2;
							}
						}
					}
					a[i] = b[i];
			} else if (a[i] != '?' and b[i] == '?') {
					for (b[i] = '0'; b[i] <= '9'; ++b[i]) {
						ll dif;	
						string v1, v2;
						fill (a, b, i+1, dif, v1, v2);
						if (dif < cdif) {
							cdif = dif;
							ma = v1; mb = v2;
						} else if (dif == cdif) {
							if (v1 < ma or (v1 == ma and v2 < mb)) {
								cdif = dif;
								ma = v1; mb = v2;
							}
						}
					}
					b[i] = a[i];
			} 
		}
		cout << ma << " " << mb << endl;
	}
}


