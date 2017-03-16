#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
using namespace std;

int K, L, S, nC;
string keyboard, target, C;
const int maxN = 111;
double mem[maxN][maxN], P[maxN];
int lm_mem[maxN][maxN];


int longestMatch(int cur, int c) {
	int &res = lm_mem[cur][c];
	if(res >= 0) return res;
	string s = target.substr(0, cur) + string(1, C[c]);
	for(int l = min(L, cur+1); l >= 1; --l) {
		if(s.substr(cur+1-l, l) == target.substr(0, l)) return res = l;
	}
	return res = 0;
}

double f(int longestCurrent, int rem) {
	double &res = mem[longestCurrent][rem];
	if(res >= 0) return res;
	if(rem + longestCurrent < L) return res = 0;
	res = longestCurrent == L;
	if(rem) {
		for(int c = 0; c < nC; c++) {
			res += P[c] * f(longestMatch(longestCurrent, c), rem-1);
		}	
	}
	return res;
}

int maxBananas() {
	for(int i = 0; i < L; i++) {
		for(int c = 0; c < nC; ++c) {
			if(longestMatch(i, c) == i+1) goto CON;	
		}
		return 0;
CON:;
	}
	for(int l = 1; l <= L; l++) {
		if(target.substr(l, L-l) + target.substr(L-l, l) == target) {
			return 1 + (S-L)/l;			
		}
	}
	return 0;
}

void genChars() {
	sort(keyboard.begin(), keyboard.end());
	C = keyboard;
	C.resize(unique(C.begin(), C.end())-C.begin());
	nC = C.size();
	for(int i = 0; i < nC; ++i) {
		P[i] = 1. * count(keyboard.begin(), keyboard.end(), C[i]) / keyboard.size();
	}
}

int main() {
	int T;
	cin >> T;
	for(int cs = 1; cs <= T; ++cs) {
		cin >> K >> L >> S;
		cin >> keyboard;
		cin >> target;
		genChars();
		memset(mem, 0xff, sizeof(mem));
		memset(lm_mem, 0xff, sizeof(lm_mem));
		cout << fixed << setprecision(12);
		cout << "Case #" << cs << ": " << maxBananas() - f(0, S) << endl;
	}
	return 0;
}
