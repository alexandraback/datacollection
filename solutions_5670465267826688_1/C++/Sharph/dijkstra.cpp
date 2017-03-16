#include <iostream>
#include <cassert>

#define I 2
#define J 3
#define K 4

using namespace std;

int T[4][4] = {
	{ 1,  I,  J,  K},
	{ I, -1,  K, -J},
	{ J, -K, -1,  I},
	{ K,  J, -I, -1},
};

int mul(int a, int b) {
	int sgn = 1;
	if(a < 0) {
		a = -a;
		sgn = -sgn;
	}
	if(b < 0) {
		b = -b;
		sgn = -sgn;
	}
	return sgn * T[a - 1][b - 1];
}

int toval(char c) {
	if(c == 'i') return I;
	if(c == 'j') return J;
	if(c == 'k') return K;
	assert(false);
	return 1000;
}

int main() {
	cin.sync_with_stdio(false);
	
	int T;
	cin >> T;
	
	for(int t = 0; t < T; ++t) {
		int L;
		long long X;
		cin >> L >> X;
		
		string S;
		cin >> S;
		
		long long x = min(X, 40LL);
		x += (X - x) % 4;
		
		string Q;
		for(long long i = 0; i < x; ++i) {
			Q += S;
		}
		
		bool ok = true;
		try {
			int val = 1;
			int i = 0;
			while(val != I) {
				if(i == Q.size()) throw 5;
				val = mul(val, toval(Q[i]));
				++i;
			}
			val = 1;
			while(val != J) {
				if(i == Q.size()) throw 5;
				val = mul(val, toval(Q[i]));
				++i;
			}
			val = 1;
			while(i != Q.size()) {
				val = mul(val, toval(Q[i]));
				++i;
			}
			if(val != K) throw 5;
		} catch(int x) {
			ok = false;
		}
		
		cout << "Case #" << t + 1 << ": " << (ok ? "YES" : "NO") << "\n";
	}
	
	return 0;
}
