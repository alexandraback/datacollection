#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll best, a, b;
string A, B;
int target;
vector<ll> val(20);
// ?4? ?85 046 085
void rek(int pos, ll aa, ll bb) {
	if(pos == target) {
		//cerr << aa << " " << bb << endl;
		if(best == -1) {
			best = abs(aa-bb);
			a = aa;
			b = bb;
		} else {
			if (best > abs(aa-bb)) {
				best = abs(aa-bb);
				a = aa;
				b = bb;
			}
			if (best == abs(aa-bb)) {
				if(aa < a || (aa == a && bb < b)) {
					a = aa;
					b = bb;
				} 
			}
		}
		return;
	}

	ll akt = val[pos];
	if(A[pos] == '?' && B[pos] == '?') {
		if(aa == bb) {
			rek(pos + 1, aa, bb);
			rek(pos + 1, aa + akt, bb);
			rek(pos + 1, aa, bb + akt);
		} else if(aa > bb) {
			rek(pos + 1, aa, bb + akt * 9);
		} else {
			rek(pos + 1, aa + akt * 9, bb);
		}
	} else if (A[pos] == '?') {
		if(aa == bb) {
			bb += akt * (B[pos] - '0');

								rek(pos + 1, aa + akt * (B[pos] - '0'), bb);
			if(B[pos] != '0') 	rek(pos + 1, aa + akt * (B[pos] - '0' - 1), bb);
			if(B[pos] != '9') 	rek(pos + 1, aa + akt * (B[pos] - '0' + 1), bb);
		} else if(aa > bb) {
			bb += akt * (B[pos] - '0');
			rek(pos + 1, aa, bb);
		} else {
			bb += akt * (B[pos] - '0');
			rek(pos + 1, aa + akt * 9, bb);
		}
	} else if (B[pos] == '?') {
		if(aa == bb) {
			aa += akt * (A[pos] - '0');

								rek(pos + 1, aa, bb + akt * (A[pos] - '0'));
			if(A[pos] != '0') 	rek(pos + 1, aa, bb + akt * (A[pos] - '0' - 1));
			if(A[pos] != '9') 	rek(pos + 1, aa, bb + akt * (A[pos] - '0' + 1));
		} else if(aa > bb) {
			aa += akt * (A[pos] - '0');
			rek(pos + 1, aa, bb + akt * 9);
		} else {
			aa += akt * (A[pos] - '0');
			rek(pos + 1, aa, bb);
		}
	} else {
		aa += akt * (A[pos] - '0');
		bb += akt * (B[pos] - '0');
		rek(pos + 1, aa, bb);
	}
}

void print(ll cislo, int n) {
	cout << setw(n) << setfill('0') << cislo;
}

void solve() {
	cin >> A >> B;
	val[A.size() - 1] = 1;
	for(int i=A.size() - 2; i >= 0; i--) val[i] = val[i+1] * 10ll;

	target = A.size();
	best = -1;

	rek(0, 0, 0);
	//cout << A << " " << B << " ";
	print(a, A.size()); 
	cout << " ";
	print(b, A.size());
}

int main(void) {
	int T;
	cin >> T;
	for(int t=1; t<=T; t++) {
		cout << "Case #" << t << ": ";
		solve();
		cout << endl;
	}
}