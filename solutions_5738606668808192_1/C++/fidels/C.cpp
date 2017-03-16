#include <iostream>
#include <cstdlib>
#include <ctime>
#include <set>
using namespace std;

#define MAXN 32
#define MAXJ 500
#define MAXP 25

int p[MAXP] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

int modexp(int a, int b, int mod) {
	int RES = 1;
	while (b) {
		if (b&1) RES = (RES*a)%mod;
		a = (a*a)%mod;
		b >>= 1;
	}
	return RES;
}

set<long long> done;

void MathematicaCheck(int n[MAXN], int N, int div[11]) {
	for (int i=2; i<=10; i++) {
		cerr << "Divisible[FromDigits[{1";
		for (int j=N-2; j>=0; j--) cerr << ", " << n[j];
		cerr << "}, " << i << "], " << div[i] << "], ";
	}
}

int main() {
	int T, N, J, n[MAXN], i, j, k, tmp, div[11];

	srand(time(0)); cerr << "And@@{";
	
	cin >> T >> N >> J;
	cout << "Case #1:" << endl;
	while (J) {
		n[0] = n[N-1] = 1;
		for (i=1; i<N-1; i++) n[i] = rand()%2;
		
		long long num = 0LL;
		for (i=0; i<N; i++) if (n[i]) num ^= (1LL<<i);
		if (done.find(num) != done.end()) continue;
		
		for (i=2; i<=10; i++) {
			for (j=0; j<MAXP; j++) {
				tmp = 0;
				for (k=0; k<N; k++) if (n[k]) tmp += modexp(i, k, p[j]);
				if (tmp%p[j] == 0) break;
			}
			if (j == MAXP) break;
			else div[i] = p[j];
		}
		done.insert(num);
		
		if (i == 11) {
			MathematicaCheck(n, N, div);
			for (i=N-1; i>=0; i--) cout << n[i];
			for (i=2; i<=10; i++) cout << ' ' << div[i];
			cout << endl;
			J--;
		}
	}
	cerr << "}" << endl;

	return 0;
}
