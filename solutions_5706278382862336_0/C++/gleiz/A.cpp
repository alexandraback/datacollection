#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

long long gcd(long long p, long long q) {
	if (p % q == 0) {
		return q;
	} else {
		return gcd(q, p % q);
	}
}

bool testAvailable(long long p) {
	while (p > 1) {
		if (p % 2 == 1) {
			return false;
		}

		p /= 2;
	}
	return true;
}

int main(int argc, char *argv[])
{
    int T = 0;

	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small.out", "w+", stdout);
	cin >> T;
	
	for (int cas = 1; cas <= T; cas++) {
		long long P = 0, Q = 0;
		long long g = 0;
		string buff;

		cin >> buff;

		bool past = false;

		for (int i = 0; i < buff.size(); i++) {
			if (buff[i] == '/') {
				past = true;
			} else if (past == false) {
				P = P * 10 + buff[i] - '0';
			} else {
				Q = Q * 10 + buff[i] - '0';
			}
		}

		g = gcd(P, Q);
		P /= g;
		Q /= g;

		if (!testAvailable(Q)) {
			cout << "Case #" << cas << ": impossible" << endl;	
		} else {
			int res = 0;
			while (P < Q) {
				P *= 2;
				res++;
			}
			cout << "Case #" << cas << ": " << res << endl;	
		}
		
	}
    return 0;
}
