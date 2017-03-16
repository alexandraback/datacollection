#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_set>
#include <valarray>
#include <vector>

using namespace std;

typedef long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef vector<bool> vb;

#define DELTA 1e-6

int main() {
#ifdef TESTING
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int T, K, L, S;
	string keyboard, target;
	cin >> T;
	for (int caso = 1; caso <= T; caso++) {
		cin >> K >> L >> S;
		cin >> keyboard >> target;

		vector<double> prob(26);
		for (int i = 0; i < K; i++)
			prob[keyboard[i]-'A'] += 1.0;
		for (int i = 0; i <= 'Z'-'A'; i++)
			prob[i] /= K;

		double avg = 1.0;
		for (int i = 0; i < L; i++)
			avg *= prob[target[i]-'A'];
		avg *= S - L + 1;

		int lensufijo = -1;
		for (int i = L - 2; i >= 0 && lensufijo < 0; i--) {
			if (target[L-1] == target[i]) {
				bool ok = true;
				for (int j = 1; i-j >= 0 && ok; j++)
					if (target[L-1-j] != target[i-j]) ok = false;
				if (ok)
					lensufijo = L - (i+1);
			}
		}
		if (lensufijo < 0) lensufijo = L;

		double best = 1.0;
		best = 1 + (S - L) / lensufijo;

		if (avg == 0.0) {
			printf("Case #%d: 0.0\n", caso);
		} else {
			printf("Case #%d: %.7lf\n", caso, best - avg);
		}
	}

	return 0;
}
