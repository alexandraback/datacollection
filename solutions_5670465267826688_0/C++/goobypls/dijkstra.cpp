#include <iostream>
#include <cstdio>

using namespace std;

enum {
	PO = 0, MO, PI, MI, PJ, MJ, PK, MK
};

const char *names[] = {
	"1", "-1", "i", "-i", "j", "-j", "k", "-k"
};

// Quaternion multiplication table.
char mult[8][8] = {
	// 1, -1
	{PO, MO, PI, MI, PJ, MJ, PK, MK},
	{MO, PO, MI, PI, MJ, PJ, MK, PK},
	
	// i, -i
	{PI, MI, MO, PO, PK, MK, MJ, PJ},
	{MI, PI, PO, MO, MK, PK, PJ, MJ},
	
	// j, -j
	{PJ, MJ, MK, PK, MO, PO, PI, MI},
	{MJ, PJ, PK, MK, PO, MO, MI, PI},
	
	// k, -k
	{PK, MK, PJ, MJ, MI, PI, MO, PO},
	{MK, PK, MJ, PJ, PI, MI, PO, MO},
};
// Quaternion inverse table.
char inv[8] = {
	PO, MO, MI, PI, MJ, PJ, MK, PK
};

void mult_table() {
	for (int i = 0; i < 8; i++) {
		printf("%2s:", names[i]);
		for (int j = 0; j < 8; j++)
			printf(" %2s", names[mult[i][j]]);
		printf("\n");
	}
}

#define BIGNUM (10005)
#define MULTIPLE (16)

int L, length;
char entry[MULTIPLE*BIGNUM];
char accum[MULTIPLE*BIGNUM];

bool doprob() {
	long long xbig;
	cin >> L >> xbig;
	if (xbig > 16LL) xbig = 12LL + (xbig % 4LL);
	int X = (int) xbig;
	length = X*L;
	
	string s;
	cin >> s;
	accum[0] = PO;
	for (int i = 0; i < length; i++) {
		char c = s[i%L];
		if (c == 'i') entry[i] = PI;
		if (c == 'j') entry[i] = PJ;
		if (c == 'k') entry[i] = PK;
		accum[i+1] = mult[accum[i]][entry[i]];
	}
	
	// The whole string should be the product ijk = -1.
	if (accum[length] != MO) {
		return false;
	}
	
	// Need an index a such that P[0:a] = i.
	int a = 1;
	for (; a < length; a++) {
		if (accum[a] == PI) break;
	}
	
	// Need an index b such that P[0:b] = P[b:] = k. Note that
	// P[b:] = inv(P[0:b])P[:] = (-k)(-1) = k, so it suffices to check P[0:b] = k.
	int b = length;
	for (; b > a; b--) {
		if (accum[b] == PK) break;
	}
	
	return a < b;
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		bool result = doprob();
		printf("Case #%d: %s\n", i, (result) ? "YES" : "NO");
	}
	return 0;
}