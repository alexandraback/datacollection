#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second

typedef unsigned long long ull;
typedef unsigned int ui;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double E = 2.71828182846;

ll resa, resb;
string s1, s2;

ll ab (ll x) {
	if (x >= 0) return x;
	return -1 * x;
}

void go (int i, ll a, ll b) {

	if (i == (int)s1.size()) {
		if (resa < 0) {
			resa = a;
			resb = b;
		} else {
			if (ab(a-b) < ab(resa - resb)) {
				resa = a;	resb = b;
			} else if (ab(a-b) == ab(resa - resb)) {
				if (a < resa) {
					resa = a;
					resb = b;
				} else if (b < resb) {
					resa = a;
					resb = b;
				}
			}
		}
		return;
	}

	if (s1[i] == '?' and s2[i] == '?') {
		if (a == b) {
			go (i + 1, a*10, b*10);
			go (i + 1, a*10 + 1, b*10);
			go (i + 1, a*10, b*10 + 1);
		} else if (a < b){
			go (i + 1, a*10 + 9, b*10);
		} else {
			go (i + 1, a*10, b*10 + 9);
		}
	} else if (s1[i] == '?') {
		if (a == b) {
			go (i + 1, a*10 + s2[i] - '0', b*10 + s2[i] - '0');
			if (s2[i] != '0') go (i + 1, a*10 + s2[i] - '0' - 1, b*10 + s2[i] - '0');
			if (s2[i] != '9') go (i + 1, a*10 + s2[i] - '0' + 1, b*10 + s2[i] - '0');
		} else if (a < b) {
			go (i + 1, a*10 + 9, b*10 + s2[i]-'0');
		} else {
			go (i + 1, a*10, b*10 + s2[i]-'0');
		}
	} else if (s2[i] == '?') {
		if (a == b) {
			go (i + 1, a*10 + s1[i] - '0', b*10 + s1[i] - '0');
			if (s1[i] != '0') go (i + 1, a*10 + s1[i] - '0', b*10 + s1[i] - '0' - 1);
			if (s1[i] != '9') go (i + 1, a*10 + s1[i] - '0', b*10 + s1[i] - '0' + 1);
		} else if (b < a) {
			go (i + 1, a*10 + s1[i]-'0', b*10 + 9);
		} else {
			go (i + 1, a*10 + s1[i]-'0', b*10);
		}
	} else {
		go(i + 1, a*10 + s1[i]-'0', b*10 + s2[i]-'0');
	}

}

void imp (ll x) {
	int display[20];	memset(display, 0, sizeof display);

	int n = s1.size() - 1;

	for (int i = n; i >= 0; i--) {
		display[i] = x%10;
		x /= 10;
	}

	for (int i = 0; i <= n; i++) {
		cout << display[i];
	}

}

int main (void) {
	ios_base::sync_with_stdio(false);

	int t;	cin >> t;
	for (int T = 1; T <= t; T++) {
		cout << "Case #" << T  << ": ";
		cin >> s1 >> s2;
		resa = resb = -1;
		go(0,0,0);
		imp(resa); cout << " "; imp(resb);
		cout << endl;
	}

	return 0;
}
