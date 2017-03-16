#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a; i<int(b); i++)
typedef long long LL;

int data[8][8], neg[8]={4,5,6,7,0,1,2,3}, tf[4]; // total product

bool solve() {
	LL L,X;
	string s;
	cin >> L >> X >> s;
	int cum = 0;
	for (char c : s) cum = data[cum][c-'i'+1];
	tf[1] = cum;
	tf[2] = data[tf[1]][cum];
	tf[3] = data[tf[2]][cum];

	LL p = 0;
	// Look for i
	bool foundI = false;
	int iCum = 0;
	for (p = 0; p < 4*L; p++) {
		iCum = data[iCum][s[p%L]-'i'+1];
		if (iCum == 1) {
			foundI = true;
			break;
		}
	}
	if (!foundI) return false;

	// Look for j
	bool foundJ = false;
	int jCum = 0;
	for (p++; p < 8*L; p++) {
		jCum = data[jCum][s[p%L]-'i'+1];
		if (jCum == 2) {
			foundJ = true;
			break;
		}
	}
	if (!foundJ || p >= L*X-1) return false;

	// Look for k
	int kCum = 0;
	for (p++; p%L; p++) kCum = data[kCum][s[p%L]-'i'+1];
	LL l3 = ((L*X-p)/L) % 4;
	kCum = data[kCum][tf[l3]];
	return kCum == 3;
}

int main() {
	data[0][0] = 0;
	data[0][1] = 1;
	data[0][2] = 2;
	data[0][3] = 3;
	data[1][0] = 0;
	data[1][1] = 4;
	data[1][2] = 3;
	data[1][3] = 6;
	data[2][0] = 2;
	data[2][1] = 7;
	data[2][2] = 4;
	data[2][3] = 1;
	data[3][0] = 3;
	data[3][1] = 2;
	data[3][2] = 5;
	data[3][3] = 4;
	FOR(i,0,4) FOR(j,4,8) data[i][j] = neg[data[i][neg[j]]];
	FOR(i,4,8) FOR(j,0,4) data[i][j] = neg[data[neg[i]][j]];
	FOR(i,4,8) FOR(j,4,8) data[i][j] = data[neg[i]][neg[j]];

	int TC;
	cin >> TC;
	FOR(tc,1,TC+1) {
		cout << "Case #" << tc << ": " << (solve() ? "YES" : "NO") << endl;
	}
}
