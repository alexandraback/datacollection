#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

typedef long long LL;
typedef long double LD;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int,int> PII;
#define FOR(k,a,b) for(typeof(a) k=(a); k <= (b); ++k)
#define REP(k,a) for(int k=0; k < (a); ++k)
#define REPD(k,a) for(int k=(a)-1; k >= 0; --k)
#define PB push_back 
#define MP make_pair

int multable[8][8] = {
	{ 0, 1, 2, 3, 4, 5, 6, 7 },
	{ 1, 4, 3, 6, 5, 0, 7, 2 },
	{ 2, 7, 4, 1, 6, 3, 0, 5 },
	{ 3, 2, 5, 4, 7, 6, 1, 0 },
	{ 4, 5, 6, 7, 0, 1, 2, 3 },
	{ 5, 0, 7, 2, 1, 4, 3, 6 },
	{ 6, 3, 0, 5, 2, 7, 4, 1 },
	{ 7, 6, 1, 0, 3, 2, 5, 4 }
};
inline int decodeijk(char c) {
	if (c == '1') return 0;
	if (c == 'i') return 1;
	if (c == 'j') return 2;
	if (c == 'k') return 3;
	return -1;
}
int ijkRevL(int val, int resval) {
	for (int i = 0; i < 8; ++i) {
		if (multable[i][val] == resval) return i;
	}
	return -1;
}
int ijkRevR(int val, int resval) {
	for (int i = 0; i < 8; ++i) {
		if (multable[val][i] == resval) return i;
	}
	return -1;
}
void problemc(int t) {
	int L,X;
	unsigned long long position;
	string s,res;
	cout << "Case #" << (t + 1) << ": ";
	cin >> L >> X >> s;

	unsigned long long fposi, fposj, fposk;
	
	LL pos[8] = { -1, -1, -1, -1, -1, -1, -1, -1 };
	LL rpos[8] = { -1, -1, -1, -1, -1, -1, -1, -1 };

	int ival = 0;
	int i = 0;
	while (i < s.length()) {
		ival = multable[ival][decodeijk(s[i])];
		if (pos[ival] == -1) pos[ival] = i;
		i++;
	}
	int fval = ival;
	i = s.length() - 1;
	int irval = 0;
	while (i >= 0) {
		irval = multable[decodeijk(s[i])][irval];
		if (rpos[irval] == -1) rpos[irval] = L - i;
		i--;
	}

	LL IPos = -1;
	LL KPos = -1;

	if (pos[1] != -1) IPos = pos[1];
	else {
		LL nval = fval;
		for (int x = 1; x < X; x++) {
			int p = ijkRevR(nval, 1);
			if (pos[p] != -1) {
				IPos = pos[p] + x * L;
				break;
			}
			nval = multable[nval][fval];
		}
		if (IPos == -1) {
			cout << "NO" << endl;
			return;
		}
	}

	//cout << endl << "IPOS: " << IPos << endl;

	if (rpos[3] != -1) KPos = X * L - rpos[3];
	else {
		LL nval = irval;
		for (int x = 1; x < X; x++) {
			int p = ijkRevL(nval, 3);
			if (rpos[p] != -1) {
				KPos = X * L - rpos[p] - x * L;
				break;
			}
			nval = multable[irval][nval];
		}
		if (KPos == -1) {
			cout << "NO" << endl;
			return;
		}
	}

	//cout << endl << "KPOS: " << KPos << endl;

	if (IPos + 1 >= KPos) {
		cout << "NO" << endl;
		return;
	}
	ival = 0;
	for (auto i = IPos + 1; i < KPos; ++i) {
		int ii = i % L;
		ival = multable[ival][decodeijk(s[ii])];
	}
	if (ival == 2) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return;
	if (IPos / L != KPos / L) {
		ival = 0;
		for (auto i = (IPos + 1) % L; i < L; ++i) {
			ival = multable[ival][decodeijk(s[i])];
			//cout << endl << "ival: " << ival;
		}
		auto fb = (IPos + 1) / L + ((IPos + 1) % L == 0);

		LL nx = (KPos - IPos - 3) / L;
		for (auto x = 0; x < nx; x++) {
			ival = multable[ival][fval];
			//cout << endl << "ival: " << ival;
		}
		for (auto i = 0; i < KPos % L; i++) {
			ival = multable[ival][decodeijk(s[i])];
			//cout << endl << "ival: " << ival;
		}
		//cout << endl << "ival: " << ival << endl;
		if (ival != 2) {
			cout << "NO" << endl;
			return;
		}
	}
	else {
		ival = 0;
		for (auto i = IPos + 1; i < KPos; ++i) {
			ival = multable[ival][decodeijk(s[i])];
		}
		//cout << endl << "ival: " << ival << endl;
		if (ival != 2) {
			cout << "NO" << endl;
			return;
		}
	}

	cout << "YES" << endl;
}
void splitPP(int* PP, int& curmax) {
	int val = curmax;
	int r1 = val / 2;
	int r2 = val / 2 + val % 2;
	PP[curmax]--;
	PP[r1]++;
	PP[r2]++;
	while (PP[curmax] == 0 && curmax > 0) curmax--;
}
void problemb(int t) {
	int D;
	int PP[1001];
	cout << "Case #" << (t + 1) << ": ";
	cin >> D;
	int curmax = 0;
	memset(PP, 0, sizeof(int) * 1001);
	for (auto i = 0; i < D; ++i) {
		int val;
		cin >> val;
		PP[val]++;
		if (val > curmax) curmax = val;
	}
	int bestres = curmax;
	int res = 0;
	while (curmax > 0) {
		if (res > bestres) break;


	}

	cout << bestres << endl;
}


int main()
{
	int T;
	cin >> T;
	for (auto t = 0; t < T; ++t)
	{
		problemc(t);
		//break;
	}
	
	return 0;
}

