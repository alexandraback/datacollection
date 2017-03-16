#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <queue>
#include <fstream>
using namespace std;

/* --------------------------------- */
 
#define ios ios_base::sync_with_stdio(false)

template<class T> T stoi(string str) {
	T ret = 0;
	for (int i = 0; i < str.size(); i++) ret = ret * 10 + str[i] - '0';
	return ret;
}

bool updateType1(int now, int &ans) {
	if (ans == -1 || ans > now) {
		ans = now;
		return true;
	}
	return false;
}

bool updateType2(int now, int &ans) {
	if (ans == -1 || ans < now) {
		ans = now;
		return true;
	}
	return false;
}

vector<long long> primesUnder(unsigned long long limit) {
	vector<long long> ret;
	vector<bool> u(limit + 1, false);
	for (long long j = 2; j <= limit; j++) if (!u[j]) {
		ret.push_back(j);
		if (j <= limit / j) {
			for (int k = j * j; k <= limit; k += j) u[k] = true;
		}
	}
	return ret;
}

class Edge {
public:
	int from, to;
	Edge *next;
	Edge(int from_, int to_, Edge *next_):from(from_), to(to_), next(next_) {} 
};

/* --------------------------------- */

int testCase = 0;

int main() {
	ios;
	
	ofstream ouf;
	ouf.open("C.small");
	const int MAXL = 16;
	
	vector<long long> prime = primesUnder(10000);
	cout << prime.size() << endl;
	vector<vector<int> > primel(prime.size(), vector<int>(11));
	for (int i = 0; i < prime.size(); i++) {
		for (int j = 2; j <= 10; j++) {
			int s = 0, t = 0;
			for (int k = prime[i]; k; k /= j) {
				s += (k % j > 0) << t;
				t ++;
			}
			primel[i][j] = s;
		}
	}
	
	int regen = false;
	
	vector<int> count(MAXL + 1, 0);
	for (long long i = 1; i < (1LL << MAXL); i++) if (i & 1) {
		int h = 0;
		for (long long j = i; j; j = j >> 1, h ++);
		if (h != 16) continue;
		if (count[h] == 50) continue;
		cout << h << endl;
		
		//cout << i << ' ' << h << ' ' << count[h] << endl;
		
		bool bo = true;
		vector<int> sol(11, 0);
		for (long long p = 2; p <= 10; p++) {
			bool bc = false;
			for (int j = 0; j < prime.size(); j++) {
				if (i <= primel[j][p]) break;
				long long s = 0, t = 1;
				for (long long l = 0; l < h; l++) {
					s = (s + ((i >> l) & 1) * t) % prime[j];
					t = (t * p) % prime[j];
				}
				if (s == 0) {
					bc = true;
					sol[p] = prime[j];
					break;
				}
			}
			if (!bc) {
				bo = false;
				break;
			}
		}
		if (bo) {
			for (int j = h - 1; j >= 0; j --) ouf << ((i >> j) & 1);
			for (int j = 2; j <= 10; j++) ouf << ' ' << sol[j];
			ouf << endl;
			count[h] ++;
		}
	}
	//for (int i = 1; i <= MAXL; i++) ouf << i << ' ' << count[i] << endl;
	

	return 0;
}
