#include <iostream>
#include <cstring>
#include <string>

using namespace std;

typedef long long ll;

inline bool getBit(int n, int b) {
	return (ll(n) & (1ll << b)) != 0;
}

int A, B, K;

ll table[33][2][2][2];

ll f(int bitNo, bool safeA, bool safeB, bool safeK) {
	if (bitNo == -1) {
		return 1;
	}

	if (table[bitNo][safeA][safeB][safeK] != -1)
		return table[bitNo][safeA][safeB][safeK];

	bool Abit = getBit(A, bitNo);
	bool Bbit = getBit(B, bitNo);
	bool Kbit = getBit(K, bitNo);

	ll ans = 0;
	// Combinazione 0 0, va sempre bene
	ans += f(bitNo - 1, safeA || Abit, safeB || Bbit, safeK || Kbit);

	// Combinazione 0 1
	if (Bbit == 0 && !safeB) {} // non posso
	else {
		ans += f(bitNo - 1, safeA || Abit, safeB, safeK || Kbit);
	}

	// Combinazione 1 0
	if (Abit == 0 && !safeA) {} // non posso
	else {
		ans += f(bitNo - 1, safeA, safeB || Bbit, safeK || Kbit);
	}

	// Combinazione 1 1
	if ((Abit == 0 && !safeA) || (Bbit == 0 && !safeB) || (Kbit == 0 && !safeK)) {} // non posso
	else {
		ans += f(bitNo - 1, safeA, safeB, safeK);
	}

	return table[bitNo][safeA][safeB][safeK] = ans;
}

void testcase(int testnum) {
	memset(table, -1, sizeof table);
	cin >> A >> B >> K;
	--A, --B, --K;

	cout << "Case #" << testnum << ": " << f(31, false, false, false) << endl;
}

int main() {
	int T; cin >> T;

	for (int t=1; t<=T; t++) testcase(t);
	
	return 0;
}