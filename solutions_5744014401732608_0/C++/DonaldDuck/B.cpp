// Problem B

#include <iostream>
#include <string.h>
#include <assert.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <math.h>
#include <fstream>

using namespace std;

typedef long long int ll;
typedef vector<int> vi;

void TestCase(int t) {
	int B;
	ll M;
	cin >> B;
	cin >> M;
	
	cout << "Case #" << t << ": ";
	
	if ((ll)round(pow(2, B-2)) < M) {
		cout << "IMPOSSIBLE\n";
		return;
	}
	
	else {
		int prima_riga[100];
		ll m = M;
		prima_riga[0] = 0;
		prima_riga[B-1] = 0;
		for (int i=B-2; i>0; i--) {
			prima_riga[i] = m%2;
			m = m/2;
		}
		
		assert(m <= 1);
		if (m > 0)
			for (int i=B-1; i > 0; i--)
				prima_riga[i] = 1;
			
		// Stampo
		cout << "POSSIBLE\n";
		for (int i=0; i<B; i++) cout << prima_riga[i];
		cout << endl;
		for (int i=0; i<B-1; i++) {
			cout << 0;
			for (int j=0; j<B-1; j++) {
				if (j <= i) cout << 0;
				else cout << 1;
			}
			cout << endl;
		}		
	}
}

int main() {
	int T;
	cin >> T;
	for (int t=1; t<=T; t++)
		TestCase(t);
	
	return 0;
}
