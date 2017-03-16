//Problem: GCJ 2012 Qualification Round C
//Name: Recycled Numbers
//Author: Bruce K. B. Tong

#include <iostream>
#include <algorithm>
using namespace std;

//#define SMALL
#define LARGE

#define MAX 2000000
int rotation[MAX+1];
int multipier[7+1] = {0, 1, 10, 100, 1000, 10000, 100000, 1000000};
int digit[7+1] = {0, 9, 99, 999, 9999, 99999, 999999, 9999999};

//return the number of digits of number a
int digits(int a) {
	return lower_bound(digit, digit+7+1, a) - digit;
	/*
	int count = 0;
	while (a > 0) {
		a /= 10;
		count++;
	}
	return count;
	*/
}

int rotate(int a, int digits, int &r) {
	//return the rotated a: 12345 -> 51234
	int q;
	q = a / 10;
	r = a % 10;
	r *= multipier[digits];
	return r + q;
}

void init(int rotation[]) {
	int a, d, r, key;
	for (int i = 1; i <= MAX; i++) {
		if (rotation[i] != -1) continue;
		d = digits(i);
		key = a = i;
		for (int j = 0; j < d; j++) {
			a = rotate(a, d, r);		//e.g. rotation[12345] = 51234
			if (r != 0 && a <= MAX) {	//r == 0 means rotated a has leading zero
				rotation[key] = a;
				key = a;
			}
		}
	}
	/* post-condition:
		r[key] = a
		r[12345] = 51234	r[1020]	= 102 (ignore)
		r[51234] = 45123	r[1020]	= 2010
		r[45123] = 34512	r[2010] = 201 (ignore)
		r[34512] = 23451	r[2010] = 1020
		r[23451] = 12345
	*/
}

int compute(int A, int B) {
	int count = 0;
	int m, x;
	for (int n = A; n <= B; n++) {
		if (rotation[n] != n) {
			x = n;
			while (rotation[x] != n) {
				m = rotation[x];
				if (n < m && m <= B) count++;
				x = m;
			}
		}
	}
	return count;
}

int main() {
	freopen("C-sample.in", "rt", stdin);
	#ifdef SMALL
		freopen("C-small-attempt0.in", "rt", stdin);
		freopen("C-small-attempt0.out", "wt", stdout);
	#endif
	#ifdef LARGE
		freopen("C-large.in", "rt", stdin);
		freopen("C-large.out", "wt", stdout);
	#endif

	int T;			//1 <= T <= 50
	int A, B;		//1 <= A, B <= 1,000 (or 2,000,000)

	memset(rotation, ~0, sizeof(rotation));		//init all to -1
	init(rotation);

	cin >> T;

	for (int i = 1; i <= T; i++) {
		cin >> A >> B;
		cout << "Case #" << i << ": ";
		cout << compute(A, B) << endl;
	}
	
	return 0;
}