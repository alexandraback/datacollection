#include <bits/stdc++.h>

using namespace std;

namespace Solve {

	enum OPERAND {
		P1 = 0L,
		PI,
		PJ,
		PK,
		N1,
		NI,
		NJ,
		NK
	};

	const static OPERAND MUL_TABLE[8][8] = {
		{ P1, PI, PJ, PK, N1, NI, NJ, NK }, 
		{ PI, N1, PK, NJ, NI, P1, NK, PJ }, 
		{ PJ, NK, N1, PI, NJ, PK, P1, NI }, 
		{ PK, PJ, NI, N1, NK, NJ, PI, P1 }, 
		{ N1, NI, NJ, NK, P1, PI, PJ, PK }, 
		{ NI, P1, NK, PJ, PI, N1, PK, NJ }, 
		{ NJ, PK, P1, NI, PJ, NK, N1, PI }, 
		{ NK, NJ, PI, P1, PK, PJ, NI, N1 }, 
	};
	const static OPERAND LDIV_TABLE[8][8] = {
		{ P1, NI, NJ, NK, N1, PI, PJ, PK }, 
		{ PI, P1, NK, PJ, NI, N1, PK, NJ }, 
		{ PJ, PK, P1, NI, NJ, NK, N1, PI }, 
		{ PK, NJ, PI, P1, NK, PJ, NI, N1 }, 
		{ N1, PI, PJ, PK, P1, NI, NJ, NK }, 
		{ NI, N1, PK, NJ, PI, P1, NK, PJ }, 
		{ NJ, NK, N1, PI, PJ, PK, P1, NI }, 
		{ NK, PJ, NI, N1, PK, NJ, PI, P1 }, 
	};
	const static OPERAND RDIV_TABLE[8][8] = {
		{ P1, NI, NJ, NK, N1, PI, PJ, PK }, 
		{ PI, P1, PK, NJ, NI, N1, NK, PJ }, 
		{ PJ, NK, P1, PI, NJ, PK, N1, NI }, 
		{ PK, PJ, NI, P1, NK, NJ, PI, N1 }, 
		{ N1, PI, PJ, PK, P1, NI, NJ, NK }, 
		{ NI, N1, NK, PJ, PI, P1, PK, NJ }, 
		{ NJ, PK, N1, NI, PJ, NK, P1, PI }, 
		{ NK, NJ, PI, N1, PK, PJ, NI, P1 }, 
	};

	inline OPERAND operator*(const OPERAND &a, const OPERAND &b) {
		return MUL_TABLE[a][b];
	}

	inline OPERAND operator/(const OPERAND &a, const OPERAND &b) {
		return LDIV_TABLE[a][b];
	}

	inline OPERAND operator%(const OPERAND &a, const OPERAND &b) {
		return RDIV_TABLE[a][b];
	}

	OPERAND prefix[16384];
	OPERAND input[16384];

	void main() {
		ios::sync_with_stdio(false);
		long T, t;
		string part, res;
		part.reserve(16384);
		res.reserve(16384);
		for(cin >> T, t = 1; t <= T; ++ t) {
			long L, X;
			register long i, j;
			cin >> L >> X;
			long len = L * X;
			part.clear(); res.clear();
			cin >> part;
			cout << "Case #" << t << ": ";
			for(i = 0; i < X; ++ i) res += part;
			for(i = 0; i < len; ++ i) {
				input[i + 1] = OPERAND(res[i] - 'i' + 1);
			}
			for(i = 1; i <= len; ++ i) prefix[i] = prefix[i - 1] * input[i];
			if (len < 3) {
				cout << "NO" << endl;
				continue;
			}
			if (len == 3 && res != "ijk") {
				cout << "NO" << endl;
				continue;	
			}
			bool flag = false;
			for(i = 1; i < len - 1; ++ i) {
				if (prefix[i] != PI) continue;
				for(j = i + 1; j < len; ++ j) {
					if (prefix[j] % prefix[i] != PJ) continue;
					if (prefix[len] % prefix[j] != PK) continue;
					flag = true;
					break;
				}
				if (flag) break;
			}
			cout << (flag ? "YES" : "NO") << endl;
		}
	}
}

int main(void) {
	Solve::main();
	return 0;
}
