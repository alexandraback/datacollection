#include <cassert>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int M[8][8], D[8][8];

void init() {
	M[0][0] = 0; M[0][1] = 1; M[0][2] = 2; M[0][3] = 3;
	M[1][0] = 1; M[1][1] = 4; M[1][2] = 3; M[1][3] = 6;
	M[2][0] = 2; M[2][1] = 7; M[2][2] = 4; M[2][3] = 1;
	M[3][0] = 3; M[3][1] = 2; M[3][2] = 5; M[3][3] = 4;


	for(int i = 0; i < 8; ++i)
		for(int j = 0; j < 8; ++j) {
			if(i < 4 && j < 4) continue;
			M[i][j] = (i & 4) ^ (j & 4) ^ M[i & 3][j & 3];
		}
	for(int i = 0; i < 8; ++i)
		for(int j = 0; j < 8; ++j)
			for(int k = 0; k < 8; k++)
				if(M[i][k] == j) 
					D[i][j] = k;
	for(int i = 0; i < 8; ++i) {
		assert(accumulate(M[i], M[i] + 8, 0) == 28);
		assert(accumulate(D[i], D[i] + 8, 0) == 28);
	}
}

bool calc(int L, long long X, const vector<int>& v) {
	vector<int> pre(L + 1, 0);
	for(int i = 1; i <= L; ++i) pre[i] = M[pre[i - 1]][v[i - 1]];
	vector<int> pow(5, 0);
	for(int i = 1; i <= 4; ++i) pow[i] = M[pow[i - 1]][pre[L]];
	
	// same part
	for(int l = 0; l < 4; ++l)
		for(int r = 0; r < 4; ++r) {
			if(l + r + 1 > X || (X - (l + r + 1)) % 4 != 0) continue;
			for(int i = 1; i < L; ++i) {
				if(M[pow[l]][pre[i]] != 1) continue;
				for(int j = i + 1; j < L; ++j)
					if(D[pre[i]][pre[j]] == 2 && M[D[pre[j]][pre[L]]][pow[r]] == 3)
						return true;
			}
		}
	// different part
	for(int l = 0; l < 4; ++l)
		for(int m = 0; m < 4; ++m)
			for(int r = 0; r < 4; ++r) {
				if(l + m + r + 2 > X || (X - (l + m + r + 2)) % 4 != 0) continue;
				for(int i = 1; i <= L; ++i) {
					if(M[pow[l]][pre[i]] != 1) continue;
					for(int j = 1; j <= L; ++j)
						if(M[M[D[pre[i]][pre[L]]][pow[m]]][pre[j]] == 2 && M[D[pre[j]][pre[L]]][pow[r]] == 3)
							return true;
				}
			}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	init();
	int T, L;
	long long X;
	string s;
	vector<int> v;
	cin >> T;
	for(int cs = 1; cs <= T; ++cs) {
		cin >> L >> X >> s;
		v.resize(L);
		for(int i = 0; i < L; ++i)
			v[i] = s[i] - 'i' + 1;
		cout << "Case #" << cs << ": " << (calc(L, X, v) ? "YES" : "NO") << endl;
	}
	return 0;
}
