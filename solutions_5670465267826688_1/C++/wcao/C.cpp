#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
#include <map>

using namespace std;

const int MAXN = 10005;

struct quarter {
	int sg, val;
	inline quarter operator * (const quarter &o) const {
		if (val == 0 || o.val == 0) {
			return ((quarter){sg * o.sg, max(val, o.val)});
		}
		else if (val == o.val) {
			return ((quarter){-sg * o.sg, 0});
		}
		else if (val == 1) {
			if (o.val == 2) {
				return ((quarter){sg * o.sg, 3});
			}	else if (o.val == 3) {
				return ((quarter){-sg * o.sg, 2});
			}
		}	else if (val == 2) {
			if (o.val == 1) {
				return ((quarter){-sg * o.sg, 3});
			}	else if (o.val == 3) {
				return ((quarter){sg * o.sg, 1});
			}
		}	else if (val == 3) {
			if (o.val == 1) {
				return ((quarter){sg * o.sg, 2});
			}	else if (o.val == 2) {
				return ((quarter){-sg * o.sg, 1});
			}
		}
	}
	inline bool operator == (const quarter &o) const {
		return (sg == o.sg && val == o.val);
	}
};

int T, L;
long long X;
string mem;

quarter A[MAXN * 4];
quarter B[MAXN * 4];

map<char, quarter> mp;

inline bool calc() {
	A[0] = mp[mem[0]];
	for(int i = 1 ; i < 4 * L ; i++) {
		A[i] = A[i - 1] * mp[mem[i % L]];
	}
	B[4 * L - 1] = mp[mem[L - 1]];
	for(int i = 4 * L - 2 ; i >= 0 ; i--) {
		B[i] = mp[mem[i % L]] * B[i + 1];
	}

	quarter tot = A[L - 1];
	//cout << tot.sg << " " << tot.val << endl;
	int num = ((X % 4) + 4);
	for(int i = 1 ; i < num ; i++) {
		tot = tot * A[L - 1];
	}
	if (tot.sg != -1 || tot.val != 0) {
		//printf("prod\n");
		return false;
	}

	int ind = 0;
	while (ind < 4 * L && !(A[ind] == mp['i'])) {
		ind++;
	}
	if (ind == 4 * L) {
		//printf("first\n");
		return false;
	}

	int ind2 = 0;
	while (ind2 < 4 * L && !(B[4 * L - 1 - ind2] == mp['k'])) {
		ind2++;
	}
	if (ind2 == 4 * L) {
		//printf("last\n");
		return false;
	}
	return (((ind + ind2 + 2) / X) <= L);
}

int main() {
	mp['i'] = ((quarter){1, 1});
	mp['j'] = ((quarter){1, 2});
	mp['k'] = ((quarter){1, 3});
	cin >> T;
	for(int t = 1 ; t <= T ; t++) {
		cin >> L >> X;
		cin >> mem;
		printf("Case #%d: ", t);
		if (calc()) {
			printf("YES\n");
		}	else {
			printf("NO\n");
		}
	}	
	return 0;
}
