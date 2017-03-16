#include <bits/stdc++.h>

using namespace std;

int T, N, J;

long long spreadOut (long long n) {
	vector<int> v;
	while (n != 0) {
		v.push_back(n % 2);
		n >>= 1;
	}
	long long r = 0;
	for (int i = v.size() - 1; i >= 0; --i) {
		int d = v[i];
		r *= 4;
		r += d;
	}
	return r;
}

long long get_jth(int j) { // assume N even and j "small enough"
	long long res = (1LL << (N - 1)) + 1LL;
	long long sp = spreadOut(j)*3LL*2LL; // * 0b11, shift left 1
	return res + sp;
}

void printBin(long long n) { // n always nonzero
	vector<char> v;
	while (n != 0) {
		v.push_back('0' + (n % 2));
		n >>= 1;
	}
	for (int i = v.size() - 1; i >= 0; --i) cout << v[i];
}

int main() {
	freopen("C.txt", "r", stdin);
	freopen("C.out.txt", "w", stdout);
	cin >> T >> N >> J;
	cout << "Case #1:" << endl;
	for (int i = 0; i < J; ++i) {
		printBin(get_jth(i));
		cout << " 3 4 5 6 7 8 9 10 11";
		if (i != J - 1) cout << endl;
	}
}