#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <cassert>
using namespace std;

typedef long long tl; //type long
int _tc;
#define SIZE 1024

#define index(a, b) ((a * n) + b)

#define toidx(a, s) ((std::find(a.begin(), a.end(), s) - a.begin()))
int n;
int firsts[SIZE];
int lasts[SIZE];
int used[SIZE];
int maxf, maxl;

int scoreToAdd(int ust, int s) {
	int f = firsts[s];
	int l = lasts[s];
	int af, al;
	af = al = 1;
	for (int i = 0; i < ust && (af + al); ++i) {
		int idx = used[i];
		if (firsts[idx] == f && af)
			af = 0;
		if (lasts[idx] == l && al)
			al = 0;
	}
	return (af + al);
}

int tryTo(int ust, int score) {
	int i = (ust > 0) ? used[ust - 1]:0;
	int maxaaa = SIZE;
	for (; i < n; ++i) {
		int a = scoreToAdd(ust, i);
		if (score + a >= (maxf + maxl))
			return ust + 1;
		if (a) {
			used[ust] = i;
			maxaaa = min(maxaaa, tryTo(ust + 1, score + a));
		}
	}
	return maxaaa;
}

bool testCase() {
	cin >> n;
	vector<string> mf, ml;

	for (int i = 0; i < n; ++i) {
		string f, l;
		cin >> f >> l;
		int _if = toidx(mf, f);
		int _il = toidx(ml, l);
		if (_if == mf.size())
			mf.push_back(f);
		if (_il == ml.size())
			ml.push_back(l);
		firsts[i] = _if;
		lasts[i] = _il;
	}
	maxf = mf.size();
	maxl = ml.size();

	int mina = tryTo(0, 0);
	cout << (n - mina);
	return true;
}

bool testCase2() {
	int n;
	cin >> n;
	vector<string> mf, ml;
	int firsts[SIZE];
	int lasts[SIZE];

	for (int i = 0; i < n; ++i) {
		string f, l;
		cin >> f >> l;
		int _if = toidx(mf, f);
		int _il = toidx(ml, l);
		if (_if == mf.size())
			mf.push_back(f);
		if (_il == ml.size())
			ml.push_back(l);
		firsts[i] = _if;
		lasts[i] = _il;
	}
	int vw[SIZE][SIZE]; //[vi][vw]
	// memset(vw[0], 0, sizeof(vw[0]));
	// for (int vi = 0; vi < n; ++vi) {
	// 	for (int wi = 0; wi < n; ++wi) {			
	// 		vw[vi][wi] = max(vw[vi - 1][wi], score + vw[vi - 1][wi]);
	// 	}
	// 	vw[vi]
	// }
	for (int i = 0; i < n; ++i) {
		cerr << firsts[i] << " " << lasts[i] << endl;
	}
	return true;
}

int main(){
	int ntc;

	cin >> ntc;
	//cerr << "tests " << n << endl;
	for (int _tc = 0; _tc < ntc; ++_tc) {
		cout << "Case #" << (_tc + 1) << ": ";
		if (!testCase()) {
			cout << " IMPOSSIBLE";
		}
		cout << endl;
	}
	return 0;
}