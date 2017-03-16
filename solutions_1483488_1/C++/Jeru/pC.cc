#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int M = 2 * 1000 * 1000;

int next[M + 1], prev[M + 1];

void Init() {
	fill(next, next + M + 1, -1);
	int base = 10, len = 2;
	for (int n = 10; n <= M; ++n) {
		if (base * 10 <= n) {
			base *= 10;
			++len;
		}
		int m = n, &best = next[n];
		for (int i = 0; i < len; ++i) {
			m = m % 10 * base + m / 10;
			if (m > n && (best == -1 || m < best))
				best = m;
		}
	}
	fill(prev, prev + M + 1, -1);
	for (int n = 0; n <= M; ++n)
		if (next[n] != -1 && next[n] <= M)
			prev[next[n]] = n;
}

void Solve(istream& in, ostream& out) {
	int A, B;
	in >> A >> B;
	long long ans = 0;
	for (int i = A; i <= B; ++i)
		if (prev[i] == -1 || prev[i] < A) {
			int c = 1, j = i;
			for (; next[j] != -1 && next[j] <= B; ++c, j = next[j]);
			ans += c * (c - 1) / 2;
		}
	out << ans << endl;
}

void Main2(istream& in, ostream& out) {
	Init();
	int testNo;
	in >> testNo;
	string line;
	getline(in, line);
	for (int caseId = 1; caseId <= testNo; ++caseId) {
		out << "Case #" << caseId << ": ";
		Solve(in, out);
	}
}

int main(int argc, char* argv[]) {
	if (argc == 1) {
		cin.sync_with_stdio(false);
		cout.sync_with_stdio(false);
		Main2(cin, cout);
	} else {
		string s(argv[1]);
		if (s.size() >= 1 && s[s.size() - 1] == '.')
			s.erase(s.end() - 1);
		else if (s.size() >= 3 and s.substr(s.size() - 3) == ".in")
			s.erase(s.end() - 3, s.end());
		ifstream fin((s + ".in").c_str());
		ofstream fout((s + ".out").c_str());
		Main2(fin, fout);
	}
	return 0;
}
