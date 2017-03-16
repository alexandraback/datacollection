
#include <iostream>
#include <cstdio>
using namespace std;

const int i = 2;
const int j = 3;
const int k = 4;

int m(int a, int b) {
	int r = 1;
	a = a < 0 ? (r*=-1, -a) : a;
	b = b < 0 ? (r*=-1, -b) : b;
	switch (a) {
		case 1: return r*((int[]){0, 1, i, j, k})[b];
		case i: return r*((int[]){0, i, -1, k, -j})[b];
		case j: return r*((int[]){0, j, -k, -1, i})[b];
		case k: return r*((int[]){0, k, j, -i, -1})[b];
	}
}
int ij = m(i, j);
int ijk = m(ij, k);

int get(char c) {
	switch (c) {
		case '1': return 1;
		case 'i': return i;
		case 'j': return j;
		case 'k': return k;
	}
}

int acc[110005] = {0};
int L, X;

int find_i() { 
	for (int c = 0; c < L*X-2; ++c) {
		if (acc[c] == i) {
		    return c;
		}
	}
	return 99999999;
}

int find_j() {
	for (int c = L*X-2; c >= 1; --c) {
		if (acc[c] == ij) {
		    return c;
		}
	}
	return -1;
}

bool find() {
    if (acc[L*X-1] != ijk) return false;
    return find_i() < find_j();
}

int main() {
	int t;
	cin >> t;
	for (int ii = 1; ii <= t; ++ii) {
		cin >> X >> L;
		int g = L % 4;
		while (g < L && g < 11) g += 4;
		L = g;
		char cs[10005];
		scanf("%s", cs);
		int in[10005];
		for (int c = 0; c < X; ++c) {
		    in[c] = get(cs[c]);
		}
		
		acc[0] = in[0];
		for (int c = 1; c < X*L; ++c) {
			acc[c] = m(acc[c-1], in[c%X]);
		}
		
		cout << "Case #" << ii << ": " << (find() ? "YES" : "NO") << endl;
	}
}

