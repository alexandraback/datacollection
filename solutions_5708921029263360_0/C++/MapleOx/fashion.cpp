#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

struct triple {
	int j;
	int p;
	int s;
};

void printTriple(struct triple triple) {
	cout << triple.j << " " << triple.p << " " << triple.s << endl;
}

void printcase(int i) {
	cout << "Case #" << i+1 << ": ";
}

bool conflicting(int j, int p, int s, int K, vector <struct triple> combinations) {
	int jp, ps, js;
	jp = ps = js = 0;
	for (int i = 0; i < combinations.size(); ++i) {
		struct triple t = combinations[i];
		if (t.j == j && t.p == p)
			jp++;
		if (t.j == j && t.s == s)
			js++;
		if (t.p == p && t.s == s)
			ps++;
	}
	if (jp >=  K || ps >= K || js >= K)
		return false;
	return true;
}

int main() {
	int T;
	int J, P, S, K;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		vector<struct triple> combinations;
		printcase(i);
		cin >> J >> P >> S >> K;
		for (int j = 1; j <= J; ++j) {
			for (int p = 1; p <= P; ++p) {
				for (int s = 1; s <= S; ++s) {
					if (!conflicting(j, p, s, K, combinations)) {
						struct triple t;
						t.j = j;
						t.p = p;
						t.s = s;
						combinations.push_back(t);
					}
				}
			}
		}
		cout << combinations.size() << endl;
		for (int k = 0; k < combinations.size(); ++k) {
			printTriple(combinations[k]);
		}
	}

	return 0;
}