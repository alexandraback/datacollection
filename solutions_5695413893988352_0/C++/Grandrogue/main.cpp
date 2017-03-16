#include <fstream>
#include <string>
#include <iostream>

using namespace std;

ifstream fin("B-small-attempt1.in");
ofstream fout("out.txt");

int mpow(int a, int b) {
	int res = 1;
	for (int i = 0; i < b; ++i) {
		res *= a;
	}
	return res;
}

int nsize(int a) {
	if (a == 0) {
		return 1;
	}
	int cnt = 0;
	while (a > 0) {
		a /= 10;
		cnt++;
	}
	return cnt;
}

bool matches(int a, string s) {
	int aa[3];
	for (int i = 0; i < s.length(); ++i) {
		aa[i] = a / mpow(10, s.length() - i - 1);
		if (aa[i] != s[i] - '0' && s[i] != '?') return false;
		a %= mpow(10, s.length() - i - 1);
	}
	return true;
}



int main() {
	int tests;
	fin >> tests;
	string a, b;
	for (int test = 0; test < tests; ++test) {
		fin >> a >> b;
		int cap = mpow(10, a.length());
		int mina = 1000, minb = 1000, mindiff = 1000;
		for (int i = 0; i < cap; ++i) {
			for (int j = 0; j < cap; ++j) {
				if (matches(i, a) && matches(j, b)) {
					int diff = abs(i - j);
					if (diff < mindiff) {
						mindiff = diff;
						mina = i;
						minb = j;
					} else
					if (diff == mindiff) {
						if (i < mina) {
							mina = i;
							minb = j;
						} else if (i == mina && j < minb) {
							minb = j;
						}
					}
				}
			}
		}
		fout << "Case #" << test + 1 << ": "; 
		for (int i = 0; i < a.length() - nsize(mina); ++i) {
			fout << '0';
		}
		fout << mina << " ";
		for (int i = 0; i < a.length() - nsize(minb); ++i) {
			fout << '0';
		}
		fout <<	minb << endl;
	}

	return 0;
}
