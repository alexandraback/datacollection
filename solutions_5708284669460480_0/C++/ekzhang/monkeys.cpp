#include <bits/stdc++.h>
using namespace std;

int k, l, s;
string keyboard, want;

long pow(int a, int b) {
	long ret = 1;
	for (int i = 0; i < b; i++) {
		ret *= a;
	}
	return ret;
}

string* keyseqs(int len) {
	if (len == 0) {
		string* ret = new string[1];
		ret[0] = "";
		return ret;
	}
	string* rec = keyseqs(len - 1);
	long rec_sz = pow(k, len - 1);
	string* ret = new string[rec_sz * k];
	for (int i = 0; i < rec_sz; i++) {
		for (int j = 0; j < k; j++) {
			ret[k * i + j] = rec[i] + keyboard[j];
		}
	}
	delete[] rec;
	return ret;
}

int find(string s, string f) {
	int count = 0;
	for (int i = 0; i < s.length() - f.length() + 1; i++) {
		bool worked = true;
		for (int j = 0; j < f.length(); j++) {
			if (s[i + j] != f[j]) {
				worked = false;
			}
		}
		if (worked) {
			count++;
		}
	}
	return count;
}

int main() {
	ifstream in ("monkeys.in");
	ofstream out("monkeys.out");

	int t;
	in >> t;
	for (int tc = 1; tc <= t; tc++) {
		out << "Case #" << tc << ": ";
		in >> k >> l >> s;
		in >> keyboard >> want;
		string* seqs = keyseqs(s);
		long amt = 0;
		long max = 0;
		long p = pow(k, s);
		for (int i = 0; i < p; i++) {
			long res = find(seqs[i], want);
			amt += res;
			if (res > max)
				max = res;
		}
		out << max - ((double) amt) / p << endl;
	}

	return 0;
}
