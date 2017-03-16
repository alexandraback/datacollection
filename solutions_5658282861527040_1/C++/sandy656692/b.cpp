#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <set>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

const int L = 32;
int a[L], b[L], c[L];
bool flag[2][2][2][L];
long long all[2][2][2][L];

long long cal(bool ea, bool eb, bool ec, int pos) {
	if (pos < 0) {
		return 1;
	}
	if (flag[ea][eb][ec][pos]) return all[ea][eb][ec][pos];
	flag[ea][eb][ec][pos] = true;
	if (!ea && !eb && !ec) {
		all[ea][eb][ec][pos] = 1LL << ((pos + 1) * 2);
		return all[ea][eb][ec][pos];
	}
	int topa, topb;
	if (!ea) topa = 1;
	else topa = a[pos];
	if (!eb) topb = 1;
	else topb = b[pos];
	long long rul = 0;
	for (int i = 0; i <= topa; ++i)
		for (int j = 0; j <= topb; ++j) {
			int k = i & j;
			if (ec && k > c[pos]) continue;
			bool nextea, nexteb, nextec;
			if (!ea) nextea = ea;
			else nextea = (i == a[pos]);
			if (!eb) nexteb = eb;
			else nexteb = (j == b[pos]);
			if (!ec) nextec = ec;
			else nextec = (k == c[pos]);
			rul += cal(nextea, nexteb, nextec, pos - 1);
		}
	//cout << pos << '\t' << ea << '\t' << eb << '\t' << ec << '\t' << rul << endl;
	all[ea][eb][ec][pos] = rul;
	return rul;
}

int main() {
	int T;
	cin >> T;
	for (int test = 1; test <= T; ++test) {
		int A, B, C;
		cin >> A >> B >> C;
		--A; --B; --C;
		for (int i = 0; i < L; ++i) {
			a[i] = A % 2;
			b[i] = B % 2;
			c[i] = C % 2;
			A /= 2;
			B /= 2;
			C /= 2;
		}
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j)
				for (int k = 0; k < 2; ++k)
					for (int t = 0; t < L; ++t) flag[i][j][k][t] = false;
		long long ans = cal(true, true, true, L - 1);
		cout << "Case #" << test << ": " << ans << endl;
	}
	return 0;
}