#include "stdafx.h"
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <fstream>
#include <iostream>
using namespace std;

#define INF 300000000
#define LLINF 10000000000000LL
#define MOD 1000000000LL
#define cout cout
#define cin cin
typedef long long ll;

int Q, N, M, K, L;

int main() {
	ifstream in("A-large.in");
	ofstream out("out.txt");
	cin.rdbuf(in.rdbuf());
	cout.rdbuf(out.rdbuf());

	cin >> Q;
	for (int qq = 0; qq < Q; qq++) {
		string s;
		string r;
		cin >> s;
		for (int i = 0; i < s.size(); i++) {
			if (r.size() == 0) r += s[i];
			else {
				if (r[0] <= s[i])
					r = s[i] + r;
				else
					r += s[i];
			}
		}
		cout << "Case #" << qq + 1 << ": " << r << "\n";
	}

	return 0;
}