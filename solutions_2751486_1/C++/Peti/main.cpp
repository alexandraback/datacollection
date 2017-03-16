#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <algorithm>
#include <set>
#include <list>
#include <stack>
#include <cstdio>
#include <sstream>
#include <map>
#include <cmath>
#include <queue>
#include <ctime>

#define FOR(i,n) for(int i = 0; i < (n); ++i)
#define SZ(x) ((int)((x).size()))

using namespace std;

typedef long long int LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<bool> VB;
typedef vector<VB> VVB;
typedef vector<double> VD;
typedef vector<VD> VVD;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;

bool vowel(char c) {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
	ifstream fin("a2.in");
	ofstream fout("a2.out");
	int t;
	fin >> t;
	vector<LL> a(1000010);
	for (int tt = 1; tt <= t; ++tt) {
		string s;
		LL n;
		fin >> s >> n;
		LL ptr = 0;
		LL cons = 0;
		LL beg = 0;
		LL as = 0;
		while (ptr < s.size()) {
			while (cons < n && ptr < s.size())
			{
				if (vowel(s[ptr])) {
					cons = 0;
				} else {
					++cons;
				}
				++ptr;
			}
			if (cons == n)
			{
				a[as++] = ptr - cons - beg;
				while (ptr < s.size() && !vowel(s[ptr])) { ++ptr; ++cons; }
				a[as++] = cons;
				beg = ptr;
				cons = 0;
			}
		}
		a[as++] = ptr - beg;
		LL res = 0;
		for (LL i = 0; i < as; i+=2) {
			res += (a[i]*(a[i]+1)) / 2;
			if (i) res += (a[i-1] >= n ? n-1 : a[i-1]) * a[i];
			if (i+1 < as) {
				res += (a[i+1] >= n ? n-1 : a[i+1]) * a[i];
				if (a[i+1] >= n) {
					LL last = a[i+1], first = a[i+1] - n + 2;
					res += ((first + last) * (last - first + 1)) / 2;
				} else {
					res += (a[i+1] * (a[i+1]+1)) / 2;
				}
				if (i) {
					LL turnv = a[i-1] > a[i+1] ? a[i+1] : a[i-1];
					res += (a[i-1] >= n ? n-1 : a[i-1]) * (a[i+1] >= n ? n-1 : a[i+1]);
				}
			}
		}
		res = (((LL)s.size() * (LL)(s.size()+1) / 2) - res);
		fout << "Case #" << tt << ": " << res << "\n";
	}
	fin.close();
	fout.close();
	return 0;
}
