#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <stdlib.h>
#include <string.h>

using namespace std;

const int maxBit = 32;

struct PartialNumer {
	int bits[maxBit];
} ;

vector<PartialNumer> A, B, K;
vector<PartialNumer> Ap, Bp;

long long solve(int index) {
	int* k = K[index].bits;
	long long result = 0;
	for (int i=0; i<Ap.size(); ++i)
		for (int j=0; j<Bp.size(); ++j) {
			int* a = Ap[i].bits;
			int* b = Bp[j].bits;
			long long this_count = 1;
			for (int l=maxBit-1; l>=0; --l) {
				if (k[l] == -1) {
					if (a[l] == -1)
						this_count *= 2;
					if (b[l] == -1)
						this_count *= 2;
				} else if (k[l] == 0) {
					if (a[l] == -1 && b[l] == -1)
						this_count *= 3;
					if ((a[l] == 0 && b[l] == -1) || (a[l] == -1 && b[l] == 0))
						this_count *= 2;
					if (a[l] == 1 && b[l] == 1) {
						this_count = 0;
						break;
					}
				}
			}
			result += this_count;
		}
	return result;
}

void refineVector(int index, vector<PartialNumer>& V, vector<PartialNumer>& Vp) {
	int* bits = K[index].bits;
	int new_array[maxBit];
	for (int i=0; i<V.size(); ++i) {
		int* temp = V[i].bits;
		bool found = true;
		for (int j=maxBit-1; j>=0; --j) {
			if (bits[j] == 0 || bits[j] == -1)
				new_array[j] = temp[j];
			else if (bits[j] == 1) {
				if (temp[j] == 0) {
					found = false;
					break;
				}
				new_array[j] = 1;
			}
		}
		if (!found)
			continue;

			
		PartialNumer p;
		memcpy(p.bits, new_array, maxBit * sizeof(int));
		Vp.push_back(p);
	}

/*	for (int i=0; i<Vp.size(); ++i) {
		for (int j=maxBit-1; j>=0; --j)
			cout << Vp[i].bits[j] << " ";
		cout << endl;
	}
	cout << endl;
*/
}

void fillVector(int n, vector<PartialNumer>& N) {
	int this_bit[maxBit];
	for (int i=0; i<maxBit; ++i)
		this_bit[i] = -1;

	for (int i=maxBit-1; i>=0; --i) {
		int my_bit = n & (1 << i);
		if (my_bit == 0)
			this_bit[i] = 0;
		else {
			this_bit[i] = 0;
			PartialNumer p;
			memcpy(p.bits, this_bit, maxBit * sizeof(int));
			N.push_back(p);
			this_bit[i] = 1;
		}
	}
/*
	for (int i=0; i<N.size(); ++i) {
		for (int j=maxBit-1; j>=0; --j)
			cout << N[i].bits[j] << " ";
		cout << endl;
	}
	cout << endl;*/
}

int main () {
/*	int a;
	cin >> a;
	fillVector(a, A);*/
	int T;
	cin >> T;
	for (int tt=1; tt<=T; ++tt) {
		A.clear();
		B.clear();
		K.clear();
		int a, b, k;
		cin >> a >> b >> k;
		fillVector(a, A);
		fillVector(b, B);
		fillVector(k, K);

		long long count = 0;
		for (int i=0; i<K.size(); ++i) {
			Ap.clear();
			Bp.clear();
//			cout << i << endl;
//			cout << "Ap" << endl;
			refineVector(i, A, Ap);
//			cout << "Bp" << endl;
			refineVector(i, B, Bp);

			count += solve(i);
		}

		cout << "Case #" << tt << ": " << count << endl;
		
//		cout << count << endl;
	}
	return 0;
}
